#ifndef INPUT_H
#define INPUT_H

#include <QObject>
#include <QJSEngine>
#include "export.h"

class PLUGINENGINE_EXPORT Input : public QObject {
    Q_OBJECT
public:
    // form elements, return field id
    Q_INVOKABLE int createForm();
    Q_INVOKABLE int createTextField(int form, QString name, QString value = "");
    Q_INVOKABLE int createNumberField(int form, QString name, int value = 0);
    Q_INVOKABLE int createSizeField(int form, QString name);
    Q_INVOKABLE int createCheckboxField(int form, QString name);
    Q_INVOKABLE int createComboboxField(int form, QString name, QStringList options);
    Q_INVOKABLE int createMultiField(int form, QString name, QStringList options);
    Q_INVOKABLE int crateGroup();

    // getters
    Q_INVOKABLE QVariant getValue(int form, int fieldId);
    Q_INVOKABLE int getInt(int form, int fieldId);
    Q_INVOKABLE double getDouble(int form, int fieldId);
    Q_INVOKABLE QString getString(int form, int fieldId);
    Q_INVOKABLE QStringList getStringList(int form, int fieldId);
    Q_INVOKABLE bool getBool(int form, int fieldId);

    // methods
    Q_INVOKABLE void show(int form);
    Q_INVOKABLE void enable(int fieldId);
    Q_INVOKABLE void disable(int fieldId);

    // callbacks
    Q_INVOKABLE bool onValidate(int form, QJSValue callback);
    Q_INVOKABLE bool onSubmit(int form, QJSValue callback);
    Q_INVOKABLE bool onCancel(int form, QJSValue callback);
};

#endif // INPUT_H
