#ifndef CONNECTION_PARAMETERS_H
#define CONNECTION_PARAMETERS_H
#include <QHostAddress>

struct ConnectionParameters
{
    QString user;
    QString password;
    QString databaseName;
    QHostAddress address;
    int port;
};


#endif // CONNECTION_PARAMETERS_H
