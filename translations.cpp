#include "translations.h"

Translations::Translations() {}

QString Translations::translate(const QString &context, const QString &sourceText) {
    return QObject::tr(sourceText.toUtf8().constData(), context.toUtf8().constData());
}

QString Translations::tr(const QString &context, const QString &sourceText) {
    return translate(context, sourceText);
}
