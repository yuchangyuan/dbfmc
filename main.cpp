#include <QCoreApplication>
// #include <nzmqt/nzmqt.hpp>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QStringList args = a.arguments();
    QTextStream cerr(stderr);

    if (args.size() < 2) {
        cerr << "Not enough argument";
        return EXIT_FAILURE;
    }

    if ("info" == args[1]) {
        //
    }

    if ("skip" == args[1]) {
        //
    }

    if ("rate" == args[1]) {
        //
    }

    if ("trash" == args[1]) {
        //
    }

    if ("switch" == args[1]) {
        if (args.size() < 3) {
            cerr << "Not enough argument, need channel id";
            return EXIT_FAILURE;
        }

        bool ok;
        int ch_id = args[2].toInt(&ok);
        if (!ok) {
            cerr << "channel id should be integer.";
            return EXIT_FAILURE;
        }
    }

    if ("monitor" == args[1]) {
        //
    }

    return a.exec();
}
