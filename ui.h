#ifndef UI_H
#define UI_H

#include <QObject>

class UI : public QObject {
    Q_OBJECT
public:
    UI();
    // createWindow()
    Q_INVOKABLE void CreateButton();
    Q_INVOKABLE void CreateEdit();
    Q_INVOKABLE void CreateLabel();
    Q_INVOKABLE void CreateCheckbox();
    Q_INVOKABLE void CreateRadiobutton();
    Q_INVOKABLE void LoadQml(const QString &file);
    // Button, Edit, Label, Checkbox, Radiobutton, Combobox
};
#endif // UI_H
