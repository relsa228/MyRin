#ifndef PERSON_H
#define PERSON_H

#include <QString>

class Person
{
private:
    QString FirstName;
    QString Surname;
    QString Patronymic;

    QString Email;
    QString Telephone;
    QString SelfId;

public:
    Person(QString firstName, QString surname, QString patronymic, QString email, QString telephone, QString selfId);

    const QString &getFirstName() const;
    void setFirstName(const QString &newFirstName);

    const QString &getSurname() const;
    void setSurname(const QString &newSurname);

    const QString &getPatronymic() const;
    void setPatronymic(const QString &newPatronymic);

    const QString &getEmail() const;
    void setEmail(const QString &newEmail);

    const QString &getTelephone() const;
    void setTelephone(const QString &newTelephone);

    const QString &getSelfId() const;
    void setSelfId(const QString &newSelfId);
};

#endif // PERSON_H
