
/*
 * ServerException.h
 *
 *  Created on: 01-oct.-2011
 *      Author: Proprietaire
 */
#ifndef SERVEUREXCEPTION_H
#define SERVEUREXCEPTION_H
#include <stdexcept>
#include <string>

class ServerException
{
    std::string msg;
public:
    /*!
     * \brief Constructeur.
     *
     * \param msg Le message dont on veut affubler l'exception.
     */
    inline ServerException(const std::string & msg) : msg(msg){}
    inline std::string what(){return msg;}
};

#endif // SERVEUREXCEPTION_H
