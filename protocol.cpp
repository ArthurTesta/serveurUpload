#include "receivethread.h"
#include "protocol.h"
#include "exception.h"

void readCharSock(char * dest, int length, QTcpSocket * t){
     t->read((char *) dest, length);
}

void readIntSock(int * dest, QTcpSocket * t){
    t->read((char *)dest,sizeof(int));
}
QString & convertCharStoQString(char * destTmp){
    QString * dest = new QString;
    int cpt=0;
    while (destTmp[cpt]!=0){
        dest->append(destTmp[cpt]);
        cpt++;
    }
    return (*dest);
}
QString & readQStringSock(QTcpSocket * t){
    int size;
     t->read((char *)&size,sizeof(int));
    char * destTmp = new char [size-1];
     t->read((char *) destTmp, size);
    return convertCharStoQString(destTmp);
}

QByteArray & readDataSock(QTcpSocket * t) throw (Exception){
    int size=0;
    QByteArray * data = new QByteArray;
     t->read((char *)&size,sizeof(int));
    while (data->length()<size){
        if(! t->waitForReadyRead(5000)){
            qDebug() << "[SERV] - TIME OUT";
            throw Exception("Server Time out");
        }
        (*data) += t->read( t->bytesAvailable());
    }
    return (*data);
}

void writeIntSock(int * source, QTcpSocket * t){
     t->write(((char *)source),sizeof(int));
}

void writeQStringSock(QString & source, QTcpSocket * t){
    int size = source.length()+1;
    QByteArray ba = source.toLocal8Bit();
    char * tmpStock = ba.data();
    writeIntSock(&size,t);
     t->write(tmpStock,size);
}
