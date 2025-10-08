#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <QObject>

#if defined(PLUGINENGINE_LIBRARY)
#define PLUGINENGINE_EXPORT Q_DECL_EXPORT
#else
#define PLUGINENGINE_EXPORT Q_DECL_IMPORT
#endif

class PLUGINENGINE_EXPORT Visualizer : public QObject {
    Q_OBJECT
public:
    Visualizer();
};

#endif // VISUALIZER_H
