#ifndef DATABASEINITSERVICE_H
#define DATABASEINITSERVICE_H

#include <QtSql>
#include <QxOrm.h>
#include <QVector>

#include "Models/personmodel.h"

class DataBaseInitService
{
private:
    QSqlDatabase dataBase;

public:
    DataBaseInitService();
    const QSqlDatabase &getDataBase() const;

private:
    void CreateShema();
};

#endif // DATABASEINITSERVICE_H
