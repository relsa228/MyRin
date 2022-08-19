#ifndef DATABASEPUSHSERVICE_H
#define DATABASEPUSHSERVICE_H

#include <QxOrm.h>
#include <QVector>

#include "Models/personmodel.h"

#include "Parsers/xmlparser.h"

class DataBasePushService
{
private:
    XmlParser *xmlParser;

public:
    DataBasePushService();

    QSqlError pushVectorOfPersons(QVector<PersonModel> *persons);
    QSqlError pushSinglePerson(PersonModel person);

    QSqlError addFromXmlFile(QString fileName);
    QSqlError updateFromXmlFile(QString fileName);
};

#endif // DATABASEPUSHSERVICE_H
