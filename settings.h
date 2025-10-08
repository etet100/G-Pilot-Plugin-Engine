// This file is a part of "G-Pilot (formerly Candle)" application.
// Copyright 2015-2021 Hayrullin Denis Ravilevich
// Copyright 2025 BTS

#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include "export.h"

class PLUGINENGINE_EXPORT Settings : public QObject {
    Q_OBJECT
public:
    Settings();
    Q_INVOKABLE void set(const QString ns, const QString &key, const QString &value);
    Q_INVOKABLE QString get(const QString ns, const QString &key, const QString &defaultValue = "");
};

class PLUGINENGINE_EXPORT PluginSettings : public Settings {
    Q_OBJECT
public:
    PluginSettings(const QString ns);
    Q_INVOKABLE void set(const QString &key, const QString &value);
    Q_INVOKABLE QString get(const QString &key, const QString &defaultValue = "");
private:
    const QString ns;
};

#endif // SETTINGS_H
