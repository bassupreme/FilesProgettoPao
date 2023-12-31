// direttive d'inclusione
#include <QApplication>
#include <QStatusBar>
#include <QScrollArea>
#include <QSplitter>
#include <QList>
#include <QAction>
#include <QPixmap>
#include <QIcon>
#include <QFileDialog>
#include <QMessageBox>
#include <iostream>

// inclusioni utente
#include "mainwindow.h"
#include "model/Fisico.h"
#include "model/Virtuale.h"
#include "model/Noleggio.h"
#include "filePersistence/JsonReader.h"
#include "filePersistence/JsonConverter.h"
#include "EditorFisico.h"
#include "EditorVirtuale.h"
#include "EditorNoleggio.h"
#include "ItemEditorRenderer.h"
#include "ItemCreator.h"


MainWindow::MainWindow(Memory& memory, QWidget *parent) : QMainWindow(parent), buffer(nullptr), memory(memory), jsonFile(nullptr) {

    // CREAZIONE ACTIONS DELLA TOOLBAR
    QAction* create = new QAction(
                QIcon(QPixmap((":/assets/icons/new.svg"))),
                "Nuovo dataset"
                );
    create->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));
    QAction* open = new QAction(
                QIcon(QPixmap((":/assets/icons/open.svg"))),
                "Apri"
                );
    open->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_O));
    QAction* save = new QAction(
                QIcon(QPixmap((":/assets/icons/save.svg"))),
                "Salva"
                );
    save->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));
    QAction* togge_toolbar = new QAction(
                "Toolbar"
                );
    createItem = new QAction(
                QIcon(QPixmap((":/assets/icons/new_item.svg"))),
                "Nuovo Prodotto"
        );
    QAction* close = new QAction(
                QIcon(QPixmap((":/assets/icons/close.svg"))),
                "Esci"
                );
    createItem ->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_N));
    createItem ->setEnabled(false);

    // SETUP DELLA TOOLBAR
    toolbar = addToolBar("File Toolbar");
    toolbar->addAction(create);
    toolbar->addAction(open);
    toolbar->addAction(save);
    toolbar->addSeparator();
    toolbar->addAction(createItem);
    toolbar->addAction(close);
    toolbar->addSeparator();

    // SPLITTER
    QSplitter* splitter = new QSplitter(this);

    // RESULT WIDGET
    // creazione scrollArea
    QScrollArea* customScrollArea = new QScrollArea();
    customScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    customScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    customScrollArea->setWidgetResizable(true);
    resultsWidget = new ResultsWidget(this);
    customScrollArea->setWidget(resultsWidget);

    // STACKED WIDGET
    stackedWidget = new QStackedWidget(this);
    stackedWidget->addWidget(customScrollArea);


    // FILTER WIDGET
    filterWidget = new FilterWidget();
    filterWidget->getButtonApply()->setEnabled(false);


    // AGGIUNTA ELEMENTI ALLO SPLITTER E SETUP
    splitter->addWidget(stackedWidget);
    splitter->addWidget(filterWidget);
    splitter->setSizes(QList<int>() << 3000 << 1000);

    // WIDGET CENTRALE DELLA MAINWINDOW
    setCentralWidget(splitter);

    // CONNESSIONI SEGNALI E SLOT
    connect(togge_toolbar, &QAction::triggered, this, &MainWindow::toggleToolbar);
    connect(create, &QAction::triggered, this, &MainWindow::createDataset);
    connect(open, &QAction::triggered, this, &MainWindow::openDataset);
    connect(createItem, &QAction::triggered, this, &MainWindow::createProduct);
    connect(save, &QAction::triggered, this, &MainWindow::writeDataset);
    connect(close, &QAction::triggered, this, &MainWindow::close);
    connect(filterWidget, SIGNAL(signalFilter(Filter*)), this, SLOT(search(Filter*)));
    connect(filterWidget, SIGNAL(signalCleared(Filter*)), this, SLOT(search(Filter*)));
}

MainWindow::~MainWindow() {

}

void MainWindow::clearResults() {
    resultsWidget->clearResults();
}

void MainWindow::setHasUnsavedChanges(const bool& unsavedChanges) {
    hasUnsavedChanges = unsavedChanges;
}

FilterWidget *MainWindow::getFilterWidget() const {
    return filterWidget;
}

Buffer *MainWindow::getBuffer() const {
    return buffer;
}

Memory& MainWindow::getMemory() const {
    return memory;
}

void MainWindow::createDataset() {
    QString path = QFileDialog::getSaveFileName(
                this,
                "Creates new Dataset",
                "./",
        "JSON files *.json"
        );

    if (!path.isEmpty()) {
        if(buffer != nullptr) {
            buffer->clear();
            delete buffer;
        }
        if (jsonFile != nullptr) {
            delete jsonFile;
        }

        jsonFile = new JsonFile(path.toStdString());
        buffer = new Buffer();
        resultsWidget->clearResults();
        search(nullptr);
        createItem->setEnabled(true);
        showStatus("New dataset created.", 3000);

    }
}

