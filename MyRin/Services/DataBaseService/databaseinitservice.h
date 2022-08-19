#ifndef DATABASEINITSERVICE_H
#define DATABASEINITSERVICE_H

#include <QxOrm.h>
#include <QVector>

#include "Models/personmodel.h"

class DataBaseInitService
{
public:
    DataBaseInitService();
    void cleanDataBase();

private:
    void CreateShema();
};

#endif // DATABASEINITSERVICE_H
