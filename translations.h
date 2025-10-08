#ifndef TRANSLATIONS_H
#define TRANSLATIONS_H

#include <QObject>
#include <QString>

#if defined(PLUGINENGINE_LIBRARY)
#define PLUGINENGINE_EXPORT Q_DECL_EXPORT
#else
#define PLUGINENGINE_EXPORT Q_DECL_IMPORT
#endif

class PLUGINENGINE_EXPORT Translations : public QObject {
    Q_OBJECT
public:
    Translations();
    QString translate(const QString &context, const QString &sourceText);
    QString tr(const QString &context, const QString &sourceText);
};

#endif // TRANSLATIONS_H
