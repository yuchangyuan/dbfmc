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
    else if ("skip" == args[1]) {
        c->skip();
    }
    else if ("rate" == args[1]) {
        int like = -1;
        if (args.size() > 2) {
            if ("true" == args[2]) like = 1;
            else if ("false" == args[2]) like = 0;
            else {
                cerr << "should only rate 'true' of 'false'" << endl;
                return EXIT_FAILURE;
            }
        }
        c->rate(like);
    }
    else if ("trash" == args[1]) {
        c->trash();
    }
    else if ("switch" == args[1]) {
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
    else if ("monitor" == args[1]) {
        c->monitor();
    }
    else if ("play" == args[1]) {
        c->play();
    }
    else if ("pause" == args[1]) {
        c->pause();
    }
    else {
        cerr << "command error" << endl;
        return EXIT_FAILURE;
    }

    return a.exec();
}
