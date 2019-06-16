#include "connectionmanager.h"

ConnectionManager::ConnectionManager(QObject *parent) : QObject(parent)
{
    connect(&timer_, &QTimer::timeout, this, &ConnectionManager::sendParameters);
    timer_.start(1000);
}

void ConnectionManager::sendParameters() Q_DECL_NOTHROW
{
    ConnectionParameters cp_tcp;
    cp_tcp.port = 5000;
    cp_tcp.address = QHostAddress::LocalHost;
    emit tcpConnectionChanged(cp_tcp);

    ConnectionParameters cp_base;
    cp_base.port = 3050;
    cp_base.user = "SYSDBA";
    cp_base.password = "masterkey";
    cp_base.databaseName = "/home/floyd/1.fdb";
    cp_base.address = QHostAddress("127.0.0.1");
    emit databaseConnectionChanged(cp_base);
}
