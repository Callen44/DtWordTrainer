#include "DtWordTrainer.h"
#include <QtWidgets/QApplication>

#include "Verb.h"

int main(int argc, char *argv[])
{
    Verb verb(
        "Haben",
        "To Have",
        "Habe",
        "Hast",
        "Hat",
        "Haben",
        "habt",
        "haben"
        );


    QApplication app(argc, argv);
    DtWordTrainer window;
    window.show();
    return app.exec();
}
