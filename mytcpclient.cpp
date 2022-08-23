#include "mytcpclient.h"

MyTcpClient::MyTcpClient(QObject *parent) : QObject(parent)
{

}

void MyTcpClient::doConnect(){
    socket = new QTcpSocket(this);

    connect(socket,SIGNAL(errorOccurred(QAbstractSocket::SocketError)),this,SLOT(socketError(QAbstractSocket::SocketError)));


    socket->connectToHost("127.0.0.7", 9999);
    if(socket->waitForConnected(5000)){
        qDebug()<<"Connected!";

        //send
        socket->write("Hello Server! \r\n");
        socket->waitForBytesWritten(1000);
        socket->waitForReadyRead(3000);

        qDebug()<< "Reading: " <<socket->bytesAvailable();

        //get the data
        TextMessage message;
        message.ParseFromString(socket->readAll().toStdString());
        qDebug()<< message.name().c_str();


        //close
//        socket->disconnectFromHost();
    }else{
        qDebug()<< "Not Connected!";
    }
}

void MyTcpClient::socketError(QAbstractSocket::SocketError error){
    qDebug()<< error;
}
