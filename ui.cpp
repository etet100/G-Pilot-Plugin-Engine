#include "ui.h"
#include <QDebug>
#include <QDialog>
#include <QFile>
#include <QtUiTools/QUiLoader>
#include <QLayout>
#include <QHBoxLayout>

UI::UI(QMainWindow *mainWindow) : mainWindow(mainWindow) {}

void UI::loadUiFile(QString name)
{
    QFile file(":/test/" + name);
    if (!file.open(QFile::ReadOnly)) {
        qFatal("Cannot open resource file");
    }

    QUiLoader loader;
    QWidget *widget = loader.load(&file);

    file.close();

    if (!widget) {
        qFatal("Cannot load UI file");
    }

    elements.append(widget);
}

void UI::loadUiFile2(std::string name)
{
    loadUiFile(QString::fromStdString(name));
}

void UI::createWindow(QString title)
{
    QLayout *l = new QHBoxLayout();
    l->addWidget(elements[0]);
    // l->addWidget(elements[0]);
    l->update();

    QDialog *dialog = new QDialog(mainWindow);
    dialog->setWindowTitle(title);
    dialog->setMinimumSize(QSize(200, 100));
    dialog->setModal(true);
    dialog->setLayout(l);
    dialog->adjustSize();
    dialog->show();

    elements.append(dialog);
}

void UI::createWindow2(std::string title)
{
    createWindow(QString::fromStdString(title));
}

void UI::createButton() {
    qDebug() << "Button created!";
}

void UI::createEdit() {
    qDebug() << "Edit created!";
}

void UI::createLabel() {
    qDebug() << "Label created!";
}

void UI::createCheckbox() {
    qDebug() << "Checkbox created!";
}

void UI::createRadiobutton() {
    qDebug() << "Radiobutton created!";
}

void UI::LoadQml(const QString &file) {
    qDebug() << "QML file loaded:" << file;
}
