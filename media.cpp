#include <QString>
#include "media.h"
/*
  ARTHUR 27/11 : Création sur base du travail de Paul
 */
Media::Media(const int id,const QString title, const QString synopsis, const int date) {
    this->id=id;
    this->title = new QString(title);
    this->synopsis = new QString(synopsis);
    this->date = date;
}

int Media::getDate() const {
    return this->date;
}

QString Media::getSynopsis() const {
    return *(this->synopsis);
}

QString Media::getTitle() const {
    return *(this->title);
}
int Media::getId() const{
    return this->id;
}
