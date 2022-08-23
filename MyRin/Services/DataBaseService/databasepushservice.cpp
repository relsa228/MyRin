#include "databasepushservice.h"

DataBasePushService::DataBasePushService()
{
    xmlParser = new XmlParser();
}

QVector<int> DataBasePushService::pushVectorOfPersons(QVector<PersonModel> *persons, TableService *tableService)
{
    QVector<int> index = QVector<int>();
    foreach(PersonModel person, *persons)
        index.push_back(pushSinglePerson(person, tableService));

    return index;
}

int DataBasePushService::pushSinglePerson(PersonModel person, TableService *tableService)
{
    QSqlError daoError = qx::dao::insert(person);

    if(daoError.isValid())
        return -1;

    tableService->AddPersonToTable(person, qx::dao::count<PersonModel>() - 1);
    return person.id;
}

QSqlError DataBasePushService::addFromXmlFile(QString fileName, TableService *tableService)
{
    QVector<PersonModel>* transferVector;
    transferVector = xmlParser->parseFile(fileName);

    QSqlError daoError = qx::dao::insert(transferVector);

    tableService->UpdateFromDataBase();

    return daoError;
}

QSqlError DataBasePushService::updateFromXmlFile(QString fileName, TableService *tableService)
{
    qx::dao::delete_all<PersonModel>();

    return addFromXmlFile(fileName, tableService);
}

QSqlError DataBasePushService::updatePersonInfo(PersonModel person, TableService *tableService, int row)
{
    person.id = tableService->GetIdByRow(row);
    QSqlError daoError = qx::dao::update(person);
    tableService->UpdatePerson(row, person);

    return daoError;
}

QSqlError DataBasePushService::deletePerson(TableService *tableService, int row)
{
    PersonModel idModel = PersonModel();
    idModel.id = tableService->GetIdByRow(row);
    QSqlError daoError = qx::dao::delete_by_id(idModel);

    tableService->UpdateFromDataBase();
    return daoError;
}
