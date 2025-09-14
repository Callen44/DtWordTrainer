#include "RootZone/DtWordTrainer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    DtWordTrainer window;
    window.show();
    return app.exec();
}
