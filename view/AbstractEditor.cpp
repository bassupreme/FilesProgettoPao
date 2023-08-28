#include "AbstractEditor.h"

AbstractEditor::~AbstractEditor() {

}

AbstractEditor::AbstractEditor(MainWindow *mainWindow, const AbstractProduct *subject, QWidget *parent) : QWidget(parent), mainWindow(mainWindow), subject(subject) {

    boxId = new QSpinBox();
    boxPrezzo = new QDoubleSpinBox();
    boxNome = new QLineEdit();
    boxImagePath = new QLineEdit();
    boxDescription = new QTextEdit();
    buttonApply = new QPushButton("APPLY");
    // setup oggetti
    boxId->setMinimum(1);
    boxId->setMaximum(INT_MAX);

    boxPrezzo->setMinimum(0.0);
    boxPrezzo->setMaximum(1000.0);

    /*
    if (subject != nullptr) { // questo nel caso in cui questo editor venga usato durante la modifica di un prodotto.
        boxId->setValue(subject->getId());
        boxPrezzo->setValue(subject->getPrezzo());
        boxNome->setText(QString::fromStdString(subject->getNome()));
        boxImagePath->setText(QString::fromStdString(subject->getImagePath()));
    }
    */
}

QSpinBox* AbstractEditor::getBoxId() const {
    return boxId;
}

QDoubleSpinBox* AbstractEditor::getBoxPrezzo() const {
    return boxPrezzo;
}

QLineEdit *AbstractEditor::getBoxNome() const {
    return boxNome;
}

QLineEdit *AbstractEditor::getBoxImagePath() const {
    return boxImagePath;
}

QTextEdit *AbstractEditor::getBoxDescription() const {
    return boxDescription;
}

QPushButton *AbstractEditor::getButtonApply() const {
    return buttonApply;
}

const AbstractProduct *AbstractEditor::getSubject() const {
    return subject;
}

MainWindow *AbstractEditor::getMainWindow() const {
    return mainWindow;
}

