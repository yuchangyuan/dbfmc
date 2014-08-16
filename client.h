#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <nzmqt/nzmqt.hpp>

class Client : public QObject
{
    Q_OBJECT

    nzmqt::ZMQContext *context_;
    nzmqt::ZMQSocket *sock_sub_;
    nzmqt::ZMQSocket *sock_req_;

    static const char* SUB_ADDR;
    static const char* REQ_ADDR;

    void request(QString req, int arg1 = -1);

public:
    explicit Client(QObject *parent = 0);

    void skip();
    // 1->like, 0->unlike, otherwise toggle
    void rate(int like);
    void trash();
    void info();
    void switchChannel(int ch_id);
    void play();
    void pause();

    void monitor();
signals:

public slots:

private slots:
    void reply(QList<QByteArray> reply);
    void received(QList<QByteArray> recv);

};

#endif // CLIENT_H
