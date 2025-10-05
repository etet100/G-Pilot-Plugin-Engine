#ifndef UI_H
#define UI_H

#include <QObject>

class UI : public QObject {
    Q_OBJECT
public:
    UI();
    // createWindow()
    Q_INVOKABLE void createButton();
    Q_INVOKABLE void createEdit();
    Q_INVOKABLE void createLabel();
    Q_INVOKABLE void createCheckbox();
    Q_INVOKABLE void createRadiobutton();
    Q_INVOKABLE void LoadQml(const QString &file);
    // Button, Edit, Label, Checkbox, Radiobutton, Combobox
};
#endif // UI_H
