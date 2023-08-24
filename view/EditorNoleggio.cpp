#include "EditorNoleggio.h"
#include "model/Noleggio.h"
#include <QVBoxLayout>
#include <QFormLayout>

EditorNoleggio::EditorNoleggio(MainWindow *mainWindow, AbstractProduct* subject, QWidget *parent) : AbstractEditor(mainWindow, subject, parent) {
    // setup oggetti grafici di questo editor specifico
    checkBoxUsato = new QCheckBox();
    boxNoleggiante = new QLineEdit();
    boxNoleggiatore = new QLineEdit();

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
    form->addRow("noleggiante", boxNoleggiante);
    form->addRow("noleggiatore", boxNoleggiatore);
    // form->addRow("apply changes:", getButtonApply());

    // connect(getButtonApply(), SIGNAL(clicked()), this, SLOT(emitSignalUpdate()));
    connect(this, SIGNAL(signalUpdated(AbstractProduct*)), this,  SLOT(updatedProduct(AbstractProduct*)));

}

void EditorNoleggio::injectItem(const Noleggio& product) {
    // settare i campi delle box
    getBoxId()->setValue(product.getId());
    getBoxPrezzo()->setValue(product.getPrezzo());
    getBoxNome()->setText(QString::fromStdString(product.getNome()));
    getBoxImagePath()->setText(QString::fromStdString(product.getImagePath()));
    getBoxDescription()->setText(QString::fromStdString(product.getDescription()));
    checkBoxUsato->setChecked(product.getUsato());
    boxNoleggiatore->setText(QString::fromStdString(product.getNoleggiatore()));
    boxNoleggiante->setText(QString::fromStdString(product.getNoleggiante()));
}

AbstractProduct* EditorNoleggio::update() {
    return create();
}

AbstractProduct* EditorNoleggio::create() {
    std::cout << "EditorNoleggio::create()" << std::endl;
    return new Noleggio(getBoxId()->value(),
              getBoxPrezzo()->value(),
              getBoxNome()->text().toStdString(),
              getBoxImagePath()->text().toStdString(),
              getBoxDescription()->toPlainText().toStdString(),
              checkBoxUsato->isChecked(),
              boxNoleggiatore->text().toStdString(),
                        boxNoleggiante->text().toStdString());

}

void EditorNoleggio::emitSignalUpdate() {
    emit signalUpdated(getSubject());
}

void EditorNoleggio::emitSignalCreate() {
    emit signalCreated(getSubject());
}

void EditorNoleggio::updatedProduct(AbstractProduct* product) {
    // richiamare la funzione update
    std::cout << "EditorNoleggio::updatedProduct()" << std::endl;
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

void EditorNoleggio::CreatedProduct(AbstractProduct* product) {

}

