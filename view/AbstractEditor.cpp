#include <iostream>
#include <QHBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include "AbstractEditor.h"

AbstractEditor::~AbstractEditor() {

}

AbstractEditor::AbstractEditor(MainWindow *mainWindow, const AbstractProduct *subject, QWidget *parent) : QWidget(parent), mainWindow(mainWindow), subject(subject) {

    // creazione oggetti grafici
    QVBoxLayout* vbox = new QVBoxLayout(this);
    container = new QFormLayout();
    boxId = new QSpinBox();
    boxPrezzo = new QDoubleSpinBox();
    boxNome = new QLineEdit();
    QHBoxLayout* imageRow = new QHBoxLayout();
    boxImagePath = new QLineEdit();
    QPushButton* btnSelectImage = new QPushButton("select");
    imageRow->addWidget(boxImagePath);
    imageRow->addWidget(btnSelectImage);
    boxDescription = new QTextEdit();
    buttonApply = new QPushButton("APPLY");

    // setup oggetti
    container->setAlignment(Qt::AlignRight | Qt::AlignTop);
    boxId->setMinimum(1);
    boxId->setMaximum(INT_MAX);
    boxPrezzo->setMinimum(0.0);
    boxPrezzo->setMaximum(1000.0);

    // aggiunta oggetti grafici al form
    vbox->addLayout(container);
    container->addRow("id:", boxId);
    container->addRow("prezzo:", boxPrezzo);
    container->addRow("nome:", boxNome);
    container->addRow("imagePath:", imageRow);
    container->addRow("descrizione:", boxDescription);

    /*
    if (subject != nullptr) { // questo nel caso in cui questo editor venga usato durante la modifica di un prodotto.
        boxId->setValue(subject->getId());
        boxPrezzo->setValue(subject->getPrezzo());
        boxNome->setText(QString::fromStdString(subject->getNome()));
        boxImagePath->setText(QString::fromStdString(subject->getImagePath()));
    }
    */
    connect(btnSelectImage, SIGNAL(clicked()), this, SLOT(selectImage()));
}

QFormLayout *AbstractEditor::getContainer() const {
    return container;
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

void AbstractEditor::selectImage() {
    std::cout << "select new image" << std::endl;

    QString path = QFileDialog::getOpenFileName(
                this,
                "Select image",
                "./",
                "Image files (*.jpg *.jpeg *.png)"
                );
    if (path.isEmpty()) {
        return;
    }
    boxImagePath->setText(path);
}

