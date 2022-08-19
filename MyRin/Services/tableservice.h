#ifndef TABLESERVICE_H
#define TABLESERVICE_H

#include <QTableWidget>
#include <QVector>
#include <QxOrm.h>

#include "Models/personmodel.h"

#include "Services/DataBaseService/databasegetservice.h"

class TableService
{
private:
    QTableWidget *table;
    DataBaseGetService *dataBaseGet;

public:
    TableService(QTableWidget *newTable);

    void AddPersonToTable(PersonModel person, int row);
    void AddVectorOfPersonsToTable(QVector<PersonModel>* vector);

    void AddFromDataBase();
    void UpdateFromDataBase();

    PersonModel GetPersonFromTable(int row);
    QVector<PersonModel>* GetAllPersons();

    void setTable(QTableWidget *newTable);
    void cleanTable();
};

#endif // TABLESERVICE_H
