#include <QDebug>
#include <qt4/QtSql/QtSql>
#include <QString>
#include <QList>
#include "media.h"
#include "medialist.h"
/*
  ARTHUR 27/11 : Création sur base du travail de Paul
 */
MediaList::MediaList() {
    db = new QSqlDatabase();
    mediaList = new QList<Media>();
    if (createConnection()) {
        buildList();
        closeConnection();
    } else {
        qDebug() << "Error !" << endl;
    }
}

bool MediaList::createConnection() {
    qDebug() << "Opening connection..." << endl;
    *(db) = QSqlDatabase::addDatabase("QSQLITE");
    db->setDatabaseName("movies.db");
    db->setHostName("");
    db->setPassword("");
    return db->open();
}

void MediaList::closeConnection() {
    qDebug() << "Closing connection..." << endl;
    db->close();
}

void MediaList::buildList() {
    if (db->isOpen()) {
        QSqlQuery query;
        query.setForwardOnly(true);
        /*
          ARTHUR 27/11 :

          NB : J'ai eu pleins de problèmes parce que les drivers de qt sont pas les bons pour sqlite 3 donc j'ai du faire les création
          à partir d'ici je les ai laissé parce qu'on en aura encore besoin ...
          NB2 : Le path n'est pas dans les champs parce que j'ai imaginé que le path = filePath+fileName maintenant c'est facile à changer

        QSqlQuery create = db->exec("CREATE TABLE media ( id INTEGER PRIMARY KEY, title TEXT, synopsis TEXT, date INTEGER)");
                qDebug() << create.lastError();
        QSqlQuery insert = db->exec("INSERT OR REPLACE INTO media (title,synopsis,date) VALUES('Leon','Great movie',1997)");
                qDebug() << insert.lastError();
        QSqlQuery insert2 = db->exec("INSERT OR REPLACE INTO media (title,synopsis,date) VALUES('Iron Man','Armor man',2008)");
                qDebug() << insert2.lastError();
        QSqlQuery update = db->exec("UPDATE media SET title= 'Independance Day', synopsis='Alien movie', date=1996 WHERE id=4");
                qDebug() << update.lastError();
         */
        query.exec("SELECT * FROM media");
        while (query.next()) {
            int id = query.value(0).toInt();
            QString title = query.value(1).toString();
            QString synopsis = query.value(2).toString();
            int date = query.value(3).toInt();
            Media * media = new Media(id,title, synopsis, date);
            mediaList->push_back((*media));
        }
    }
}

/*
  ARTHUR 30/11 :
  Ajout d'un film à la médialist et à la BD
 */
void MediaList::AddMovie(QString title, QString synopsis, int date){
    QSqlQuery insert = db->exec("INSERT OR REPLACE INTO media (title,synopsis,date) VALUES('"+ title+ "','"+synopsis+"',"+1997+")");
    QSqlError e= insert.lastError();
    if(e!=0){
    qDebug() << "[SERV] - MEDIALIST - ADD TO DB ERROR" << e;
    }
}

QList<Media> MediaList::getMediaList() const {
    return *mediaList;
}

void MediaList::refreshList() {
    if (createConnection()) {
        delete mediaList;
        mediaList = new QList<Media>;
        buildList();
        closeConnection();
    }
}
