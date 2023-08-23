#include "TestProductEditor.h"
#include <QLabel>
#include <QVBoxLayout>

TestProductEditor::TestProductEditor(MainWindow* mainWindow, AbstractProduct* subject, QWidget *parent) : QWidget(parent), mainWindow(mainWindow), subject(subject) {
    QVBoxLayout* layout = new QVBoxLayout(this);
    QLabel* label = new QLabel("EDITOR DI TESTING");
    QLabel* labelEdited = new QLabel(QString::fromStdString(std::to_string(subject->getId())));
    apply = new QPushButton("APPLY CHANGES");
    label->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    labelEdited->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    layout->setAlignment(apply, Qt::AlignHCenter | Qt::AlignTop);

    // aggiunta widgets al layout
    layout->addWidget(label);
    layout->addWidget(labelEdited);
    layout->addWidget(apply);

    // connessione con slot e signal
    connect(apply, SIGNAL(clicked()), this, SLOT(appliedChanges()));

}


void TestProductEditor::appliedChanges() {
    std::cout << "TestProductEditor::appliedChanges()" << std::endl;
    emit searchAll(nullptr);
}
