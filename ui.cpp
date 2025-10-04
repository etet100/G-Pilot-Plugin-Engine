#include "ui.h"
#include <QDebug>

UI::UI() {}

void UI::CreateButton() {
    qDebug() << "Button created!";
}

void UI::CreateEdit() {
    qDebug() << "Edit created!";
}

void UI::CreateLabel() {
    qDebug() << "Label created!";
}

void UI::CreateCheckbox() {
    qDebug() << "Checkbox created!";
}

void UI::CreateRadiobutton() {
    qDebug() << "Radiobutton created!";
}

void UI::LoadQml(const QString &file) {
    qDebug() << "QML file loaded:" << file;
}
