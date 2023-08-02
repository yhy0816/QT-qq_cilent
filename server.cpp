#include "server.h"

Server::Server(QWidget *parent):
    QDialog(parent)
{
    setFixedSize(400, 200);
    server = new QTcpServer(this);
    connect(server, &QTcpServer::newConnection, this, &Server::newConnection);
    server->listen(QHostAddress::Any, PORT);
}



void Server::newConnection()
{
    QTcpSocket* nextSocket = server->nextPendingConnection();
    sockets.push_back(nextSocket);
}
