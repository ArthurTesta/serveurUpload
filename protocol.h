#ifndef PROTOCOL_H
#define PROTOCOL_Hs
#include "receivethread.h"

QString & getQStringFromSock(ReceiveThread * t);
void readChar(char * dest, int length,ReceiveThread * t);
void readInt(int * dest, ReceiveThread * t);
QString & convertCharStoQString(char * source);
QByteArray & getDataFromSock(ReceiveThread * t) throw (ServerException);
void writeInt(int * source, ReceiveThread * t);
void writeQString(QString & source,ReceiveThread * t);

#endif // PROTOCOL_H
