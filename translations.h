#ifndef TRANSLATIONS_H
#define TRANSLATIONS_H

#include <QObject>
#include <QString>

class Translations : public QObject {
    Q_OBJECT
public:
    Translations();
    QString translate(const QString &context, const QString &sourceText);
    QString tr(const QString &context, const QString &sourceText);
};

#endif // TRANSLATIONS_H
