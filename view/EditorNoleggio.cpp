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
    getBoxId()->setValue(product.getId());
    getBoxPrezzo()->setValue(product.getPrezzo());
    getBoxNome()->setText(QString::fromStdString(product.getNome()));
    getBoxImagePath()->setText(QString::fromStdString(product.getImagePath()));
    getBoxDescription()->setText(QString::fromStdString(product.getDescription()));
    getCheckBoxUsato()->setChecked(product.getUsato());
    boxNoleggiatore->setText(QString::fromStdString(product.getNoleggiatore()));
    boxNoleggiante->setText(QString::fromStdString(product.getNoleggiante()));
}

AbstractProduct* EditorNoleggio::update() const {
    return create();
}

AbstractProduct* EditorNoleggio::create() const {
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

