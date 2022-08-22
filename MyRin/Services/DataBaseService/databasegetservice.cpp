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

long DataBaseGetService::getIdByRow(int row)
{
    QVector<PersonModel> *fetchFromDataBase = new QVector<PersonModel>();
    qx::dao::fetch_all(fetchFromDataBase);

    if(!fetchFromDataBase->isEmpty())
        return fetchFromDataBase->at(0).id + row;

    else return 0;
}
