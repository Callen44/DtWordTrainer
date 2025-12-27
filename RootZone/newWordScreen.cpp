#include "newWordScreen.h"

newWordScreen::newWordScreen(WordSet* words, QWidget *parent)
    : words(words), QWidget(parent)
{
    // create the widgets
    wortBox = new QLineEdit(this);

    definitionBox = new QLineEdit(this);

    wortartBox = new QComboBox(this);
    wortartBox->addItems({"Verb", "Substantiv"});
    QObject::connect(wortartBox, &QComboBox::currentTextChanged, this, &newWordScreen::posChosen);

    submitBtn = new QPushButton("Einzufügen", this);
    QObject::connect(submitBtn, &QPushButton::pressed, this, &newWordScreen::addWord);

    // Add the form layout widget
    formLayout = new QFormLayout(this);
    formLayout->addRow(tr("&Deutsches Wort:"), wortBox);
    formLayout->addRow(tr("&Englische Definition:"), definitionBox);
    formLayout->addRow(tr("&Wortart:"), wortartBox);
    formLayout->addRow(tr(""), submitBtn);

    setLayout(formLayout);
}

void newWordScreen::posChosen(QString newItem) {
    if (newItem == "Substantiv") {
        genderBox = new QComboBox(this);
        genderBox->addItems({"Der", "Die", "Das"});
        genderBox->setObjectName("genderBox");
        formLayout->insertRow(3, tr("&Genus:"), genderBox);
    }
}

void newWordScreen::addWord() {
    if (wortartBox->currentText() == "Substantiv") {
        Gender wordGender = DER; // set a fallback gender
        if (genderBox->currentText() == "Der")
            wordGender = DER;
        else if (genderBox->currentText() == "Die")
            wordGender = DIE;
        else if (genderBox->currentText() == "Das")
            wordGender = DAS;

        Noun newNoun(wortBox->text(), wordGender, definitionBox->text());
        words->addWord(newNoun);
    }

    emit done();
}

newWordScreen::~newWordScreen()
{

}
