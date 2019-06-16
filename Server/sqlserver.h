#ifndef SQLSERVER_H
#define SQLSERVER_H

#include <QObject>
#include <QScopedPointer>
#include <QSharedDataPointer>

#include <QSqlDatabase>
#include "connection_parameters.h"


class SqlServer : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(SqlServer)
public:
    explicit SqlServer(QObject *parent = nullptr);
    ~SqlServer() = default;
    SqlServer(SqlServer &&other){qSwap(sqlDb_, other.sqlDb_);}
    SqlServer &operator=(SqlServer &&other) Q_DECL_NOTHROW {qSwap(sqlDb_, other.sqlDb_); return  *this;}

    void execQueryes(QMap<QString, QByteArray> &&) Q_DECL_NOTHROW;
private:
    Q_REQUIRED_RESULT bool sameParameters(const ConnectionParameters & ) Q_DECL_NOTHROW;

public slots:
    void onConnectionParametersChanged(const ConnectionParameters &) Q_DECL_NOTHROW;
signals:

private:
    QScopedPointer<QSqlDatabase> sqlDb_;
};

#endif // SQLSERVER_H
