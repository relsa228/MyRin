#ifndef DELETEDIALOG_H
#define DELETEDIALOG_H

#include <QDialog>

#include <Services/DataBaseService/databasepushservice.h>
#include <Services/tableservice.h>

#include <Parsers/configworker.h>

namespace Ui {
class DeleteDialog;
}

class DeleteDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteDialog(DataBasePushService* inputPush, TableService* inputTable, ConfigWorker* inputWorker, int row, QWidget *parent = nullptr);
    ~DeleteDialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::DeleteDialog *ui;

    ConfigWorker* currentWorker;

    DataBasePushService* dbPush;
    TableService* tableService;

    int row;
};

#endif // DELETEDIALOG_H
