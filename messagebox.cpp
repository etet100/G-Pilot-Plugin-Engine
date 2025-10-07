#include "messagebox.h"
#include <QMessageBox>

MsgBox::MsgBox() {}

void MsgBox::info(const QString &title, const QString &msg) {
    QMessageBox::information(nullptr, title, msg);
}

void MsgBox::info2(std::string title, std::string msg)
{
    QMessageBox::information(nullptr, QString::fromStdString(title), QString::fromStdString(msg));
}

void MsgBox::warn(const QString &title, const QString &msg) {
    QMessageBox::warning(nullptr, title, msg);
}

void MsgBox::warn2(std::string title, std::string msg)
{
    QMessageBox::warning(nullptr, QString::fromStdString(title), QString::fromStdString(msg));
}

void MsgBox::error(const QString &title, const QString &msg) {
    QMessageBox::critical(nullptr, title, msg);
}

void MsgBox::error2(std::string title, std::string msg)
{
    QMessageBox::critical(nullptr, QString::fromStdString(title), QString::fromStdString(msg));
}

// ok, cancel
bool MsgBox::confirm(const QString &title, const QString &msg) {
    return QMessageBox::question(nullptr, title, msg) == QMessageBox::Yes;
}

bool MsgBox::confirm2(std::string title, std::string msg)
{
    return QMessageBox::question(nullptr, QString::fromStdString(title), QString::fromStdString(msg)) == QMessageBox::Yes;
}

int MsgBox::select(const QString &title, const QStringList &options) {
    QMessageBox msgBox;
    msgBox.setWindowTitle(title);
    msgBox.setText("Select an option:");

    QList<QPushButton*> buttons;
    for (const QString &opt : options) {
        buttons.append(msgBox.addButton(opt, QMessageBox::ActionRole));
    }
    msgBox.exec();

    QPushButton *clicked = (QPushButton*)msgBox.clickedButton();
    int index = buttons.indexOf(clicked);

    return index;
}

int MsgBox::select2(std::string title, std::vector<std::string> options)
{
    QStringList qOptions;
    for (const std::string &opt : options) {
        qOptions.append(QString::fromStdString(opt));
    }

    return select(QString::fromStdString(title), qOptions);
}
