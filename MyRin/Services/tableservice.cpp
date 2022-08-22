#include "tableservice.h"

TableService::TableService(QTableWidget *newTable)
{
    dataBaseGet = new DataBaseGetService();
    setTable(newTable);
}

void TableService::setTable(QTableWidget *newTable)
{
    table = newTable;
}

void TableService::cleanTable()
{
    table->clear();
    table->setHorizontalHeaderLabels(QStringList()<< "Имя" << "Фамилия" << "Отчество" << "Почта"
                                               << "Телефон" << "Внтр. телефон" << "Гор. телефон" << "Telegram"
                                             << "Дополнительные сведения");
    table->setRowCount(0);
}

void TableService::AddPersonToTable(PersonModel person, int row)
{
    table->setRowCount(row + 1);

    QTableWidgetItem *firstName = new QTableWidgetItem(QObject::tr("%1").arg(person.FirstName));
    table->setItem(row, 0, firstName);
    table->item(row, 0)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *surname = new QTableWidgetItem(QObject::tr("%1").arg(person.Surname));
    table->setItem(row, 1, surname);
    table->item(row, 1)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *patronymic = new QTableWidgetItem(QObject::tr("%1").arg(person.Patronymic));
    table->setItem(row, 2, patronymic);
    table->item(row, 2)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *email = new QTableWidgetItem(QObject::tr("%1").arg(person.Email));
    table->setItem(row, 3, email);
    table->item(row, 3)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *telephone = new QTableWidgetItem(QObject::tr("%1").arg(person.Telephone));
    table->setItem(row, 4, telephone);
    table->item(row, 4)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *internalTelephone = new QTableWidgetItem(QObject::tr("%1").arg(person.InternalTelephone));
    table->setItem(row, 5, internalTelephone);
    table->item(row, 5)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *cityTelephone = new QTableWidgetItem(QObject::tr("%1").arg(person.CityTelephone));
    table->setItem(row, 6, cityTelephone);
    table->item(row, 6)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *telegram = new QTableWidgetItem(QObject::tr("%1").arg(person.Telegram));
    table->setItem(row, 7, telegram);
    table->item(row, 7)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *description = new QTableWidgetItem(QObject::tr("%1").arg(person.Description));
    table->setItem(row, 8, description);
    table->item(row, 8)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);
}

void TableService::AddVectorOfPersonsToTable(QVector<PersonModel> *persons)
{
    foreach (PersonModel model, *persons)
        AddPersonToTable(model, table->rowCount());
}

void TableService::AddFromDataBase()
{
    AddVectorOfPersonsToTable(dataBaseGet->getAll());
}

void TableService::UpdateFromDataBase()
{
    cleanTable();
    AddVectorOfPersonsToTable(dataBaseGet->getAll());
}

PersonModel TableService::GetPersonFromTable(int row)
{
    PersonModel tempPerson;
    tempPerson.FirstName = table->item(row, 0)->text();
    tempPerson.Surname = table->item(row, 1)->text();
    tempPerson.Patronymic = table->item(row, 2)->text();
    tempPerson.Email = table->item(row, 3)->text();
    tempPerson.Telephone = table->item(row, 4)->text();
    tempPerson.InternalTelephone = table->item(row, 5)->text();
    tempPerson.CityTelephone = table->item(row, 6)->text();
    tempPerson.Telegram = table->item(row, 7)->text();
    tempPerson.Description = table->item(row, 8)->text();

    return tempPerson;
}

QVector<PersonModel> *TableService::GetAllPersons()
{
    QVector<PersonModel>* resultVector = new QVector<PersonModel>();
    for(int row = 0; row < table->rowCount(); row++)
        resultVector->push_back(GetPersonFromTable(row));

    return resultVector;
}

void TableService::UpdatePerson(int row, PersonModel personModel)
{
    QTableWidgetItem *firstName = new QTableWidgetItem(QObject::tr("%1").arg(personModel.FirstName));
    table->setItem(row, 0, firstName);
    table->item(row, 0)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *surname = new QTableWidgetItem(QObject::tr("%1").arg(personModel.Surname));
    table->setItem(row, 1, surname);
    table->item(row, 1)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *patronymic = new QTableWidgetItem(QObject::tr("%1").arg(personModel.Patronymic));
    table->setItem(row, 2, patronymic);
    table->item(row, 2)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *email = new QTableWidgetItem(QObject::tr("%1").arg(personModel.Email));
    table->setItem(row, 3, email);
    table->item(row, 3)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *telephone = new QTableWidgetItem(QObject::tr("%1").arg(personModel.Telephone));
    table->setItem(row, 4, telephone);
    table->item(row, 4)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *internalTelephone = new QTableWidgetItem(QObject::tr("%1").arg(personModel.InternalTelephone));
    table->setItem(row, 5, internalTelephone);
    table->item(row, 5)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *cityTelephone = new QTableWidgetItem(QObject::tr("%1").arg(personModel.CityTelephone));
    table->setItem(row, 6, cityTelephone);
    table->item(row, 6)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *telegram = new QTableWidgetItem(QObject::tr("%1").arg(personModel.Telegram));
    table->setItem(row, 7, telegram);
    table->item(row, 7)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem *description = new QTableWidgetItem(QObject::tr("%1").arg(personModel.Description));
    table->setItem(row, 8, description);
    table->item(row, 8)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);
}
