#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QJSEngine>
#include <QJSValue>
#include <QObject>
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QSettings>
#include "settings.h"
#include "apis.h"

class UIButton {
};

class UIEdit {
};


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    // QJSEngine engine;

    // // 1) Proste wyrażenie JS
    // QJSValue res1 = engine.evaluate("1 + 2 + 3");
    // qDebug() << "1+2+3 =" << res1.toInt(); // oczekiwane: 6

    // // 2) Funkcja JS, wywołana z C++
    // engine.evaluate("function mul(a,b) { return a * b; }");
    // QJSValue mul = engine.globalObject().property("mul");
    // QJSValueList args;
    // args << 6 << 7;
    // QJSValue res2 = mul.call(args);
    // qDebug() << "6*7 =" << res2.toInt(); // oczekiwane: 42

    // // 3) Udostępnienie QObject do JS
    // Greeter greeter;
    // engine.globalObject().setProperty("greeter", engine.newQObject(&greeter));
    // QJSValue res3 = engine.evaluate("greeter.greet('Marek')");
    // qDebug() << res3.toString(); // oczekiwane: "Cześć, Marek!"

    // // 4) Obsługa błędów JS
    // QJSValue err = engine.evaluate("throw 'błąd testowy';");
    // if (err.isError()) {
    //     qDebug() << "JS error:" << err.toString();
    // }

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
    QJSEngine engine;

    UI ui;
    engine.globalObject().setProperty("ui", engine.newQObject(&ui));
    engine.globalObject().setProperty("u", engine.newQObject(&ui));

    // app
    engine.globalObject().setProperty("app", engine.newQObject(&this->app));
    engine.globalObject().setProperty("a", engine.newQObject(&this->app));

    Console console(this);
    engine.globalObject().setProperty("console", engine.newQObject(&console));
    engine.globalObject().setProperty("c", engine.newQObject(&console));

    MessageBox msgBox;
    engine.globalObject().setProperty("msgBox", engine.newQObject(&msgBox));
    engine.globalObject().setProperty("m", engine.newQObject(&msgBox));

    Settings settings;
    engine.globalObject().setProperty("settings", engine.newQObject(&settings));
    engine.globalObject().setProperty("s", engine.newQObject(&settings));

    Translations translations;
    engine.globalObject().setProperty("translations", engine.newQObject(&translations));
    engine.globalObject().setProperty("t", engine.newQObject(&translations));

    QJSValue err = engine.evaluate(this->ui->script->toPlainText());
    if (err.isError()) {
        qDebug() << "JS error:" << err.toString();
    }
}

void MainWindow::scriptChanged()
{
    QFile file("last_script.js");
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        file.write(this->ui->script->toPlainText().toUtf8());
        file.close();
    }
}

void MainWindow::ev1Clicked()
{

}

void MainWindow::ev2Clicked()
{

}

void MainWindow::loadLastScript()
{
    QFile file("last_script.js");
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray data = file.readAll();
        this->ui->script->setPlainText(QString::fromUtf8(data));
        file.close();
    }
}

#include "mainwindow.moc"
