#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QObject>
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QSettings>
#include "settings.h"
#include "apis.h"
#include "code_editor/include/KGL/Widgets/QCodeEditor.hpp"

class UIButton {
};

class UIEdit {
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , jsEngine(this)
    , luaEngine(this)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->verticalLayout_2->addWidget(&editorJS);
    ui->verticalLayout_2->addWidget(&editorLUA);
    connect(&editorJS, &QPlainTextEdit::textChanged, this, &MainWindow::scriptChanged);
    connect(&editorLUA, &QPlainTextEdit::textChanged, this, &MainWindow::scriptChanged);

    connect(this->jsEngine.console(), &Console::message, this, &MainWindow::logSent);
    connect(this->luaEngine.console(), &Console::message, this, &MainWindow::logSent);

    loadLastScript();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addLog(const QString &type, const QString &msg)
{
    this->ui->log->append(QString("[%1] %2").arg(type).arg(msg));
}

void MainWindow::runClicked()
{
    this->jsEngine.execute(editorJS.toPlainText());
    this->luaEngine.execute(editorLUA.toPlainText());
}

void MainWindow::scriptChanged()
{
    QFile file1("last_js.js");
    if (file1.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        file1.write(editorJS.toPlainText().toUtf8());
        file1.close();
    }

    QFile file2("last_lua.js");
    if (file2.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        file2.write(editorLUA.toPlainText().toUtf8());
        file2.close();
    }
}

void MainWindow::ev1Clicked()
{

}

void MainWindow::ev2Clicked()
{

}

void MainWindow::logSent(Console::Level level, const QString &msg)
{
    switch (level) {
    case Console::Level::Log:
        this->addLog("LOG", msg);
        qDebug() << msg;

        break;
    case Console::Level::Warn:
        this->addLog("WARN", msg);
        qWarning() << msg;

        break;
    case Console::Level::Error:
        this->addLog("ERROR", msg);
        qCritical() << msg;

        break;
    }
}

void MainWindow::loadLastScript()
{
    QFile file1("last_js.js");
    if (file1.open(QIODevice::ReadOnly)) {
        QByteArray data = file1.readAll();
        editorJS.setPlainText(QString::fromUtf8(data));
        file1.close();
    }

    QFile file2("last_lua.js");
    if (file2.open(QIODevice::ReadOnly)) {
        QByteArray data = file2.readAll();
        editorLUA.setPlainText(QString::fromUtf8(data));
        file2.close();
    }
}

