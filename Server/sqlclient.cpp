#include "sqlclient.h"
#include <QSqlDatabase>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>


SqlClient::SqlClient(QObject *parent) : QObject(parent),
    sqlDb_(new QSqlDatabase)
{

}

void SqlClient::execQueryes(QMap<QString, QByteArray> &&) Q_DECL_NOTHROW
{

}

void SqlClient::init(const QString &connectionName)
{
    *sqlDb_ = QSqlDatabase::addDatabase("QIBASE", connectionName);
    qDebug() << connectionName;
}

bool SqlClient::sameParameters(const ConnectionParameters &params) Q_DECL_NOTHROW
{
    return  sqlDb_->hostName() == params.address.toString() &&
            sqlDb_->databaseName() == params.databaseName &&
            sqlDb_->userName() == params.user &&
            sqlDb_->password() == params.password;
}

void SqlClient::onConnectionParametersChanged(const ConnectionParameters &params) Q_DECL_NOTHROW
{
    qDebug() << "new database params";
    if (sameParameters(params)){
        return;
    }

    if (sqlDb_->isOpen())
        sqlDb_->close();

    sqlDb_->setHostName(params.address.toString());
    sqlDb_->setPort(params.port);
    sqlDb_->setDatabaseName(params.databaseName);
    sqlDb_->setUserName(params.user);
    sqlDb_->setPassword(params.password);
    if (!sqlDb_->open())
        qDebug() << sqlDb_->lastError().text();
    else{
        qDebug() << "connect to database success!";
    }

}
