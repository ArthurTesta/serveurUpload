#include "uploadthread.h"

UploadThread::UploadThread(int socketDescriptor, QString pathFile, QObject * parent) : socketDescriptor(socketDescriptor),pathFile(pathFile), QThread(parent){
    bdContent = new MediaList();
    clientConnection = new QTcpSocket();
    if (!clientConnection->setSocketDescriptor(socketDescriptor)) {
        emit error(clientConnection->error());
        return;
    }
    connect(clientConnection,SIGNAL(readyRead()),this,SLOT(readData()));
}

void UploadThread::run(){
    qDebug() << "[SERV] Waiting for signal readyRead()" ;
    /*
      ARTHUR 27/11 :
      Bloque tant qu'il n'y a rien à lire
     */
    clientConnection->waitForReadyRead(-1);
}

void UploadThread::readData(){
    qDebug() << "[SERV] - READ";
    int sizeName=0;
    char * tmp = new char[40];
    clientConnection->read(((char*)&sizeName),4);
    int cpt = clientConnection->read(tmp,sizeName);
    pathFile += "/";
    for (int cpt=0;cpt<sizeName-1;cpt++){
        fileName += tmp[cpt];
    }
    qDebug() << "[SERV] - File" << pathFile+fileName;
    sendData();
}

void UploadThread::sendData(){
    qDebug() << "[CLI] - NETWORK SUCCESS";
    QList < Media > list = bdContent->getMediaList();
    int cpt=0;
    bool found=false;
    while (cpt<list.size()){
        if(list.at(cpt).getTitle()==fileName){
            found=true;
            break;
        }
        cpt++;
    }
    if (found){
        qDebug() << "[SERV] - File FOUND" << pathFile+fileName;
        QFile * myFile = new QFile(pathFile+fileName);
        int myFileSize = myFile->size();
        qDebug() << "[SERV] - TOTAL SIZE TO SENT " << myFile->size() + sizeof(int);
        qDebug() << "[SERV] - SIZE OF FILE " << myFile->size();
        myFile->open(QIODevice::ReadOnly);
        clientConnection->write((const char*) &myFileSize,sizeof(int));
        clientConnection->setReadBufferSize(myFileSize);
        clientConnection->write(myFile->readAll());
        clientConnection->flush();
    }else{
        qDebug() << "[SERV] - FILE NOT FOUND";
        clientConnection->close();
    }
}

