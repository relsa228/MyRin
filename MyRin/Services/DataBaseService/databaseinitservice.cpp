#include "databaseinitservice.h"


DataBaseInitService::DataBaseInitService()
{
    qx::QxSqlDatabase::getSingleton()->setDriverName("QSQLITE");
    qx::QxSqlDatabase::getSingleton()->setDatabaseName("./myRinWB.sqlite");
    qx::QxSqlDatabase::getSingleton()->setHostName("localhost");
    qx::QxSqlDatabase::getSingleton()->setUserName("root");
    qx::QxSqlDatabase::getSingleton()->setPassword("");
    qx::QxSqlDatabase::getSingleton()->setFormatSqlQueryBeforeLogging(true);
    qx::QxSqlDatabase::getSingleton()->setDisplayTimerDetails(true);

    CreateShema();
}

void DataBaseInitService::cleanDataBase()
{
    qx::dao::destroy_all<PersonModel>();
}

void DataBaseInitService::CreateShema()
{
    QSqlError daoError = qx::dao::create_table<PersonModel>();
}