void MainWindow::openDataset() {
    QString path = QFileDialog::getOpenFileName(
        this,
        "Creates new Dataset",
        "./",
        "JSON files *.json"
        );
    if (!path.isEmpty()) {
        if (buffer != nullptr) {
            buffer->clear(); // clear del buffer
        }
        if (!memory.empty()) {
            memory.clear();
        }

        // creazione buffer di memoria
        buffer = new Buffer();
        // creazione puntatore a file
        jsonFile = new JsonFile(path.toStdString());

        // lettura dal file
        JsonReader reader;
        JsonConverter converter(reader);
        std::vector<AbstractProduct*> aux = jsonFile->ReadFrom(converter);

        // caricamento buffer e contenitore per la ricerca.
        buffer->load(aux);
        for(std::map<unsigned int, AbstractProduct*>::const_iterator cit = buffer->getMemoryBuffer().begin();
        cit != buffer->getMemoryBuffer().end();
        cit++) {
            memory.add(cit->second);
        }

        // attivare la creazione di un elemento.
        createItem->setEnabled(true);
        filterWidget->getButtonApply()->setEnabled(true);
        // chiamata del metodo per caricare i risultati
        search(nullptr);
    }
}

void MainWindow::writeDataset() {
    if (jsonFile == nullptr || buffer == nullptr) {
        QMessageBox::about(this, "errore", "Nessun file selezionato.");
        return;
    }

    JsonReader reader;
    JsonConverter converter(reader);
    jsonFile->WriteTo(buffer->readAll(), converter);

    // settare flag di cambiamenti a falso
    setHasUnsavedChanges(false);

    // mostrare status nella statusbar
    showStatus("dataset salvato", 5000);
}

void MainWindow::showStatus(const std::string& message, const unsigned int duration) {
    statusBar()->showMessage(QString::fromStdString(message), duration);
}

void MainWindow::clearStack() {
    QWidget* widget = stackedWidget->widget(1);
    while (widget) {
        stackedWidget->removeWidget(widget);
        delete widget;
        widget = stackedWidget->widget(1);
    }
}

void MainWindow::toggleToolbar() {
    toolbar->setVisible(!toolbar->isVisible());
    showStatus("Toolbar toggled.", 3000);
}

void MainWindow::createProduct() {
    // PULIZIA DEI WIDGET SOPRA LO STACK
    clearStack();

    // CREAZIONE WIDGET CREATE
    QWidget* container = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout();
    ItemCreator* itemCreator = new ItemCreator(this);
    layout->addWidget(itemCreator);
    layout->setAlignment(itemCreator, Qt::AlignHCenter | Qt::AlignTop);
    QPushButton* createItem = new QPushButton("CREA PRODOTTO");
    layout->addWidget(createItem);
    layout->setAlignment(createItem, Qt::AlignHCenter | Qt::AlignBottom);
    connect(createItem, SIGNAL(clicked()), itemCreator, SLOT(create()));
    container->setLayout(layout);

    QScrollArea* area = new QScrollArea();
    area->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    area->setWidgetResizable(true);
    area->setWidget(container);
    stackedWidget->addWidget(area);

    stackedWidget->setCurrentIndex(1);
    filterWidget->disable();
    showStatus("Creazione prodotto", 0);
}

void MainWindow::deleteProduct(const AbstractProduct* product) {
    resultsWidget->deleteResult(product);
    memory.remove(product);
    buffer->remove(product->getId());
    setHasUnsavedChanges(true);
}

void MainWindow::updateProduct(const AbstractProduct* product) {

    // PULIZIA DEI WIDGET SOPRA LO STACK
    clearStack();

    // CREAZIONE WIDGET EDIT
    QWidget* container = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout();
    ItemEditorRenderer renderer(this);
    product->accept(renderer);
    QWidget* editor = renderer.getRenderedEditor();
    layout->addWidget(editor);
    layout->setAlignment(editor, Qt::AlignHCenter | Qt::AlignTop);
    QPushButton* applyChanges = new QPushButton("APPLICA");
    layout->addWidget(applyChanges);
    layout->setAlignment(applyChanges, Qt::AlignHCenter | Qt::AlignBottom);
    connect(applyChanges, SIGNAL(clicked()), editor, SLOT(emitSignalUpdate()));
    container->setLayout(layout);

    QScrollArea* area = new QScrollArea();
    area->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    area->setWidgetResizable(true);
    area->setWidget(container);
    stackedWidget->addWidget(area);

    stackedWidget->setCurrentIndex(1);
    filterWidget->getButtonApply()->setEnabled(false);
    showStatus("Modifica prodotto", 0);

}

void MainWindow::search(Filter* filter) {
    resultsWidget->clearResults();
    filterWidget->getButtonApply()->setEnabled(true);
    if (filter == nullptr) {
        resultsWidget->renderResults(buffer->readAll());
        stackedWidget->setCurrentIndex(0);
        clearStack();
    } else {
        const std::vector<const AbstractProduct*> results = memory.search(filter);
        resultsWidget->renderResults(results);
    }
}

void MainWindow::close() {
    if (hasUnsavedChanges) {
        QMessageBox::StandardButton confirmation;
        confirmation = QMessageBox::question(
                    this,
                    "Quit?",
                    "Ci sono dei cambiamenti non salvati.",
                    QMessageBox::Yes | QMessageBox::No
                    );
        if (confirmation == QMessageBox::Yes) {
            QApplication::quit();
        }
    }
    else {
        QApplication::quit();
    }
}
