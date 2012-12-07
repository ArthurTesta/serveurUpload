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
    int code=-1;
    try{
        QString stringDate(QString::number(QDate::currentDate().day())+ QString::fromStdString("/") + QString::number(QDate::currentDate().month()) +
                           QString::fromStdString("/")+ QString::number(QDate::currentDate().year()) + QString::fromStdString(" ") +
                           QString::number(QTime::currentTime().hour()) + QString::fromStdString(":") + QString::number(QTime::currentTime().minute()));
        QByteArray data;
        QString & fileName = readQStringSock(clientConnection);
        QString & description = readQStringSock(clientConnection);
        data += readDataSock(clientConnection);
        pathFile+="/"+fileName;
        /*
          TBDINBD

         */
        if(!listMedia.isMovieInDB(fileName)){

            QFile * entry = new QFile(pathFile);
            if(entry->open(QIODevice::Append)){
                entry->write(data);
            }
            entry->close();
            listMedia.AddMovie(fileName,description,stringDate);
            code=0;
            writeIntSock(&code,clientConnection);
            QString resultMsg(QString::fromStdString("Everything ok"));
            writeQStringSock(resultMsg,clientConnection);
        } else{
            throw Exception("File already exists");
        }
    }catch(Exception e){
        QString result = QString::fromStdString(e.what());
        writeIntSock(&code,clientConnection);
        writeQStringSock(result, clientConnection);
        clientConnection->close();
        return;
    }
    clientConnection->close();
}
