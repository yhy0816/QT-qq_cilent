#include "cilent.h"

Cilent::Cilent(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);
    socket->connectToHost(IP, PORT);
    connect(socket, &QTcpSocket::connected, [](){
        qDebug() << "连接成功";
    });
    connect(socket, &QTcpSocket::readyRead, this, &Cilent::getMsg);
}


void Cilent::sendMsg(QString Msg){
    QByteArray bMsg;
    bMsg.append(Msg);
    //qDebug() << Msg;
    socket->write(bMsg);
}

Cilent::~Cilent()
{
    delete socket;
}


void Cilent::getMsg(){
    qint8 flag;
    QByteArray data = socket->readAll();
    QDataStream dataStream(&data, QIODevice::ReadOnly);
    dataStream >> flag;
    //qDebug() << flag;
    if(flag == 0)
    {
        QString msg;
        dataStream >> msg;
        //qDebug() << msg;
        emit getMsgSignal(msg);
    }
    if(flag == 1)
    {
        QStringList cilentList;
        dataStream >> cilentList;
        emit getListSignal(cilentList);
    }

}


