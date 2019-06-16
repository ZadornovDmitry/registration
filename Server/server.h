#ifndef SERVER_H
#define SERVER_H

#include "tcpserver.h"
#include "sqlserver.h"
#include "connectionmanager.h"

#include <QObject>
#include <QSharedPointer>
#include <QScopedPointer>


class Server : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Server)

public:
    explicit Server(QObject *parent = nullptr);
    ~Server(){}

private:
    QSharedPointer<ConnectionManager> connectionManager_;

    QScopedPointer<TcpServer>tcpServer_;
    QScopedPointer<SqlServer> sqlServer_;

};

#endif // SERVER_H
