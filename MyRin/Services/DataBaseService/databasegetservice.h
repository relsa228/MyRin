#ifndef DATABASEGETSERVICE_H
#define DATABASEGETSERVICE_H

#include <QxOrm.h>
#include <QVector>
#include <QStringList>

#include "Models/personmodel.h"

class DataBaseGetService
{
public:
    DataBaseGetService();

    QVector<PersonModel>* getAll();
    QVector<PersonModel>* getByFilters(QStringList listOfFilters);
};

#endif // DATABASEGETSERVICE_H
