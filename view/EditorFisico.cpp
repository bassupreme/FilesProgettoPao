#include "EditorFisico.h"
#include "model/Fisico.h"
#include "ItemInjector.h"
#include <QFormLayout>
#include <QVBoxLayout>
#include <iostream>


EditorFisico::EditorFisico(MainWindow *mainWindow, const AbstractProduct *subject, QWidget *parent) : AbstractEditor(mainWindow, subject, parent) {
    checkBoxUsato = new QCheckBox("usato");
    getContainer()->addRow("usato", checkBoxUsato);

    connect(this, SIGNAL(signalUpdated(const AbstractProduct*)), this,  SLOT(updatedProduct(const AbstractProduct*)));
}

AbstractProduct* EditorFisico::update() const {
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

