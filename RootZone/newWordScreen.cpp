#include "newWordScreen.h"

newWordScreen::newWordScreen(WordSet* words, QWidget *parent)
    : words(words), QWidget(parent)
{
    // create the widgets
    wortBox = new QLineEdit(this);

    definitionBox = new QLineEdit(this);

/*
* Combo Boxes, this code simply doesn't work right on android because of a Qt bug, but the alternative, radio buttons, doesn't really feel like the right option either.
* So, on android we use radio butons because we have to, and on other platforms we don't.
* This first block creates either the QComboBox wortartBox, or the radio buttons.
*/
#ifndef __ANDROID__
    // for all platforms other than android, combo boxes should work fine
    wortartBox = new QComboBox(this);
    wortartBox->addItems({"Verb", "Substantiv"});
    QObject::connect(wortartBox, &QComboBox::currentTextChanged, this, &newWordScreen::posChosen);
#else
    // please please please! fix this bug Qt (combo boxes crash due to android accessability rules
    // add radio buttons
    subButton = new QRadioButton("Substantiv", this);
    subButton->setAutoExclusive(true);
    QObject::connect(subButton, &QRadioButton::pressed, this, &newWordScreen::subChosen);

    verbButton = new QRadioButton("Verb", this);
    verbButton->setAutoExclusive(true);
    verbButton->setChecked(true);
    subSelectedNow = false;
    QObject::connect(verbButton, &QRadioButton::pressed, this, &newWordScreen::verbChosen);

    // hide noun specific radio buttons, but don't let them be garbage data either, and add them to their button group
    genderBox = new QButtonGroup(this);

    derButton = new QRadioButton("Der", this);
    derButton->hide();
    genderBox->addButton(derButton);
    derButton->setChecked(true);

    dieButton = new QRadioButton("Die", this);
    dieButton->hide();
    genderBox->addButton(dieButton);

    dasButton = new QRadioButton("Das", this);
    dasButton->hide();
    genderBox->addButton(dasButton);
#endif

    submitBtn = new QPushButton("Einzufügen", this);
    QObject::connect(submitBtn, &QPushButton::pressed, this, &newWordScreen::addWord);

    // Add the form layout widget
    formLayout = new QFormLayout(this);
    formLayout->addRow(tr("&Deutsches Wort:"), wortBox);
    formLayout->addRow(tr("&Englische Definition:"), definitionBox);

/*
 * This next section adds either the combo box or the radio buttons to the layout QFormLayout
*/
#ifndef __ANDROID__
    formLayout->addRow(tr("&Wortart:"), wortartBox);
#else
    formLayout->addRow(tr(""), subButton);
    formLayout->addRow(tr(""), verbButton);

    // add noun specific buttons, will be hidden until subChosen is called
    formLayout->addRow(tr(""), derButton);
    formLayout->addRow(tr(""), dieButton);
    formLayout->addRow(tr(""), dasButton);
#endif

    // back to the rest, adding the submit button and completing our layout
    formLayout->addRow(tr(""), submitBtn);
    setLayout(formLayout);
}

// Since combo boxes are so different from radio buttons, we have entirely different functions and slots to capture and process the information
#ifndef __ANDROID__
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
    } else if (wortartBox->currentText() == "Verb") {
        Verb newVerb(wortBox->text(), definitionBox->text());
        words->addWord(newVerb);
    }

    emit done();
}

#else

// android specific functions and slots
void newWordScreen::subChosen() {
    // show all noun specific buttons
    derButton->show();
    dieButton->show();
    dasButton->show();
    subSelectedNow = true; // mark substantiv as selected
}

void newWordScreen::verbChosen() {
    // hide all noun specific buttons
    derButton->hide();
    dieButton->hide();
    dasButton->hide();
    subSelectedNow = false; // mark verb as selected
}

void newWordScreen::addWord() {
    // first, figure out which partOfSpeech was selected
    if (subSelectedNow) {
        // get our gender
        Gender wordGender;
        if (dasButton->isChecked()) {
            wordGender = DAS;
        } else if (dieButton->isChecked()) {
            wordGender = DIE;
        } else {
            wordGender = DER;
        }
        Noun newNoun(wortBox->text(), wordGender, definitionBox->text());
        words->addWord(newNoun);
    } else {
        Verb newVerb(wortBox->text(), definitionBox->text());
        words->addWord(newVerb);
    }

    emit done();
}

#endif

newWordScreen::~newWordScreen()
{

}
