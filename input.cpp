#include "input.h"

int Input::createForm() {}

int Input::createTextField(int form, QString name, QString value) {}

int Input::createNumberField(int form, QString name, int value) {}

int Input::createSizeField(int form, QString name) {}

int Input::createCheckboxField(int form, QString name) {}

int Input::createComboboxField(int form, QString name, QStringList options) {}

int Input::createMultiField(int form, QString name, QStringList options) {}

int Input::crateGroup() {}

QVariant Input::getValue(int form, int fieldId) {}

int Input::getInt(int form, int fieldId) {}

double Input::getDouble(int form, int fieldId) {}

QString Input::getString(int form, int fieldId) {}

QStringList Input::getStringList(int form, int fieldId) {}

bool Input::getBool(int form, int fieldId) {}

void Input::show(int form) {}

void Input::enable(int fieldId)
{

}

void Input::disable(int fieldId)
{

}

bool Input::onValidate(int form, QJSValue callback) {}

bool Input::onSubmit(int form, QJSValue callback) {}

bool Input::onCancel(int form, QJSValue callback) {}
