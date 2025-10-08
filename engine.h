
#ifndef ENGINE_H
#define ENGINE_H

#include "apis.h"
#include "export.h"

class PLUGINENGINE_EXPORT Engine
{
public:
    Engine(QWidget *mainWindow);
    virtual bool execute(const QString &script) = 0;
    // Check if the script is supported by this engine, by keywords
    // It is not a full proof way, but a simple heuristic!
    // I'm going to add some metadata (like @engine js) in the future
    virtual bool supported(const QString &script) = 0;

    App &app() { return app_; }
    Console &console() { return console_; }
    MsgBox &msgBox() { return msgBox_; }
    Settings &settings() { return settings_; }
    Translations &translations() { return translations_; }
    Device &device() { return device_; }
    Input &input() { return input_; }
    Jogging &jogging() { return jogging_; }
    Visualizer &visualizer() { return visualizer_; }
    UI &ui() { return ui_; }

protected:
    App app_;
    Console console_;
    MsgBox msgBox_;
    Settings settings_;
    Translations translations_;
    Device device_;
    Input input_;
    Jogging jogging_;
    Visualizer visualizer_;
    UI ui_;
    QWidget *mainWindow;
    virtual void init() = 0;
};

#endif // ENGINE_H

