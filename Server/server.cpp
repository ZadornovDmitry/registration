#include "server.h"

Server::Server(QObject *parent) : QObject (parent),
    connectionManager_(new ConnectionManager),
    tcpServer_(new TcpServer),
    sqlServer_(new SqlServer)
{
    connect(connectionManager_.data(), &ConnectionManager::databaseConnectionChanged, sqlServer_.data(), &SqlServer::onConnectionParametersChanged);
}

