#include "engine.h"

Engine::Engine() {
    // UI ui;
    // engine.globalObject().setProperty("ui", engine.newQObject(&ui));
    // engine.globalObject().setProperty("u", engine.newQObject(&ui));

    QJSValue axisEnum = engine.newObject();
    axisEnum.setProperty("X", 0);
    axisEnum.setProperty("Y", 1);
    axisEnum.setProperty("Z", 2);

    engine.globalObject().setProperty("Axis", axisEnum);

    engine.globalObject().setProperty("app", engine.newQObject(&app_));
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

    engine.globalObject().setProperty("jogging", engine.newQObject(&jogging_));

}

bool Engine::execute(const QString &script)
{
    QJSValue err = engine.evaluate(script);
    if (err.isError()) {
        console_.error("JS error:" + err.toString());

        return false;
    }

    return true;
}
