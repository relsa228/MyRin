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
    QVector<int> *IndexColumn;

public:
    TableService(QTableWidget *newTable);

    void AddPersonToTable(PersonModel person, int row);
    void AddVectorOfPersonsToTable(QVector<PersonModel>* vector);

    void UpdateFromDataBase();

    PersonModel GetPersonFromTable(int row);
    QVector<PersonModel>* GetAllPersons();
    int GetIdByRow(int row);

    void UpdatePerson(int row, PersonModel personModel);

    void setTable(QTableWidget *newTable);
    void cleanTable();
};

#endif // TABLESERVICE_H
