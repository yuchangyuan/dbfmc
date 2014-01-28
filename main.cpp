#include <QCoreApplication>
#include <QTextStream>
#include "client.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QStringList args = a.arguments();
    QTextStream cerr(stderr);

    if (args.size() < 2) {
        cerr << "Not enough argument" << endl;
        return EXIT_FAILURE;
    }

    Client* c = new Client(&a);

    if ("info" == args[1]) {
        c->info();
    }

    if ("skip" == args[1]) {
        c->skip();
    }

    if ("rate" == args[1]) {
        c->rate();
    }

    if ("trash" == args[1]) {
        c->trash();
    }

    if ("switch" == args[1]) {
        if (args.size() < 3) {
            cerr << "Not enough argument, need channel id" << endl;
            return EXIT_FAILURE;
        }

        bool ok;
        int ch_id = args[2].toInt(&ok);
        if (!ok) {
            cerr << "channel id should be integer." << endl;
            return EXIT_FAILURE;
        }

        c->switchChannel(ch_id);
    }

    if ("monitor" == args[1]) {
        c->monitor();
    }

    if ("play" == args[1]) {
        c->play();
    }

    if ("pause" == args[1]) {
        c->pause();
    }

    return a.exec();
}
