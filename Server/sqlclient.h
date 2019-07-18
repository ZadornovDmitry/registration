#ifndef SQLCLIENT_H
#define SQLCLIENT_H

#include <QObject>
#include <QScopedPointer>
#include <QSharedDataPointer>

#include <QSqlDatabase>
#include "connection_parameters.h"


class SqlClient : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(SqlClient)
public:
    explicit SqlClient(QObject *parent = nullptr);
    ~SqlClient() = default;
    SqlClient(SqlClient &&other){qSwap(sqlDb_, other.sqlDb_);}
    SqlClient &operator=(SqlClient &&other) Q_DECL_NOTHROW {qSwap(sqlDb_, other.sqlDb_); return  *this;}

    void execQueryes(QMap<QString, QByteArray> &&) Q_DECL_NOTHROW;
    void init(const QString &connectionName);
private:
    Q_REQUIRED_RESULT bool sameParameters(const ConnectionParameters & ) Q_DECL_NOTHROW;

public slots:
    void onConnectionParametersChanged(const ConnectionParameters &) Q_DECL_NOTHROW;
signals:

private:
    QScopedPointer<QSqlDatabase> sqlDb_;
};

#endif // SQLCLIENT_H
