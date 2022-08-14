#ifndef FILTER_H
#define FILTER_H

#include <QVector>

#include "Entities/person.h"

class Filter
{
public:
    Filter();

    QVector<Person>* filterContent(QVector<Person> persons,
                                  const QString firstName, const QString surname,
                                  const QString patronymic, const QString email,
                                  const QString telephone, const QString telegram);

private:
    bool filterFirstName(const Person person, const QString firstName);
    bool filterSurname(const Person person, const QString surname);
    bool filterPatronymic(const Person person, const QString patronymic);
    bool filterEmail(const Person person, const QString email);
    bool filterTelephone(const Person person, const QString telephone);
    bool filterTelegram(const Person person, const QString telegram);
};

#endif // FILTER_H
