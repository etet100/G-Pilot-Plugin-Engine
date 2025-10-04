// This file is a part of "G-Pilot (formerly Candle)" application.
// Copyright 2015-2021 Hayrullin Denis Ravilevich
// Copyright 2025 BTS

#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>

class Settings : public QObject {
    Q_OBJECT
public:
    Settings();
    Q_INVOKABLE void set(const QString ns, const QString &key, const QString &value);
    Q_INVOKABLE QString get(const QString ns, const QString &key, const QString &defaultValue = "");
};

#endif // SETTINGS_H
