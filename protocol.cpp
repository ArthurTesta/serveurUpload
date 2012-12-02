#include <protocol.h>

QString & getQStringFromSock(ReceiveThread * t){
    int size;
    t->clientConnection->read((char *)&size,sizeof(int));
    char * destTmp = new char [size-1];
    t->clientConnection->read((char *) destTmp, size);
    return convertCharStoQString(destTmp);
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

void readChar(char * dest, int length, ReceiveThread * t){
    t->clientConnection->read((char *) dest, length);
}
void readInt(int * dest, ReceiveThread * t){
    t->clientConnection->read((char *)dest,sizeof(int));
}

QByteArray & getDataFromSock(ReceiveThread * t) throw (ServerException){
    int size=0;
    QByteArray * data = new QByteArray;
    t->clientConnection->read((char *)&size,sizeof(int));
    while (data->length()<size){
        if(!t->clientConnection->waitForReadyRead(5000)){
            qDebug() << "[SERV] - TIME OUT";
            throw ServerException("Server Time out");
        }
        (*data) +=t->clientConnection->read(t->clientConnection->bytesAvailable());
    }
    return (*data);
}
void writeInt(int * source, ReceiveThread * t){
    t->clientConnection->write(((char *)source),sizeof(int));
}
void writeQString(QString & source, ReceiveThread * t){
    int size = source.length()+1;
    QByteArray ba = source.toLocal8Bit();
    char * tmpStock = ba.data();
    writeInt(&size,t);
    t->clientConnection->write(tmpStock,size);
}
