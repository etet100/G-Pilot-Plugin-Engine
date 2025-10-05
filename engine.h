
#ifndef ENGINE_H
#define ENGINE_H

#include <QJSEngine>
#include "apis.h"

class Engine
{
public:
    Engine();
    bool execute(const QString &script);

    App &app() { return app_; }
    Console &console() { return console_; }
    MessageBox &msgBox() { return msgBox_; }
    Settings &settings() { return settings_; }
    Translations &translations() { return translations_; }
    Device &device() { return device_; }
    Input &input() { return input_; }
    Jogging &jogging() { return jogging_; }
    Visualizer &visualizer() { return visualizer_; }

private:
    QJSEngine engine;
    App app_;
    Console console_;
    MessageBox msgBox_;
    Settings settings_;
    Translations translations_;
    Device device_;
    Input input_;
    Jogging jogging_;
    Visualizer visualizer_;
};

#endif // ENGINE_H

