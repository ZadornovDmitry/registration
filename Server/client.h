#ifndef CLIENT_H
#define CLIENT_H

#include "connectionmanager.h"
#include "sqlclient.h"

#include <QObject>
#include <QTcpSocket>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QTcpSocket *socket, QSharedPointer<ConnectionManager> connectionManager, QObject *parent = nullptr);
    ~Client();
    qintptr descriptor();
private:
    void onReadyRead();
    void onDisconnect();
signals:
    void disconnected();
private:
    QScopedPointer<QTcpSocket> tcpSocket_;
    SqlClient *sqlClient_;
    QSharedPointer<ConnectionManager> connectionManager_;
};

#endif // CLIENT_H
