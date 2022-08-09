#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <QVector>
#include <QFile>
#include <QXmlStreamReader>
#include <QDomDocument>
#include <QTextStream>

#include "Entities/person.h"

class XmlParser
{
public:
    XmlParser();

    QVector<Person>* parseFile(const QString &fileName);
    void parseTable(const QVector<Person>, const QString &fileName);
};

#endif // XMLPARSER_H
