#include "EditorFisico.h"
#include "model/Fisico.h"
#include "ItemInjector.h"
#include <QFormLayout>
#include <QVBoxLayout>
#include <iostream>


EditorFisico::EditorFisico(MainWindow *mainWindow, AbstractProduct *subject, QWidget *parent) : AbstractEditor(mainWindow, subject, parent) {
    // setup oggetti grafici di questo editor specifico
    checkBoxUsato = new QCheckBox("usato");


    // set up layout verticale
    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    // setup form layout
    QFormLayout* form = new QFormLayout();
    form->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);
    vbox->addLayout(form);

    form->addRow("id:", getBoxId());
    form->addRow("prezzo:", getBoxPrezzo());
    form->addRow("nome:", getBoxNome());
    form->addRow("imagePath:", getBoxImagePath());
    form->addRow("descrizione:", getBoxDescription());
    form->addRow("usato", checkBoxUsato);
    // form->addRow("apply changes:", getButtonApply());

    // connect(getButtonApply(), SIGNAL(clicked()), this, SLOT(emitSignalUpdate()));
    connect(this, SIGNAL(signalUpdated(AbstractProduct*)), this,  SLOT(updatedProduct(AbstractProduct*)));

}

AbstractProduct* EditorFisico::update() {
    // prendere il subject e modificarlo a seconda dei parametri appena immessi
    std::cout << "EditorFisico::update()" << std::endl;
    return create();

}

AbstractProduct* EditorFisico::create() {
    std::cout << "EditorFisico::create()" << std::endl;
    return new Fisico(getBoxId()->value(),
               getBoxPrezzo()->value(),
               getBoxNome()->text().toStdString(),
               getBoxImagePath()->text().toStdString(),
               getBoxDescription()->toPlainText().toStdString(),
               checkBoxUsato->isChecked());

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

void EditorFisico::emitSignalCreate() {

}

void EditorFisico::updatedProduct(AbstractProduct* product) {
    // richiamare la funzione update
    std::cout << "EditorFisico::updatedProduct()" << std::endl;
    AbstractProduct* aux = update();

    std::vector<AbstractProduct*>& memoria = getMainWindow()->getMemory();
    std::vector<AbstractProduct*>::const_iterator cit = memoria.begin();

    while ((*cit) != product) {
        cit++;
    }

    memoria.erase(cit);
    memoria.push_back(aux);
    delete product;

    getMainWindow()->clearResults();
    getMainWindow()->search(nullptr);
}

void EditorFisico::CreatedProduct(AbstractProduct *)
{

}

