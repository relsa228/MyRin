#include "redactpersonview.h"
#include "ui_redactpersonview.h"

RedactPersonView::RedactPersonView(int row, PersonModel personModel, TableService *tableService, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RedactPersonView)
{
    ui->setupUi(this);

    workingRow = row;
    model = personModel;
    workTableService = tableService;

    ui->nameEdit->setText(personModel.FirstName);
    ui->snameEdit->setText(personModel.Surname);
    ui->pnameEdit->setText(personModel.Patronymic);

    ui->telephoneEdit->setText(personModel.Telephone);
    ui->iTelephoneEdit->setText(personModel.InternalTelephone);
    ui->cTelephoneEdit->setText(personModel.CityTelephone);

    ui->emailEdit->setText(personModel.Email);
    ui->telegramEdit->setText(personModel.Telegram);
    ui->descrEdit->setText(personModel.Description);
}

RedactPersonView::~RedactPersonView()
{
    delete ui;
}

void RedactPersonView::on_acceptButton_clicked()
{
    model.FirstName = ui->nameEdit->text();
    model.Surname = ui->snameEdit->text();
    model.Patronymic = ui->pnameEdit->text();

    model.Telephone = ui->telephoneEdit->text();
    model.CityTelephone = ui->cTelephoneEdit->text();
    model.InternalTelephone = ui->iTelephoneEdit->text();

    model.Telegram = ui->telegramEdit->text();
    model.Email = ui->emailEdit->text();
    model.Description = ui->descrEdit->toPlainText();

    pushService->updatePersonInfo(model, workTableService, workingRow);

    this->close();
}


void RedactPersonView::on_cancelButton_clicked()
{
    this->close();
}

