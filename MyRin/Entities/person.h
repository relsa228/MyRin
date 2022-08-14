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
    QString Telegram;

    QString Description;

public:
    Person(QString firstName, QString surname, QString patronymic, QString email, QString telephone, QString telegram, QString description);

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

    const QString &getTelegram() const;
    void setTelegram(const QString &newSelfId);

    const QString &getDescription() const;
    void setDescription(const QString &newDescription);
};

#endif // PERSON_H
