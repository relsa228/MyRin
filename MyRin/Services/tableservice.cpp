#include "tableservice.h"

void TableService::setTable(QTableWidget *newTable)
{
    table = newTable;
}

TableService::TableService(QTableWidget *newTable)
{
    setTable(newTable);
}

void TableService::AddPersonToTable(Person person, int row)
{
    QTableWidgetItem *firstName = new QTableWidgetItem(QObject::tr("%1").arg(person.getFirstName()));
    table->setItem(row, 0, firstName);
    table->item(row, 0)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *surname = new QTableWidgetItem(QObject::tr("%1").arg(person.getSurname()));
    table->setItem(row, 1, surname);
    table->item(row, 1)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *patronymic = new QTableWidgetItem(QObject::tr("%1").arg(person.getPatronymic()));
    table->setItem(row, 2, patronymic);
    table->item(row, 2)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *email = new QTableWidgetItem(QObject::tr("%1").arg(person.getEmail()));
    table->setItem(row, 3, email);
    table->item(row, 3)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *telephone = new QTableWidgetItem(QObject::tr("%1").arg(person.getTelephone()));
    table->setItem(row, 4, telephone);
    table->item(row, 4)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *internalTelephone = new QTableWidgetItem(QObject::tr("%1").arg(person.getInternalTelephone()));
    table->setItem(row, 5, internalTelephone);
    table->item(row, 5)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *cityTelephone = new QTableWidgetItem(QObject::tr("%1").arg(person.getCityTelephone()));
    table->setItem(row, 6, cityTelephone);
    table->item(row, 6)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *telegram = new QTableWidgetItem(QObject::tr("%1").arg(person.getTelegram()));
    table->setItem(row, 7, telegram);
    table->item(row, 7)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *description = new QTableWidgetItem(QObject::tr("%1").arg(person.getDescription()));
    table->setItem(row, 8, description);
    table->item(row, 8)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);
}

void TableService::AddVectorOfPersonsToTable(QVector<Person> *persons)
{
    table->setRowCount(persons->count());
    for(int row = 0; row < persons->count(); row++)
        AddPersonToTable(persons->at(row), row);
}

Person TableService::GetPersonFromTable(int row)
{
    Person tempPerson("", "", "", "", "", "", "", "", "");
    tempPerson.setFirstName(table->item(row, 0)->text());
    tempPerson.setSurname(table->item(row, 1)->text());
    tempPerson.setPatronymic(table->item(row, 2)->text());
    tempPerson.setEmail(table->item(row, 3)->text());
    tempPerson.setTelephone(table->item(row, 4)->text());
    tempPerson.setInternalTelephone(table->item(row, 5)->text());
    tempPerson.setCityTelephone(table->item(row, 6)->text());
    tempPerson.setTelegram(table->item(row, 7)->text());
    tempPerson.setDescription(table->item(row, 8)->text());

    return tempPerson;
}

QVector<Person> *TableService::GetAllPersons()
{
    QVector<Person>* resultVector = new QVector<Person>();
    for(int row = 0; row < table->rowCount(); row++)
        resultVector->push_back(GetPersonFromTable(row));

    return resultVector;
}
