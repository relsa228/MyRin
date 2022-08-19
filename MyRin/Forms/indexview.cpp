#include "indexview.h"
#include "ui_indexview.h"

IndexView::IndexView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IndexView)
{
    ui->setupUi(this);
    xmlParser = new XmlParser();
    tableServise = new TableService(ui->PersonTable);
    filtersOn = false;
    saveBeforeVector = new QVector<PersonModel>;
    dbInit = new DataBaseInitService();

    ui->PersonTable->setColumnCount(9);

    for (int i = 0; i < 9; i++)
        ui->PersonTable->setColumnWidth(i, 105);
    ui->PersonTable->setColumnWidth(8, 165);

    ui->PersonTable->setHorizontalHeaderLabels(QStringList()<< "Имя" << "Фамилия" << "Отчество" << "Почта"
                                               << "Телефон" << "Внтр. телефон" << "Гор. телефон" << "Telegram"
                                               << "Дополнительные сведения");
}

IndexView::~IndexView()
{
    delete ui;
}

void IndexView::on_FindButton_clicked()
{
    if (filtersOn)
        tableServise->AddVectorOfPersonsToTable(saveBeforeVector);
    else
    {
        filtersOn = true;
        saveBeforeVector = tableServise->GetAllPersons();
    }

    QVector<PersonModel>* filterVector = tableServise->GetAllPersons();

    QString firstNameFilter = ui->FirstNameInput->text();
    QString surnameFilter = ui->SurnameInput->text();
    QString patronymicFilter = ui->PatronymicInput->text();
    QString emailFilter = ui->EmailInput->text();
    QString telephoneFilter = ui->TelephoneInput->text();
    QString TelegramFilter = ui->TelegramInput->text();
}

void IndexView::on_CleanButton_clicked()
{
    if(!saveBeforeVector->isEmpty())
        tableServise->AddVectorOfPersonsToTable(saveBeforeVector);
    ui->FirstNameInput->setText("");
    ui->SurnameInput->setText("");
    ui->PatronymicInput->setText("");
    ui->EmailInput->setText("");
    ui->TelephoneInput->setText("");
    ui->TelegramInput->setText("@");
}


void IndexView::on_UploadXmlButton_clicked()
{
    QString xmlFilePath = QFileDialog::getOpenFileName(
                            this,
                            tr("Загрузить файл"),
                            "",
                            tr("XML (*.xml);;JSON (*.json);;TXT (*.txt)")
                            );
    if(!xmlFilePath.isEmpty())
    {
        QVector<PersonModel>* uploadPersons = xmlParser->parseFile(xmlFilePath);
        if(uploadPersons->count() == 0)
            ErrorMessage("Файл пустой или имеет некорректный формат.");
        else
        {
            tableServise->AddVectorOfPersonsToTable(uploadPersons);
            saveBeforeVector = tableServise->GetAllPersons();
            InfoMessage("Файл успешно обработан. Получено записей: " + QString::number(uploadPersons->count()));
        }
    }
}


void IndexView::on_DownloadXmlButton_clicked()
{
    QString xmlSavePath = QFileDialog::getSaveFileName(
                        this,
                        tr("Сохранить файл"),
                        "",
                        tr("XML (*.xml);;JSON (*.json);;TXT (*.txt)")
                        );
    xmlParser->parseTable(*tableServise->GetAllPersons(), xmlSavePath);
}
