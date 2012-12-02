#include "serveurtcp.h"
#include "receivethread.h"
#include <algorithm>

ServeurTcp::ServeurTcp()
{
    qDebug() << "[SERV] - INITIALISATION";
    // On récupère toutes les interfaces réseaux
    ipAddressesList = QNetworkInterface::allAddresses();
}

/*
  ARTHUR 27/11 : Ajout afin de garder les fonctionnalités imaginées par Arnaud
 */
void ServeurTcp::setPath(QString path){
    pathFile=path;
}



/*

  ARTHUR 27/11 : Remplacer par incomingConnection pour les threads



void ServeurTcp::listenPerso(QHostAddress add, int port, QString pf){
    pathFile = pf;
    qDebug() << "[SERV] - PATH " << pf;
    if(add == QHostAddress::Null)
    {
        qDebug() << "[SERV] - LISTEN DEFAULT";
        listen(QHostAddress::Any,port);
    }else{
        qDebug() << "[SERV] - LISTEN CONFIG PERSO - " << add.toString() << " Port : " << port;
        listen(add,port);
    }
    // Si on reçoit une nouvelle connexion, on declenche le slot suivant
   // QObject::connect(this,SIGNAL(newConnection()),this, SLOT(connexion()));
}
*/


QList<QHostAddress> ServeurTcp::getAddressList(){
    return ipAddressesList;
}


/*

  ARTHUR 27/11 : Remplacer par incomingConnection


void ServeurTcp::connexion(){
    qDebug() << "[SERV] - ATTENTE DE CONNEXION";
    clientConnection = nextPendingConnection();
    qDebug() << "[SERV] - CONNEXION OK";
    // Si il y a quelque chose à lire sur le socket, on déclenche le slot suivant
    QObject::connect(clientConnection,SIGNAL(readyRead()), this,SLOT(lire_data()));

}
*/



ServeurTcp::~ServeurTcp()
{
    close();
}


/*
  ARTHUR 27/11 : Lorsqu'une connection d'un client arrive on crée un nouveau thread en lui passant un socketDescriptor unique pour qu'il puisse géré les flux
 */
void ServeurTcp::incomingConnection(int socketDescriptor)
{
    try{
    qDebug() << "[SERV] - CONNEXION OK";
    ReceiveThread * thread = new ReceiveThread(socketDescriptor, pathFile, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
    }
    catch(...){
        qDebug() << "[SERV] - ERROR IN THREAD";
    }
}

