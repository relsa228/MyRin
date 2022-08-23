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

QVector<PersonModel> *DataBaseGetService::getByFilters(QStringList listOfFilter)
{
    qx_query personsFilter;
    personsFilter.where("id").isGreaterThan(-1);
    if(!listOfFilter.at(0).isEmpty())
        personsFilter.and_("FirstName").isEqualTo(listOfFilter.at(0));
    if(!listOfFilter.at(1).isEmpty())
        personsFilter.and_("Surname").isEqualTo(listOfFilter.at(1));
    if(!listOfFilter.at(2).isEmpty())
        personsFilter.and_("Patronymic").isEqualTo(listOfFilter.at(2));

    if(!listOfFilter.at(3).isEmpty())
        personsFilter.and_("Telephone").isEqualTo(listOfFilter.at(3));
    if(!listOfFilter.at(4).isEmpty())
        personsFilter.and_("InternalTelephone").isEqualTo(listOfFilter.at(4));
    if(!listOfFilter.at(5).isEmpty())
        personsFilter.and_("CityTelephone").isEqualTo(listOfFilter.at(5));

    if(!listOfFilter.at(6).isEmpty())
        personsFilter.and_("Email").isEqualTo(listOfFilter.at(6));
    if(!listOfFilter.at(7).isEmpty())
        personsFilter.and_("Telegram").isEqualTo(listOfFilter.at(7));
    if(!listOfFilter.at(8).isEmpty())
        personsFilter.and_("Description").isEqualTo(listOfFilter.at(8));

    QVector<PersonModel> *result = new QVector<PersonModel>();
    QSqlError daoError = qx::dao::fetch_by_query(personsFilter, result);

    return result;
}
