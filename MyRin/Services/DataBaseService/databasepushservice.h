#ifndef DATABASEPUSHSERVICE_H
#define DATABASEPUSHSERVICE_H

#include <QxOrm.h>
#include <QVector>

#include "Models/personmodel.h"

#include "Parsers/xmlparser.h"

#include "Services/tableservice.h"

class DataBasePushService
{
private:
    XmlParser *xmlParser;

public:
    DataBasePushService();

    QVector<int> pushVectorOfPersons(QVector<PersonModel> *persons, TableService *tableService);
    int pushSinglePerson(PersonModel person, TableService *tableService);

    QSqlError addFromXmlFile(QString fileName, TableService *tableService);
    QSqlError updateFromXmlFile(QString fileName, TableService *tableService);

    QSqlError updatePersonInfo(PersonModel person, TableService *tableService, int row);
    QSqlError deletePerson(TableService *tableService, int row);
};

#endif // DATABASEPUSHSERVICE_H
