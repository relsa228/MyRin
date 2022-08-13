#include "indexview.h"
#include "ui_indexview.h"

IndexView::IndexView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IndexView)
{
    ui->setupUi(this);
    xmlParser = new XmlParser();
    filter = new Filter();
    filtersOn = false;
    saveBeforeVector = new QVector<Person>;

    ui->PersonTable->setColumnCount(6);

    for (int i = 0; i < 6; i++)
        ui->PersonTable->setColumnWidth(i, 100);

    ui->PersonTable->setHorizontalHeaderLabels(QStringList()<< "Имя" << "Фамилия" << "Отчество" << "Почта" << "Телефон" << "Личный номер");
}

IndexView::~IndexView()
{
    delete ui;
}

void IndexView::ErrorMsg(QString errorMsg)
{
    QMessageBox msg = QMessageBox();
    msg.setWindowIcon(QIcon(":/icon/mainIcon/Icons/calendar3.svg"));
    msg.setWindowTitle("Ошибка");
    msg.setIcon(msg.Critical);
    msg.setText(errorMsg);
    msg.addButton("Принято", msg.AcceptRole);
    msg.exec();
}

void IndexView::InfoMsg(QString infoMsg)
{
    QMessageBox msg = QMessageBox();
    msg.setWindowIcon(QIcon(":/icon/mainIcon/Icons/calendar3.svg"));
    msg.setWindowTitle("Выполнено");
    msg.setIcon(msg.Information);
    msg.setText(infoMsg);
    msg.addButton("Принято", msg.AcceptRole);
    msg.exec();
}

void IndexView::FillPersonsTable(const QVector<Person> *persons)
{
    ui->PersonTable->setRowCount(persons->count());

    for(int row = 0; row < persons->count(); row++)
    {
        QTableWidgetItem *firstName = new QTableWidgetItem(tr("%1").arg(persons->at(row).getFirstName()));
        ui->PersonTable->setItem(row, 0, firstName);
        ui->PersonTable->item(row, 0)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);

        QTableWidgetItem *surname = new QTableWidgetItem(tr("%1").arg(persons->at(row).getSurname()));
        ui->PersonTable->setItem(row, 1, surname);
        ui->PersonTable->item(row, 1)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);

        QTableWidgetItem *patronymic = new QTableWidgetItem(tr("%1").arg(persons->at(row).getPatronymic()));
        ui->PersonTable->setItem(row, 2, patronymic);
        ui->PersonTable->item(row, 2)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);

        QTableWidgetItem *email = new QTableWidgetItem(tr("%1").arg(persons->at(row).getEmail()));
        ui->PersonTable->setItem(row, 3, email);
        ui->PersonTable->item(row, 3)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);

        QTableWidgetItem *telephone = new QTableWidgetItem(tr("%1").arg(persons->at(row).getTelephone()));
        ui->PersonTable->setItem(row, 4, telephone);
        ui->PersonTable->item(row, 4)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);

        QTableWidgetItem *selfId = new QTableWidgetItem(tr("%1").arg(persons->at(row).getSelfId()));
        ui->PersonTable->setItem(row, 5, selfId);
        ui->PersonTable->item(row, 5)->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    }
}

QVector<Person>* IndexView::GetDataFromTable()
{
    QVector<Person>* resultVector = new QVector<Person>();
    for(int row = 0; row < ui->PersonTable->rowCount(); row++)
    {
        Person tempPerson("", "", "", "", "", "");
        tempPerson.setFirstName(ui->PersonTable->item(row, 0)->text());
        tempPerson.setSurname(ui->PersonTable->item(row, 1)->text());
        tempPerson.setPatronymic(ui->PersonTable->item(row, 2)->text());
        tempPerson.setEmail(ui->PersonTable->item(row, 3)->text());
        tempPerson.setTelephone(ui->PersonTable->item(row, 4)->text());
        tempPerson.setSelfId(ui->PersonTable->item(row, 5)->text());

        resultVector->push_back(tempPerson);
    }

    return resultVector;
}

void IndexView::on_FindButton_clicked()
{
    if (filtersOn)
        FillPersonsTable(saveBeforeVector);
    else
    {
        filtersOn = true;
        saveBeforeVector = GetDataFromTable();
    }

    QVector<Person>* filterVector = GetDataFromTable();

    QString firstNameFilter = ui->FirstNameInput->text();
    QString surnameFilter = ui->SurnameInput->text();
    QString patronymicFilter = ui->PatronymicInput->text();
    QString emailFilter = ui->EmailInput->text();
    QString telephoneFilter = ui->TelephoneInput->text();
    QString selfIdFilter = ui->SelfIdInput->text();

    QVector<Person>* resultVector = filter->filterContent(*filterVector, firstNameFilter, surnameFilter, patronymicFilter,
                                                         emailFilter, telephoneFilter, selfIdFilter);

    FillPersonsTable(resultVector);

    if(resultVector->count() == 0)
        ErrorMsg("По вашему запросу не найдено результатов.");
    else
        InfoMsg("Результатов по вашему запросу: " + QString::number(resultVector->count()));
}

void IndexView::on_CleanButton_clicked()
{
    if(!saveBeforeVector->isEmpty())
        FillPersonsTable(saveBeforeVector);
    ui->FirstNameInput->setText("");
    ui->SurnameInput->setText("");
    ui->PatronymicInput->setText("");
    ui->EmailInput->setText("");
    ui->TelephoneInput->setText("");
    ui->SelfIdInput->setText("");
}


void IndexView::on_UploadXmlButton_clicked()
{
    QString xmlFilePath = QFileDialog::getOpenFileName(
                            this,
                            tr("Загрузить файл"),
                            "",
                            tr("XML (*.xml);;TXT (*.txt)")
                            );
    if(!xmlFilePath.isEmpty())
    {
        QVector<Person>* uploadPersons = xmlParser->parseFile(xmlFilePath);
        if(uploadPersons->count() == 0)
            ErrorMsg("Файл пустой или имеет некорректный формат.");
        else
        {
            FillPersonsTable(uploadPersons);
            saveBeforeVector = GetDataFromTable();
        }
    }
}


void IndexView::on_DownloadXmlButton_clicked()
{
    QString xmlSavePath = QFileDialog::getSaveFileName(
                        this,
                        tr("Сохранить файл"),
                        "",
                        tr("XML (*.xml);;TXT (*.txt)")
                        );
    xmlParser->parseTable(*GetDataFromTable(), xmlSavePath);
}
