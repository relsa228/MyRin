#include "deletedialog.h"
#include "ui_deletedialog.h"

DeleteDialog::DeleteDialog(DataBasePushService* inputPush, TableService* inputTable, ConfigWorker* inputWorker, int row, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteDialog)
{
    currentWorker = inputWorker;
    dbPush = inputPush;
    tableService = inputTable;

    this->row = row;

    ui->setupUi(this);
}

DeleteDialog::~DeleteDialog()
{
    delete ui;
}

void DeleteDialog::on_buttonBox_accepted()
{
    if(ui->ConfigCheck->isChecked())
        currentWorker->config["DeletePersoneAprove"] = 0;

    dbPush->deletePerson(tableService, row);
    this->close();
}


void DeleteDialog::on_buttonBox_rejected()
{
    if(ui->ConfigCheck->isChecked())
        currentWorker->config["DeletePersoneAprove"] = 0;
    this->close();
}

