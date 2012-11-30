#include "receivethread.h"
#include <QtNetwork>
ReceiveThread::ReceiveThread(int socketDescriptor, QString pathFile, QObject * parent):socketDescriptor(socketDescriptor), pathFile(pathFile), QThread(parent){
    /*
      ARTHUR 27/11 :
      Cree le thread avec le socketDescriptor et le pathfile ou on doit stocker les videos
      Puis crÃ©ation du QTcpSocket grÃ¢ce au socket descriptor
      Bind du readyread avec la fonction lire_data()
     */
    reading=false;
    clientConnection = new QTcpSocket();
    connect(clientConnection,SIGNAL(readyRead()),this,SLOT(lire_data()));
    if (!clientConnection->setSocketDescriptor(socketDescriptor)) {
        emit error(clientConnection->error());
        return;
    }
}

void ReceiveThread::run(){
    qDebug() << "[SERV] Waiting for signal readyRead()" ;
    /*
      ARTHUR 27/11 :
      Bloque tant qu'il n'y a rien Ã  lire
     */
    clientConnection->waitForReadyRead(-1);
    //   pause();
}

void ReceiveThread::lire_data(){
    if(reading)return;
    reading=true;
    qDebug() << "[SERV] - READ";
    int sizeName=0,sizeFile=0,fileBytesWritten=0;
    char * tmp = new char[40];
    QByteArray data;
    /*
      ARTHUR 27/11 :
      Lecture de la longueur en byte du nom de fichier
     */
    clientConnection->read(((char*)&sizeName),4);
    /*
      ARTHUR 27/11 :
      Lecture + crÃ©ation du pathFile indiquant ou sera stockÃ© le fichier
     */
    int cpt = clientConnection->read(tmp,sizeName);
    pathFile += "/";
    for (int cpt=0;cpt<sizeName-1;cpt++){
        pathFile += tmp[cpt];
    }
    qDebug() << "[SERV] - NEW PATHFILE" << pathFile;
    /*
      ARTHUR 27/11 :
      Lecture du nombre de la taille du fichier pour la boucle while
     */
    clientConnection->read((char *)&sizeFile,4);
    qDebug() << "[SERV] - SIZE FILE READ" << sizeFile;
    disconnect(clientConnection,SIGNAL(readyRead()),this,SLOT(lire_data()));
    /*
      ARTHUR 30/11 : En fonction de comment tcp envois ses paquets il est possible que ça bloque ici ...
      Mais ca résoud le problème de double click sur envois dans une majeure partie des cas
     */
    fileBytesWritten+=clientConnection->bytesAvailable();
    data+=clientConnection->read(clientConnection->bytesAvailable());
    while (fileBytesWritten<sizeFile){
        /*
          ARTHUR 27/11 :
          Bloque tant qu'il n'y a rien Ã  lire
         */
        clientConnection->waitForReadyRead(-1);
        /*
          ARTHUR 27/11 :
          Ajoute au QByteArray ce qui est lu
         */
        fileBytesWritten+=clientConnection->bytesAvailable();
        /*
          ARTHUR 27/11 :
          Lit ce qui est disponnible uniquement
         */
        data +=clientConnection->read(clientConnection->bytesAvailable());
        /*
          ARTHUR 27/11 :
          Vide (normalement inutile)
         */
        // clientConnection->flush();

    }

    clientConnection->close();
    /*
      ARTHUR 27/11 :
      Write dans le fichier une fois que tout est récupéré
     */
    QFile * entry = new QFile(pathFile);
    /*
      ARTHUR 30/11 :
      Si le fichier existe déjà pas d'écrasement
     */
    if(!entry->exists()){
        if(entry->open(QIODevice::Append)){
            qDebug() << "[SERV] - WRITE";
            entry->write(data);
        }
        qDebug() << "[SERV] - BYTES WRITTEN" << data.length();
        entry->close();
        qDebug() << "[SERV] - WRITE OK";

        /*
          ARTHUR 30/11 :
          TODO -> Ajout à la BD
         */
    } else{
        qDebug() << "[SERV] - FILE ALREADY EXIST";
        /*
          ARTHUR 30/11 :
          TODO -> gestion d'un message au client
         */
    }
    clientConnection->close();
}


