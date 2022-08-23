#ifndef DATABASEGETSERVICE_H
#define DATABASEGETSERVICE_H

#include <QxOrm.h>
#include <QVector>

#include "Models/personmodel.h"

class DataBaseGetService
{
public:
    DataBaseGetService();

    QVector<PersonModel>* getAll();
};

#endif // DATABASEGETSERVICE_H
