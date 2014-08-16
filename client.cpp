#include "client.h"
#include <QCoreApplication>
#include <QTextStream>

using namespace nzmqt;

const char* Client::SUB_ADDR = "tcp://localhost:12677";
const char* Client::REQ_ADDR = "tcp://localhost:12678";

Client::Client(QObject *parent) :
    QObject(parent), context_(createDefaultContext(parent))
{
    sock_req_ = context_->createSocket(ZMQSocket::TYP_REQ, this);
    sock_sub_ = context_->createSocket(ZMQSocket::TYP_SUB, this);

    sock_sub_->subscribeTo("");

    sock_req_->connectTo(REQ_ADDR);
    connect(sock_req_, SIGNAL(messageReceived(QList<QByteArray>)),
            SLOT(reply(QList<QByteArray>)));

    context_->start();
}

void Client::skip()
{
    request("skip");
}

void Client::rate(int like)
{
    request("rate", like);
}

void Client::trash()
{
    request("trash");
}

void Client::info()
{
    request("info");
}

void Client::switchChannel(int ch_id)
{
    request("switch", ch_id);
}

void Client::play()
{
    request("play");
}

void Client::pause()
{
    request("pause");
}

void Client::request(QString req, int arg1)
{
    QList<QByteArray> msg;

    msg << req.toUtf8();

    if (req == "switch") {
        QString ch_id_str;
        QTextStream(&ch_id_str) << arg1;
        msg << ch_id_str.toUtf8();
    }
    else if (req == "rate") {
        if (arg1 == 0) msg << QString("false").toUtf8();
        if (arg1 == 1) msg << QString("true").toUtf8();
    }

    sock_req_->sendMessage(msg);
}

void Client::monitor()
{
    sock_sub_->connectTo(SUB_ADDR);
    connect(sock_sub_, SIGNAL(messageReceived(QList<QByteArray>)),
            SLOT(received(QList<QByteArray>)));
}

void Client::reply(QList<QByteArray> reply)
{
    QTextStream cout(stdout);
    for (int i = 0; i < reply.size(); ++i) {
        cout << reply[i] << endl;
    }

    QCoreApplication::exit(EXIT_SUCCESS);
}

void Client::received(QList<QByteArray> recv)
{
    QTextStream cout(stdout);
    cout << QString(recv[0]) << " --> ";
    for (int i = 1; i < recv.size(); ++i) {
        cout << QString(recv[i]) << endl;
    }
}
