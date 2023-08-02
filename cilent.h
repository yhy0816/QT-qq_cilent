#ifndef CILENT_H
#define CILENT_H
#define IP "127.0.0.1"
#define PORT 8000

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QDataStream>


class Cilent : public QObject
{
    Q_OBJECT
public:
    explicit Cilent(QObject *parent = nullptr);
    ~Cilent();
    void sendMsg(QString Msg);

signals:
    void getMsgSignal(QString msg);
    void getListSignal(QStringList list);

private slots:
    void getMsg();

private:
    QTcpSocket* socket;
};

#endif // CILENT_H
