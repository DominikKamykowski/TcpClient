#ifndef MYTCPCLIENT_H
#define MYTCPCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include "TextMessage.pb.h"

class MyTcpClient : public QObject
{
    Q_OBJECT

public:
    MyTcpClient(QObject *parent = nullptr);

    void doConnect();


signals:


public slots:
    void socketError(QAbstractSocket::SocketError error);

private:
    QTcpSocket *socket;

};

#endif // MYTCPCLIENT_H
