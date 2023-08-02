#ifndef SERVER_H
#define SERVER_H
#define PORT 8000

#include <QDialog>
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>

class Server : public QDialog
{
    Q_OBJECT
public:
    Server(QWidget *parent = nullptr);

private slots:
    void newConnection();

private:
    QTcpServer *server;
    QVector<QTcpSocket*> sockets;
//    QTcpSocket *socket;
};

#endif // SERVER_H
