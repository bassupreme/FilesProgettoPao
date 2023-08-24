// direttive d'inclusione
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScrollArea>
#include <QSplitter> // andare a vedere la documentazione
#include <QList> // serve per lo splitter
#include <QAction>
#include <QPixmap>
#include <QIcon>
#include <iostream>

// inclusioni di test
#include "model/Fisico.h"
#include "model/Virtuale.h"
#include "model/Noleggio.h"
#include "TestProductEditor.h"
#include "EditorFisico.h"
#include "EditorVirtuale.h"
#include "EditorNoleggio.h"
#include "ItemEditorRenderer.h"
#include "ItemCreator.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // DATI DI TEST FAKE
    AbstractProduct* p1 =  new Noleggio(1, 9.5, "pc", "path", "descrizione", true, "negizio", "io");
    AbstractProduct* p2 =   new Fisico(2, 2.0, "chitarra", "path", "descrizione");
    AbstractProduct* p3 =   new Noleggio(3, 2.0, "casse", "path", "descrizione", "negozio");
    AbstractProduct* p4 =   new Fisico(4, 2.0, "basso", "path", "descrizione");
    AbstractProduct* p5 =   new Virtuale(5, 9.0, "cd", "path", "descrizione");

    aux.push_back(p1);
    aux.push_back(p2);
    aux.push_back(p3);
    aux.push_back(p4);
    aux.push_back(p5);


    // Actions
    QAction* create = new QAction(
                QIcon(QPixmap((":/assets/icons/new.svg"))),
                "New"
                );
    create->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));
    QAction* open = new QAction(
                QIcon(QPixmap((":/assets/icons/open.svg"))),
                "Open"
                );
    open->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_O));
    QAction* save = new QAction(
                QIcon(QPixmap((":/assets/icons/save.svg"))),
                "Save"
                );
    save->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));
    QAction* save_as = new QAction(
                QIcon(QPixmap((":/assets/icons/save_as.svg"))),
                "Save As"
                );
    save_as->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_S));
    QAction* close = new QAction(
                QIcon(QPixmap((":/assets/icons/close.svg"))),
                "Close"
                );
    close->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Q));
    QAction* togge_toolbar = new QAction(
                "Toolbar"
                );
    QAction* create_item = new QAction(
                QIcon(QPixmap((":/assets/icons/new_item.svg"))),
                "New Item"
                );
    create_item->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_N));
    create_item->setEnabled(true);


    // SETUP DELLA TOOLBAR
    toolbar = addToolBar("File Toolbar");
    toolbar->addAction(create);
    toolbar->addAction(open);
    toolbar->addAction(save);
    toolbar->addAction(save_as);
    toolbar->addSeparator();
    toolbar->addAction(create_item);
    toolbar->addSeparator();
    toolbar->addAction(close);



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


    // stacked widget
    stackedWidget = new QStackedWidget(this);
    splitter->addWidget(stackedWidget);

    stackedWidget->addWidget(customScrollArea);


    // FILTER WIDGET
    filterWidget = new FilterWidget();
    splitter->addWidget(filterWidget);

    setCentralWidget(splitter);

    // SEGNALI E SLOT
    // azioni grafiche
    connect(togge_toolbar, &QAction::triggered, this, &MainWindow::toggleToolbar);
    connect(create_item, &QAction::triggered, this, &MainWindow::createProduct);
    search(nullptr);
}

MainWindow::~MainWindow() {

}

void MainWindow::clearResults() {
    clearStack();
    resultsWidget->clearResults();
}

std::vector<AbstractProduct *> &MainWindow::getMemory() {
    return aux;
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
    showStatus("Toolbar toggled.");
}

void MainWindow::createProduct() {
    // DEBUG
    std::cout << "MainWindow::updateProduct" << std::endl;

    clearStack();

    // CREAZIONE WIDGET CREATE
    QWidget* container = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout();
    ItemCreator* itemCreator = new ItemCreator(this);
    layout->addWidget(itemCreator);
    layout->setAlignment(itemCreator, Qt::AlignHCenter | Qt::AlignTop);
    QPushButton* createItem = new QPushButton("CREATE PRODUCT");
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
    showStatus("Creating Item", 0);
}

void MainWindow::deleteProduct(AbstractProduct* product) {
    std::cout << "SLOT MAIN WINDOW" << std::endl;
    std::cout << "eliminare prodotto: " << std::to_string(product->getId()) << std::endl;
    resultsWidget->deleteResult(product);
}

void MainWindow::updateProduct(AbstractProduct* product) {
    // DEBUG
    std::cout << "MainWindow::updateProduct" << std::endl;
    std::cout << "aggiornare prodotto: " << std::to_string(product->getId()) << std::endl;

    clearStack();

    // CREAZIONE WIDGET EDIT
    QWidget* container = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout();
    ItemEditorRenderer* renderer = new ItemEditorRenderer(this);
    product->accept(*renderer);
    QWidget* editor = renderer->getRenderedEditor();
    layout->addWidget(editor);
    layout->setAlignment(editor, Qt::AlignHCenter | Qt::AlignTop);
    QPushButton* applyChanges = new QPushButton("APPLY CHANGES");
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
    showStatus("Editing Item", 0);
}

void MainWindow::search(Filter *) {
        resultsWidget->renderResults(aux);
    stackedWidget->setCurrentIndex(0);
    clearStack();
}


