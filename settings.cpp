#include "settings.h"

#include <QSettings>

Settings::Settings() {}

void Settings::set(const QString ns, const QString &key, const QString &value) {
    QSettings settings;
    settings.setValue(key, value);
}

QString Settings::get(const QString ns, const QString &key, const QString &defaultValue) {
    QSettings settings;

    return settings.value(key, defaultValue).toString();
}
