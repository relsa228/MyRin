#include "person.h"

const QString &Person::getFirstName() const
{
    return FirstName;
}

void Person::setFirstName(const QString &newFirstName)
{
    FirstName = newFirstName;
}

const QString &Person::getSurname() const
{
    return Surname;
}

void Person::setSurname(const QString &newSurname)
{
    Surname = newSurname;
}

const QString &Person::getPatronymic() const
{
    return Patronymic;
}

void Person::setPatronymic(const QString &newPatronymic)
{
    Patronymic = newPatronymic;
}

const QString &Person::getEmail() const
{
    return Email;
}

void Person::setEmail(const QString &newEmail)
{
    Email = newEmail;
}

const QString &Person::getTelephone() const
{
    return Telephone;
}

void Person::setTelephone(const QString &newTelephone)
{
    Telephone = newTelephone;
}

const QString &Person::getTelegram() const
{
    return Telegram;
}

void Person::setTelegram(const QString &newSelfId)
{
    Telegram = newSelfId;
}

const QString &Person::getDescription() const
{
    return Description;
}

void Person::setDescription(const QString &newDescription)
{
    Description = newDescription;
}

const QString &Person::getInternalTelephone() const
{
    return InternalTelephone;
}

void Person::setInternalTelephone(const QString &newInternalTelephone)
{
    InternalTelephone = newInternalTelephone;
}

const QString &Person::getCityTelephone() const
{
    return CityTelephone;
}

void Person::setCityTelephone(const QString &newCityTelephone)
{
    CityTelephone = newCityTelephone;
}

Person::Person(QString firstName, QString surname, QString patronymic, QString email,
               QString telephone, QString internalTelephone, QString cityTelephone, QString telegram, QString description)
{
    FirstName = firstName;
    Surname = surname;
    Patronymic = patronymic;
    Email = email;
    Telephone = telephone;
    InternalTelephone = internalTelephone;
    CityTelephone = cityTelephone;
    Telegram = telegram;
    Description = description;
}
