#ifndef CONNECTION_PARAMETERS_H
#define CONNECTION_PARAMETERS_H
#include <QHostAddress>

struct ConnectionParameters
{
    QString user;
    QString password;
    QString databaseName;
    QHostAddress address;
    quint16 port;
};

Q_DECLARE_METATYPE(ConnectionParameters)
#endif // CONNECTION_PARAMETERS_H
