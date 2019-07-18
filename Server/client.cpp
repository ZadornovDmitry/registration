#include "client.h"

Client::Client(QTcpSocket *socket, QSharedPointer<ConnectionManager> connectionManager, QObject *parent) : QObject(parent),
  tcpSocket_(socket),
  sqlClient_(new SqlClient(this)),
  connectionManager_(connectionManager)
{
    sqlClient_->init(QString("Client_%1").arg(descriptor()));
    connect(tcpSocket_.data(), &QTcpSocket::readyRead, this, &Client::onReadyRead);
    connect(tcpSocket_.data(), &QTcpSocket::disconnected, this, &Client::disconnected);
    connect(connectionManager_.data(), &ConnectionManager::databaseConnectionChanged, sqlClient_, &SqlClient::onConnectionParametersChanged, Qt::QueuedConnection);
}

Client::~Client()
{
    qDebug() << "dead";
}

qintptr Client::descriptor()
{
    return tcpSocket_->socketDescriptor();
}

void Client::onReadyRead()
{
    qDebug() << tcpSocket_->readAll();
}
