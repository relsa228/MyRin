#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <QVector>
#include <QFile>
#include <QXmlStreamReader>
#include <QDomDocument>
#include <QTextStream>

#include "Models/personmodel.h"

class XmlParser
{
public:
    XmlParser();

    QVector<PersonModel>* parseFile(const QString &fileName);
    void parseTable(const QVector<PersonModel>, const QString &fileName);
};

#endif // XMLPARSER_H
