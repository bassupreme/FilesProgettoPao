#include "EditorFisico.h"
#include "model/Fisico.h"
#include "ItemInjector.h"
#include <QFormLayout>
#include <QVBoxLayout>
#include <iostream>


EditorFisico::EditorFisico(MainWindow *mainWindow, const AbstractProduct *subject, QWidget *parent) : AbstractEditor(mainWindow, subject, parent) {
    // setup oggetti grafici di questo editor specifico
    checkBoxUsato = new QCheckBox("usato");
    getContainer()->addRow("usato", checkBoxUsato);

    // connect(getButtonApply(), SIGNAL(clicked()), this, SLOT(emitSignalUpdate()));
    connect(this, SIGNAL(signalUpdated(const AbstractProduct*)), this,  SLOT(updatedProduct(const AbstractProduct*)));
}

AbstractProduct* EditorFisico::update() const {
    // prendere il subject e modificarlo a seconda dei parametri appena immessi
    std::cout << "EditorFisico::update()" << std::endl;
    return create();
}

AbstractProduct* EditorFisico::create() const {
    std::cout << "EditorFisico::create()" << std::endl;
    return new Fisico(getBoxId()->value(),
               getBoxPrezzo()->value(),
               getBoxNome()->text().toStdString(),
               getBoxImagePath()->text().toStdString(),
               getBoxDescription()->toPlainText().toStdString(),
               checkBoxUsato->isChecked());
}

QCheckBox *EditorFisico::getCheckBoxUsato() const {
    return checkBoxUsato;
}

void EditorFisico::injectItem(const Fisico& product) {
    // settare i campi delle box
    getBoxId()->setValue(product.getId());
    getBoxPrezzo()->setValue(product.getPrezzo());
    getBoxNome()->setText(QString::fromStdString(product.getNome()));
    getBoxImagePath()->setText(QString::fromStdString(product.getImagePath()));
    getBoxDescription()->setText(QString::fromStdString(product.getDescription()));
    checkBoxUsato->setChecked(product.getUsato());
}

void EditorFisico::emitSignalUpdate() {
    emit signalUpdated(getSubject());
}

