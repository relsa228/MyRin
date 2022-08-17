#ifndef TABLESERVICE_H
#define TABLESERVICE_H

#include <QTableWidget>
#include <QVector>

#include "Entities/person.h"

class TableService
{
private:
    QTableWidget *table;

public:
    TableService(QTableWidget *newTable);

    void AddPersonToTable(Person person, int row);
    void AddVectorOfPersonsToTable(QVector<Person>* vector);

    Person GetPersonFromTable(int row);
    QVector<Person>* GetAllPersons();

    void setTable(QTableWidget *newTable);
};

#endif // TABLESERVICE_H
