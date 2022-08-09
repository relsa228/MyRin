#include "addpersonview.h"
#include "ui_addpersonview.h"

AddPersonView::AddPersonView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPersonView)
{
    ui->setupUi(this);
}

AddPersonView::~AddPersonView()
{
    delete ui;
}
