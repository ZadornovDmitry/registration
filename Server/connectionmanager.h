#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H

#include "connection_parameters.h"

#include <QObject>
#include <QTimer>

class ConnectionManager : public QObject
{
    Q_OBJECT

public:
    explicit ConnectionManager(QObject *parent = nullptr);
    ~ConnectionManager(){}
private slots:
    void sendParameters() Q_DECL_NOTHROW;
private:
    QTimer timer_;

signals:
    void databaseConnectionChanged(const ConnectionParameters &);
    void tcpConnectionChanged(const ConnectionParameters &);

public slots:
};

#endif // CONNECTIONMANAGER_H
