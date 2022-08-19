#ifndef PERSONMODEL_H
#define PERSONMODEL_H

#include <QString>

#include <QxOrm_Impl.h>
#include "export.h"
#include <QxOrm.h>

class MYRIN_DLL_EXPORT PersonModel
{
public:
    long id;

    QString FirstName;
    QString Surname;
    QString Patronymic;

    QString Telephone;
    QString InternalTelephone;
    QString CityTelephone;

    QString Email;
    QString Telegram;

    QString Description;

public:
    PersonModel();
};

QX_REGISTER_HPP_MYRIN(PersonModel, qx::trait::no_base_class_defined, 1)

#endif // PERSONMODEL_H
