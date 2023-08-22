#include "TestProductEditor.h"
#include <QLabel>
#include <QVBoxLayout>

TestProductEditor::TestProductEditor(QMainWindow* mainWindow, QWidget *parent) : QWidget(parent), mainWindow(mainWindow) {
    QVBoxLayout* layout = new QVBoxLayout(this);
    QLabel* label = new QLabel("EDITOR DI TESTING");
    apply = new QPushButton("APPLY CHANGES");

    // aggiunta widgets al layout
    layout->addWidget(label);
    layout->addWidget(apply);

    // connessione con slot e signal
    connect(apply, SIGNAL(clicked()), this, SLOT(appliedChanges()));

}


void TestProductEditor::appliedChanges() {
    std::cout << "TestProductEditor::appliedChanges()" << std::endl;
    emit searchAll(nullptr);
}
