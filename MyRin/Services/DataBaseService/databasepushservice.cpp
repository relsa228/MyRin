#include "databasepushservice.h"

DataBasePushService::DataBasePushService()
{
    xmlParser = new XmlParser();
}

QSqlError DataBasePushService::pushVectorOfPersons(QVector<PersonModel> *persons)
{
    QSqlError daoError = qx::dao::insert(persons);

    return daoError;
}

QSqlError DataBasePushService::pushSinglePerson(PersonModel person)
{
    QSqlError daoError = qx::dao::insert(person);

    return daoError;
}

QSqlError DataBasePushService::addFromXmlFile(QString fileName)
{
    QVector<PersonModel>* transferVector;
    transferVector = xmlParser->parseFile(fileName);

    QSqlError daoError = qx::dao::insert(transferVector);

    return daoError;
}

QSqlError DataBasePushService::updateFromXmlFile(QString fileName)
{
    qx::dao::delete_all<PersonModel>();
    return addFromXmlFile(fileName);
}
