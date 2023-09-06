#include "EditorNoleggio.h"
#include "model/Noleggio.h"
#include <QVBoxLayout>
#include <QFormLayout>

EditorNoleggio::EditorNoleggio(MainWindow *mainWindow, const AbstractProduct* subject, QWidget *parent) : EditorFisico(mainWindow, subject, parent) {
    // CREAZIONE OGGETTI GRAFICI
    boxNoleggiante = new QLineEdit();
    boxNoleggiatore = new QLineEdit();

    // AGGIUNTA OGGETTI GRAFICI
    getContainer()->addRow("noleggiante", boxNoleggiante);
    getContainer()->addRow("noleggiatore", boxNoleggiatore);

    // CONNESSIONE SEGNALI E SLOT
    connect(this, SIGNAL(signalUpdated(const AbstractProduct*)), this,  SLOT(updatedProduct(const AbstractProduct*)));
}

void EditorNoleggio::injectItem(const Noleggio& product) {
    // settare i campi delle box
    getBoxId()->setValue(product.getId());
    getBoxPrezzo()->setValue(product.getPrezzo());
    getBoxNome()->setText(QString::fromStdString(product.getNome()));
    getBoxImagePath()->setText(QString::fromStdString(product.getImagePath()));
    getBoxDescription()->setText(QString::fromStdString(product.getDescription()));
    getCheckBoxUsato()->setChecked(product.getUsato());
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
              getCheckBoxUsato()->isChecked(),
              boxNoleggiatore->text().toStdString(),
                        boxNoleggiante->text().toStdString());

}

void EditorNoleggio::emitSignalUpdate() {
    emit signalUpdated(getSubject());
}

/*
void EditorNoleggio::updatedProduct(const AbstractProduct* product) {
    // richiamare la funzione update
    std::cout << "EditorNoleggio::updatedProduct()" << std::endl;
    AbstractProduct* aux = update();

    Buffer* buffer = getMainWindow()->getBuffer();
    buffer->remove(product->getId());
    buffer->insert(aux->getId(), aux);

    Memory& memory = getMainWindow()->getMemory();
    memory.remove(product);
    memory.add(aux);

    getMainWindow()->clearResults();
    getMainWindow()->search(nullptr);
}
*/
