#include "databasegetservice.h"

DataBaseGetService::DataBaseGetService()
{

}

QVector<PersonModel>* DataBaseGetService::getAll()
{
    QVector<PersonModel> *fetchFromDataBase = new QVector<PersonModel>();
    qx::dao::fetch_all(fetchFromDataBase);

    return fetchFromDataBase;
}
