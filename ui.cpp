#include "ui.h"
#include <QDebug>

UI::UI() {}

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
