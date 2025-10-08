#ifndef UI_H
#define UI_H

#include <QObject>
#include "export.h"

class PLUGINENGINE_EXPORT UI : public QObject {
    Q_OBJECT

public:
    UI(QWidget *mainWindow);

    Q_INVOKABLE void loadUiFile(QString name);
    void loadUiFile2(std::string name);
    Q_INVOKABLE void createWindow(QString title);
    void createWindow2(std::string title);
    Q_INVOKABLE void createButton();
    Q_INVOKABLE void createEdit();
    Q_INVOKABLE void createLabel();
    Q_INVOKABLE void createCheckbox();
    Q_INVOKABLE void createRadiobutton();
    Q_INVOKABLE void LoadQml(const QString &file);
    // Button, Edit, Label, Checkbox, Radiobutton, Combobox

private:
    QList<QWidget*> elements;
    QWidget *mainWindow;

};
#endif // UI_H
