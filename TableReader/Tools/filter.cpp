#include "filter.h"

Filter::Filter()
{

}

QVector<Person>* Filter::filterContent(QVector<Person> persons,
                                      const QString firstName, const QString surname, const QString patronymic,
                                      const QString email, const QString telephone, const QString selfId)
{
    QVector<Person>* resultVector = new QVector<Person>;

    foreach (Person person, persons)
        if(filterFirstName(person, firstName) && filterSurname(person, surname) && filterPatronymic(person, patronymic)
                && filterEmail(person, email) && filterTelephone(person, telephone) && filterSelfId(person, selfId))
            resultVector->push_back(person);

    return resultVector;
}

bool Filter::filterFirstName(const Person person, const QString firstName)
{
    if(firstName.isEmpty() || person.getFirstName() == firstName)
        return true;

    return false;
}

bool Filter::filterSurname(const Person person, const QString surname)
{
    if(surname.isEmpty() || person.getSurname() == surname)
        return true;

    return false;
}

bool Filter::filterPatronymic(const Person person, const QString patronymic)
{
    if(patronymic.isEmpty() || person.getPatronymic() == patronymic)
        return true;

    return false;
}

bool Filter::filterEmail(const Person person, const QString email)
{
    if(email.isEmpty() || person.getEmail() == email)
        return true;

    return false;
}

bool Filter::filterTelephone(const Person person, const QString telephone)
{
    if(telephone.isEmpty() || person.getTelephone() == telephone)
        return true;

    return false;
}

bool Filter::filterSelfId(const Person person, const QString selfId)
{
    if(selfId.isEmpty() || person.getSelfId() == selfId)
        return true;

    return false;
}
