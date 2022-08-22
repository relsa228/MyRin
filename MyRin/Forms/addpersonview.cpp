#include "addpersonview.h"
#include "ui_addpersonview.h"

AddPersonView::AddPersonView(TableService *newTableService, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPersonView)
{
    tableService = newTableService;
    ui->setupUi(this);
}

AddPersonView::~AddPersonView()
{
    delete ui;
}

void AddPersonView::on_acceptButton_clicked()
{
    PersonModel model = PersonModel();
    DataBasePushService *dataBasePush = new DataBasePushService();

    model.FirstName = ui->nameEdit->text();
    model.Surname = ui->snameEdit->text();
    model.Patronymic = ui->pnameEdit->text();

    model.Telephone = ui->telephoneEdit->text();
    model.CityTelephone = ui->cTelephoneEdit->text();
    model.InternalTelephone = ui->iTelephoneEdit->text();

    model.Telegram = ui->telegramEdit->text();
    model.Email = ui->emailEdit->text();
    model.Description = ui->descrEdit->toPlainText();

    QSqlError error = dataBasePush->pushSinglePerson(model);
    if(!error.isValid())
    {
        tableService->AddPersonToTable(model, qx::dao::count<PersonModel>() - 1);
        InfoMessage("Запись успешно добавлена");
    }
    else ErrorMessage("Произошла ошибка");

    this->close();
}


void AddPersonView::on_cancelButton_clicked()
{
    this->close();
}

