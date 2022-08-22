#ifndef REDACTPERSONVIEW_H
#define REDACTPERSONVIEW_H

#include <QDialog>

#include "Models/personmodel.h"

#include "Services/DataBaseService/databasegetservice.h"
#include "Services/DataBaseService/databasepushservice.h"
#include "Services/tableservice.h"
#include "Services/MessagesService/errormessage.h"
#include "Services/MessagesService/infomessage.h"

namespace Ui {
class RedactPersonView;
}

class RedactPersonView : public QDialog
{
    Q_OBJECT

public:
    explicit RedactPersonView(int row, PersonModel personModel, TableService *tableService, QWidget *parent = nullptr);
    ~RedactPersonView();

private slots:
    void on_acceptButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::RedactPersonView *ui;
    PersonModel model;
    DataBaseGetService *getService;
    DataBasePushService *pushService;
    TableService *workTableService;
    int workingRow;
};

#endif // REDACTPERSONVIEW_H
