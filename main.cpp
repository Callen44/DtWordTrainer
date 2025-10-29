#include "RootZone/DtWordTrainer.h"
#include <QtWidgets/QApplication>
#include <cstdlib>
#include <ctime>

int main(int argc, char *argv[])
{
    // seed random number generation, used for distractors (I like using C libraries if you can't tell, makes me a better programmer in both langauges).
    std::srand(time(0));

    QApplication app(argc, argv);
    DtWordTrainer window;
    window.show();
    return app.exec();
}
