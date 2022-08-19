#include "databaseinitservice.h"

const QSqlDatabase &DataBaseInitService::getDataBase() const
{
    return dataBase;
}

DataBaseInitService::DataBaseInitService()
{
    qx::QxSqlDatabase::getSingleton()->setDriverName("QSQLITE");
    qx::QxSqlDatabase::getSingleton()->setDatabaseName("./myRinWB.sqlite");
    qx::QxSqlDatabase::getSingleton()->setHostName("localhost");
    qx::QxSqlDatabase::getSingleton()->setUserName("root");
    qx::QxSqlDatabase::getSingleton()->setPassword("");
    qx::QxSqlDatabase::getSingleton()->setFormatSqlQueryBeforeLogging(true);
    qx::QxSqlDatabase::getSingleton()->setDisplayTimerDetails(true);

    QSqlError daoError = qx::dao::create_table<PersonModel>();
}

void DataBaseInitService::CreateShema()
{

}
