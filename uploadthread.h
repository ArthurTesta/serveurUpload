#ifndef UPLOADTHREAD_H
#define UPLOADTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QFile>
#include "medialist.h"
/*
  ARTHUR 27/11 : Thread servant à l'envois de flux
 */

class UploadThread : public QThread
{
    Q_OBJECT
public:
    /*
      ARTHUR 27/11 :
      socketDescriptor Permet de crée un QTcpSocket pour chaque client
      pathFile Permet de savoir à quel endroit sur le serveur les videos doivent se trouver
      parent ...
     */
    UploadThread(int socketDescriptor, QString pathFile, QObject * parent);
    /*
      ARTHUR 27/11 :
      Bloquant tant qu'il ne faut pas envoyer
     */
void run();
signals:
/*
      ARTHUR 27/11 : Si la création du socket foire
     */
void error(QTcpSocket::SocketError socketError);
    
private:
/*
      ARTHUR 27/11 :
      socketDescriptor Permet de crée un QTcpSocket pour chaque client
      clientConnection Le QTcpSocket crée à partir de socketDescriptor
      pathFile Permet de savoir à quel endroit sur le serveur les videos doivent se trouver
     */
int socketDescriptor;
QTcpSocket * clientConnection;
QString pathFile;
QString fileName;
/*
  ARTHUR 27/11 : Permets de ne pas allez faire de select chaque fois qu'on doit envoyer un film
 */
MediaList * bdContent;
private slots:
/*
      ARTHUR 27/11 : Déclancher quand run est débloqué
     */
void sendData();
void readData();
};

#endif // UPLOADTHREAD_H
