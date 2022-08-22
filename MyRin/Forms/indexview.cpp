#include "indexview.h"
#include "ui_indexview.h"

IndexView::IndexView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IndexView)
{
    currentViewRow = -1;
    ui->setupUi(this);
    xmlParser = new XmlParser();

    tableService = new TableService(ui->PersonTable);
    dbInitService = new DataBaseInitService();
    dbPushService = new DataBasePushService();

    ui->PersonTable->setColumnCount(9);
    for (int i = 0; i < 9; i++)
        ui->PersonTable->setColumnWidth(i, 105);
    ui->PersonTable->setColumnWidth(8, 165);
    ui->PersonTable->setHorizontalHeaderLabels(QStringList()<< "Имя" << "Фамилия" << "Отчество" << "Почта"
                                               << "Телефон" << "Внтр. телефон" << "Гор. телефон" << "Telegram"
                                               << "Дополнительные сведения");
    tableService->UpdateFromDataBase();
}

IndexView::~IndexView()
{
    delete ui;
}

#define TOOL_BUTTONS {
void IndexView::on_FindButton_clicked()
{
    QString firstNameFilter = ui->FirstNameInput->text();
    QString surnameFilter = ui->SurnameInput->text();
    QString patronymicFilter = ui->PatronymicInput->text();
    QString emailFilter = ui->EmailInput->text();
    QString telephoneFilter = ui->TelephoneInput->text();
    QString TelegramFilter = ui->TelegramInput->text();
}

void IndexView::on_CleanButton_clicked()
{
    tableService->UpdateFromDataBase();

    ui->FirstNameInput->setText("");
    ui->SurnameInput->setText("");
    ui->PatronymicInput->setText("");
    ui->EmailInput->setText("");
    ui->TelephoneInput->setText("");
    ui->TelegramInput->setText("@");
}

void IndexView::on_CleanTable_clicked()
{
    dbInitService->cleanDataBase();
    tableService->cleanTable();
}

void IndexView::on_AddPerson_clicked()
{
    AddPersonView *addPersonView = new AddPersonView(tableService);
    addPersonView->show();
}
#define END_TOOL_BUTTONS }

#define XML_BUTTONS {
void IndexView::on_UploadXmlButton_clicked()
{
    QString xmlFilePath = QFileDialog::getOpenFileName(this, tr("Загрузить файл"), "",
                                                       tr("XML (*.xml);;JSON (*.json);;TXT (*.txt)"));

    if(!xmlFilePath.isEmpty())
    {
        if(dbPushService->updateFromXmlFile(xmlFilePath).isValid() || qx::dao::count<PersonModel>() == 0)
            ErrorMessage("Файл пустой или имеет некорректный формат.");
        else
        {
            tableService->UpdateFromDataBase();
            InfoMessage("Файл успешно обработан. Получено записей: " + QString::number(qx::dao::count<PersonModel>()) +
                        "\nТекущее кол-во записей: " + QString::number(qx::dao::count<PersonModel>()));
        }
    }
}

void IndexView::on_AddXmlButton_clicked()
{
    QString xmlFilePath = QFileDialog::getOpenFileName(this, tr("Загрузить файл"), "",
                                                       tr("XML (*.xml);;JSON (*.json);;TXT (*.txt)"));
    long bufferCount = qx::dao::count<PersonModel>();

    if(!xmlFilePath.isEmpty())
    {
        if(dbPushService->addFromXmlFile(xmlFilePath).isValid() || qx::dao::count<PersonModel>() - bufferCount == 0)
            ErrorMessage("Файл пустой или имеет некорректный формат.");
        else
        {
            tableService->AddFromDataBase();
            InfoMessage("Файл успешно обработан. Получено записей: " + QString::number(qx::dao::count<PersonModel>() - bufferCount) +
                        "\nТекущее кол-во записей: " + QString::number(qx::dao::count<PersonModel>()));
        }
    }
}

void IndexView::on_DownloadXmlButton_clicked()
{
    QString xmlSavePath = QFileDialog::getSaveFileName(this, tr("Сохранить файл"), "",
                                                       tr("XML (*.xml);;JSON (*.json);;TXT (*.txt)"));

    xmlParser->parseTable(*tableService->GetAllPersons(), xmlSavePath);
}
#define END_XML_BUTTONS }


void IndexView::on_PersonTable_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{
    currentViewRow = currentRow;
    PersonModel person = tableService->GetPersonFromTable(currentRow);

    ui->FirstNameView->setText(person.FirstName);
    ui->SurnameView->setText(person.Surname);
    ui->PatronymicView->setText(person.Patronymic);

    ui->TelephoneView->setText(person.Telephone);
    ui->InternalTelephoneView->setText(person.InternalTelephone);
    ui->CityTelephoneView->setText(person.CityTelephone);

    ui->EmailView->setText(person.Email);
    ui->TelegramView->setText(person.Telegram);
    ui->DescriptionView->setText(person.Description);
}


void IndexView::on_EditPerson_clicked()
{
    if(currentViewRow == -1)
        ErrorMessage("Необходимо выбрать элемент");
    else
    {
        PersonModel model = tableService->GetPersonFromTable(currentViewRow);
        RedactPersonView *redactPersonView = new RedactPersonView(currentViewRow, model, tableService);
        redactPersonView->show();
    }

}

