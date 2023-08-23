#include "EditorFisico.h"
#include "model/Fisico.h".h"
#include <QFormLayout>
#include <QVBoxLayout>
#include <iostream>


EditorFisico::EditorFisico(MainWindow *mainWindow, AbstractProduct *subject, QWidget *parent) : AbstractEditor(mainWindow, subject, parent){
    // setup oggetti grafici di questo editor specifico
    checkBoxUsato = new QCheckBox("usato");

    Fisico* oggetto = dynamic_cast<Fisico*>(subject);
    if(subject != nullptr) {
        checkBoxUsato->setChecked(oggetto->getUsato());
    }

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
    form->addRow("usato", checkBoxUsato);
    form->addRow("apply changes:", getButtonApply());


    connect(getButtonApply(), SIGNAL(clicked()), this, SLOT(emitSignalUpdate()));
    connect(this, SIGNAL(signalUpdated(AbstractProduct*)), this,  SLOT(updatedProduct(AbstractProduct*)));
}

void EditorFisico::update() {
    // prendere il subject e modificarlo a seconda dei parametri appena immessi
    std::cout << "EditorFisico::update()" << std::endl;
}

void EditorFisico::create() {

}

void EditorFisico::emitSignalUpdate() {
    emit signalUpdated(getSubject());
}

void EditorFisico::emitSignalCreate() {

}

void EditorFisico::updatedProduct(AbstractProduct *) {
    // richiamare la funzione update
    std::cout << "EditorFisico::updatedProduct()" << std::endl;
    update();
    MainWindow* w = getMainWindow();
    w->clearResults();
    getMainWindow()->search(nullptr);
}

void EditorFisico::CreatedProduct(AbstractProduct *)
{

}

