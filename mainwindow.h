#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "enginecontainer.h"
#include "code_editor/include/KGL/Widgets/QCodeEditor.hpp"

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
    void logSent(Console::Level level, const QString &msg);

private:
    Ui::MainWindow *ui;
    void loadLastScript();
    EngineContainer engines;
    kgl::QCodeEditor editorJS;
    kgl::QCodeEditor editorLUA;
};
#endif // MAINWINDOW_H
