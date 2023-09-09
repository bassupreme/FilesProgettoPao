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
    boxImagePath->setEnabled(false);
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
    boxPrezzo->setMaximum(__DBL_MAX__);

    // aggiunta oggetti grafici al form
    vbox->addLayout(container);
    container->addRow("id:", boxId);
    if (subject != nullptr) { boxId->setEnabled(false);}
    container->addRow("prezzo:", boxPrezzo);
    container->addRow("nome:", boxNome);
    container->addRow("imagePath:", imageRow);
    container->addRow("descrizione:", boxDescription);

    // CONNESSIONE SEGNALI E SLOT
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

void AbstractEditor::updatedProduct(const AbstractProduct* product) {
    AbstractProduct* aux = update();

    // prodotto nuovo
    Buffer* buffer = getMainWindow()->getBuffer();
    buffer->remove(product->getId());
    buffer->insert(aux->getId(), aux);

    Memory& memory = getMainWindow()->getMemory();
    memory.remove(product);
    memory.add(aux);

    getMainWindow()->setHasUnsavedChanges(true);
    getMainWindow()->clearResults();
    getMainWindow()->search(nullptr);
    getMainWindow()->showStatus("Prodotto modificato", 3000);
}

