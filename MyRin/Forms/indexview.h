#ifndef INDEXVIEW_H
#define INDEXVIEW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QVector>

#include "Parsers/xmlparser.h"

#include "Models/personmodel.h"

#include "Services/MessagesService/errormessage.h"
#include "Services/MessagesService/infomessage.h"
#include "Services/tableservice.h"
#include "Services/DataBaseService/databaseinitservice.h"

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

private:
    Ui::IndexView *ui;
    XmlParser* xmlParser;
    TableService* tableServise;
    DataBaseInitService* dbInit;

    bool filtersOn;
    QVector<PersonModel>* saveBeforeVector;
};

#endif // INDEXVIEW_H
