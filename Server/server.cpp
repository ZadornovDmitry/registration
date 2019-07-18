#include "server.h"
#include "client.h"
#include <QDebug>
#include <QThread>


Server::Server(QObject *parent) : QObject (parent),
    connectionManager_(new ConnectionManager),
    tcpServer_(new QTcpServer)
{
    connect(connectionManager_.data(), &ConnectionManager::tcpConnectionChanged, this, &Server::onTcpConnectionParams);
}

void Server::onTcpConnectionParams(const ConnectionParameters &params)
{
    if (sameParameters(params))
        return;

    tcpServer_.reset(new QTcpServer(this));
    connect(tcpServer_.data(), &QTcpServer::newConnection, this, &Server::onNewConnection);

    if (!tcpServer_->listen(params.address, params.port) && !serverRunnig_) {
        qDebug() <<  QObject::tr("Unable to start the server: %1.").arg(tcpServer_->errorString());
    } else {
        serverRunnig_ = true;
        qDebug() << QString::fromUtf8("Сервер запущен!");
    }
    qDebug() << tcpServer_->serverAddress();
}

void Server::onNewConnection()
{
    qDebug() << "new connection";
    auto *client = new Client(tcpServer_->nextPendingConnection(), connectionManager_);
    clients_[client->descriptor()] = client;
    auto *thread = new QThread(this);
    client->moveToThread(thread);
    connect(client, &Client::disconnected, thread, &QThread::quit);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);
    connect(thread, &QThread::finished, client, &Client::deleteLater);
    thread->start();
}

bool Server::sameParameters(const ConnectionParameters &params) Q_DECL_NOTHROW
{
    return tcpServer_->serverAddress() == params.address &&
            tcpServer_->serverPort() == params.port;
}

