// This file is a part of "G-Pilot (formerly Candle)" application.
// Copyright 2015-2021 Hayrullin Denis Ravilevich
// Copyright 2025 BTS

#include "js.h"

Js::Js(QMainWindow *mainWindow) : Engine(mainWindow)
{
    init();
}

bool Js::execute(const QString &script)
{
    QJSValue err = engine.evaluate(script);
    if (err.isError()) {
        console_.error("JS error:" + err.toString());

        return false;
    }

    return true;
}

bool Js::supported(const QString &script)
{
    int score = 0;

    if (script.contains("//")) score += 4;
    if (script.contains(QRegularExpression("\\b(const|let|var)\\b"))) score += 5;
    if (script.contains("=>")) score += 6;
    if (script.contains(QRegularExpression("\\b(undefined|null)\\b"))) score += 3;
    if (script.contains("console.log")) score += 4;
    score += script.count('{') + script.count('}') + script.count(';');

    return score > 3;
}

void Js::init()
{
    QJSValue axisEnum = engine.newObject();
    axisEnum.setProperty("X", 0);
    axisEnum.setProperty("Y", 1);
    axisEnum.setProperty("Z", 2);

    engine.globalObject().setProperty("Axis", axisEnum);

    engine.globalObject().setProperty("a pp", engine.newQObject(&app_));
    engine.globalObject().setProperty("a", engine.newQObject(&app_));

    engine.globalObject().setProperty("console", engine.newQObject(&console_));
    engine.globalObject().setProperty("c", engine.newQObject(&console_));

    engine.globalObject().setProperty("msgBox", engine.newQObject(&msgBox_));
    engine.globalObject().setProperty("m", engine.newQObject(&msgBox_));

    engine.globalObject().setProperty("settings", engine.newQObject(&settings_));
    engine.globalObject().setProperty("s", engine.newQObject(&settings_));

    engine.globalObject().setProperty("translations", engine.newQObject(&translations_));
    engine.globalObject().setProperty("t", engine.newQObject(&translations_));

    engine.globalObject().setProperty("device", engine.newQObject(&device_));
    engine.globalObject().setProperty("d", engine.newQObject(&device_));

    engine.globalObject().setProperty("input", engine.newQObject(&input_));
    engine.globalObject().setProperty("i", engine.newQObject(&input_));

    engine.globalObject().setProperty("ui", engine.newQObject(&ui_));
    engine.globalObject().setProperty("u", engine.newQObject(&ui_));

    engine.globalObject().setProperty("jogging", engine.newQObject(&jogging_));

}
