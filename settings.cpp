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

PluginSettings::PluginSettings(const QString ns) : Settings(), ns(ns)
{
    
}

void PluginSettings::set(const QString &key, const QString &value)
{
    return Settings::set(ns, key, value);
}

QString PluginSettings::get(const QString &key, const QString &defaultValue)
{
    return Settings::get(ns, key, defaultValue);
}
