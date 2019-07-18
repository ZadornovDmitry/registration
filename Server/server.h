#ifndef SERVER_H
#define SERVER_H


#include "sqlclient.h"
#include "connectionmanager.h"

#include <QTcpServer>
#include <QObject>
#include <QSharedPointer>
#include <QScopedPointer>

class Client;
class Server : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Server)

public:
    explicit Server(QObject *parent = nullptr);
    ~Server(){}
private:
    void onTcpConnectionParams(const ConnectionParameters &);
    void onNewConnection();

    Q_REQUIRED_RESULT bool sameParameters(const ConnectionParameters & ) Q_DECL_NOTHROW;

private:
    QSharedPointer<ConnectionManager> connectionManager_;

    QScopedPointer<QTcpServer>tcpServer_;
    bool serverRunnig_ = false;
    QMap<qintptr, Client*> clients_;

};

#endif // SERVER_H
