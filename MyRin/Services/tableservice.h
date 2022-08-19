#ifndef TABLESERVICE_H
#define TABLESERVICE_H

#include <QTableWidget>
#include <QVector>

#include "Models/personmodel.h"

class TableService
{
private:
    QTableWidget *table;

public:
    TableService(QTableWidget *newTable);

    void AddPersonToTable(PersonModel person, int row);
    void AddVectorOfPersonsToTable(QVector<PersonModel>* vector);

    PersonModel GetPersonFromTable(int row);
    QVector<PersonModel>* GetAllPersons();

    void setTable(QTableWidget *newTable);
};

#endif // TABLESERVICE_H
