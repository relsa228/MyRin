#ifndef INDEXVIEW_H
#define INDEXVIEW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QVector>

#include "Forms/addpersonview.h"

#include "Parsers/xmlparser.h"

#include "Models/personmodel.h"

#include "Services/MessagesService/errormessage.h"
#include "Services/MessagesService/infomessage.h"
#include "Services/tableservice.h"
#include "Services/DataBaseService/databaseinitservice.h"
#include "Services/DataBaseService/databasepushservice.h"

namespace Ui {
class IndexView;
}

class IndexView : public QMainWindow
{
    Q_OBJECT

public:
    explicit IndexView(QWidget *parent = nullptr);
    ~IndexView();

private slots:
    void on_CleanButton_clicked();

    void on_UploadXmlButton_clicked();

    void on_DownloadXmlButton_clicked();

    void on_FindButton_clicked();

    void on_AddXmlButton_clicked();

    void on_CleanTable_clicked();

    void on_AddPerson_clicked();

    void on_PersonTable_cellClicked(int row, int column);

private:
    Ui::IndexView *ui;
    XmlParser* xmlParser;
    TableService* tableService;
    DataBaseInitService* dbInitService;
    DataBasePushService* dbPushService;
};

#endif // INDEXVIEW_H
