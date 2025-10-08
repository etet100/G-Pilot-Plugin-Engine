#ifndef PROGRAM_H
#define PROGRAM_H

#include <QObject>
#include <QPoint>
#include "export.h"

class PLUGINENGINE_EXPORT Program : public QObject {
    Q_OBJECT
public:
    Program();
    Q_INVOKABLE int load(QString file);
    Q_INVOKABLE int loadString(QString str);
    Q_INVOKABLE QString path();
    Q_INVOKABLE bool isLoaded();
    // current `
    Q_INVOKABLE QPoint lowerBounds();
    Q_INVOKABLE QPoint upperBounds();
    Q_INVOKABLE int lineCount();
    Q_INVOKABLE QString lineAt(int index);
    Q_INVOKABLE void close();
    Q_INVOKABLE void save(QString file);

    // events
    // onLoaded
    // onClosed
    // onSaved
    // "G1X" + app.program.lowerBounds.x() + "Y" + app.program.lowerBounds.y(),
    //     "G1Y" + app.program.upperBounds.y(),
    //     "G1X" + app.program.upperBounds.x(),
    //     "G1Y" + app.program.lowerBounds.y(),
    //     "G1X" + app.program.lowerBounds.x(),
    };

#endif // PROGRAM_H
