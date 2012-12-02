#include "receivethread.h"
#include <QtNetwork>
#include "exception.h"

ReceiveThread::ReceiveThread(int socketDescriptor, QString pathFile, QObject * parent):socketDescriptor(socketDescriptor), pathFile(pathFile), QThread(parent),reading(false){
    clientConnection = new QTcpSocket();
    connect(clientConnection,SIGNAL(readyRead()),this,SLOT(lire_data()));
    if (!clientConnection->setSocketDescriptor(socketDescriptor)) {
        emit error(clientConnection->error());
        return;
    }
}

void ReceiveThread::run(){
    qDebug() << "[SERV] Waiting for signal readyRead()" ;
    clientConnection->waitForReadyRead(-1);
}

void ReceiveThread::lire_data(){
    disconnect(clientConnection,SIGNAL(readyRead()),this,SLOT(lire_data()));
    if(reading)return;
    reading=true;
    try{
        qDebug() << "[SERV] - READ";
        QTime * t= new QTime;
        int date = t->currentTime().minute()+t->currentTime().second()+t->currentTime().hour()+t->currentTime().msec();
        QString & fileName = readQStringSock(clientConnection);
        qDebug() << "[SERV] - FileName" << fileName;
        QString & description = readQStringSock(clientConnection);
        qDebug() << "[SERV] - Description" << description;
        QByteArray data;
        try{
            data += readDataSock(clientConnection);
        }
        catch(...){
            qDebug() << "OHOHOH";
        }

        pathFile+="/"+fileName;
        qDebug() << "[SERV] - CHECKING DB";

        /*
          TBDINBD

         */
        if(!listMedia.isMovieInDB(fileName)){
            QFile * entry = new QFile(pathFile);
            if(entry->open(QIODevice::Append)){
                qDebug() << "[SERV] - WRITE";
                entry->write(data);
            }
            entry->close();
            qDebug() << "[SERV] - BYTES WRITTEN" << data.length();
            listMedia.AddMovie(fileName,description,date);
            QString result = "Everything ok";
            writeQStringSock(result,clientConnection);
            clientConnection->close();
            return;
        } else{
            qDebug() << "[SERV] - FILE ALREADY EXIST";
            throw Exception("File already exists");
        }
    }catch(Exception e){
        QString result = QString::fromStdString(e.what());
        writeQStringSock(result, clientConnection);
        clientConnection->close();
        return;
    }
    clientConnection->close();
}
