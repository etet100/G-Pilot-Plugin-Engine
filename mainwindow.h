#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "app.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

enum LogType {
    Log,
    Warn,
    Error
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addLog(const QString &type, const QString &msg);

public slots:
    void runClicked();
    void scriptChanged();
    void ev1Clicked();
    void ev2Clicked();

private:
    Ui::MainWindow *ui;
    void loadLastScript();
    AppApi app;
};
#endif // MAINWINDOW_H
