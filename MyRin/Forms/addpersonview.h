#ifndef ADDPERSONVIEW_H
#define ADDPERSONVIEW_H

#include <QDialog>

#include "Models/personmodel.h"

#include "Services/DataBaseService/databasepushservice.h"
#include "Services/tableservice.h"

namespace Ui {
class AddPersonView;
}

class AddPersonView : public QDialog
{
    Q_OBJECT

public:
    explicit AddPersonView(TableService *newTableService, QWidget *parent = nullptr);
    ~AddPersonView();

private slots:
    void on_acceptButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::AddPersonView *ui;
    TableService* tableService;
};

#endif // ADDPERSONVIEW_H
