#include "messagebox.h"
#include <QMessageBox>

MessageBox::MessageBox() {}

void MessageBox::info(const QString &title, const QString &msg) {
    QMessageBox::information(nullptr, title, msg);
}

void MessageBox::warn(const QString &title, const QString &msg) {
    QMessageBox::warning(nullptr, title, msg);
}

void MessageBox::error(const QString &title, const QString &msg) {
    QMessageBox::critical(nullptr, title, msg);
}

// ok, cancel
bool MessageBox::confirm(const QString &title, const QString &msg) {
    return QMessageBox::question(nullptr, title, msg) == QMessageBox::Yes;
}

int  MessageBox::select(const QString &title, const QStringList &options) {
    QMessageBox msgBox;
    msgBox.setWindowTitle(title);
    msgBox.setText("Select an option:");
    QList<QAbstractButton*> buttons;
    for (const QString &opt : options) {
        QPushButton *btn = msgBox.addButton(opt, QMessageBox::ActionRole);
        // buttons.append(btn);
    }
    msgBox.exec();
    QAbstractButton *clicked = msgBox.clickedButton();
    int index = buttons.indexOf(clicked);

    return index;
}
