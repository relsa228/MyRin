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
    dbGetService = new DataBaseGetService();

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


void IndexView::resizeEvent(QResizeEvent *)
{
    float newSize = ui->PersonTable->size().width()/9;
    if(ui->PersonTable->size().width() >= 1067)
        for (int i = 0; i < 9; i++)
            ui->PersonTable->setColumnWidth(i, newSize - 6.5);
}

#define TOOL_BUTTONS {
void IndexView::on_FindButton_clicked()
{
    QStringList listOfFilters = QStringList();
    listOfFilters << ui->FirstNameInput->text();
    listOfFilters << ui->SurnameInput->text();
    listOfFilters << ui->PatronymicInput->text();

    listOfFilters << ui->TelephoneInput->text();
    listOfFilters << ui->InternalTelephoneInput->text();
    listOfFilters << ui->CityTelephoneInput->text();

    listOfFilters << ui->EmailInput->text();
    listOfFilters << ui->TelegramInput->text();
    listOfFilters << ui->DescriptionInput->toPlainText();

    tableService->UpadateTableByFilter(listOfFilters);
}

void IndexView::on_CleanButton_clicked()
{
    tableService->UpdateFromDataBase();

    ui->FirstNameInput->setText("");
    ui->SurnameInput->setText("");
    ui->PatronymicInput->setText("");
    ui->EmailInput->setText("");
    ui->TelephoneInput->setText("");
    ui->TelegramInput->setText("");
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

void IndexView::on_PersonTable_currentCellChanged(int currentRow, int, int, int)
{
     currentViewRow = currentRow;

    if (currentViewRow == -1)
    {
        ui->FirstNameView->setText("");
        ui->SurnameView->setText("");
        ui->PatronymicView->setText("");

        ui->TelephoneView->setText("");
        ui->InternalTelephoneView->setText("");
        ui->CityTelephoneView->setText("");

        ui->TelegramView->setText("@");
        ui->EmailView->setText("");
        ui->DescriptionView->setText("");

        return;
    }

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
    if(currentViewRow == -1) ErrorMessage("Необходимо выбрать элемент");
    else
    {
        PersonModel model = tableService->GetPersonFromTable(currentViewRow);
        RedactPersonView *redactPersonView = new RedactPersonView(currentViewRow, model, tableService);
        redactPersonView->show();
    }

}

void IndexView::on_DeletePerson_clicked()
{
    if(currentViewRow == -1) ErrorMessage("Необходимо выбрать элемент");
    else dbPushService->deletePerson(tableService, currentViewRow);
}
#define END_TOOL_BUTTONS }

#define XML_BUTTONS {
void IndexView::on_UploadXmlButton_clicked()
{
    QString xmlFilePath = QFileDialog::getOpenFileName(this, tr("Загрузить файл"), "",
                                                       tr("XML (*.xml);;JSON (*.json);;TXT (*.txt)"));

    if(!xmlFilePath.isEmpty())
    {
        if(dbPushService->updateFromXmlFile(xmlFilePath, tableService).isValid() || qx::dao::count<PersonModel>() == 0)
            ErrorMessage("Файл пустой или имеет некорректный формат.");
        else
            InfoMessage("Файл успешно обработан. Получено записей: " + QString::number(qx::dao::count<PersonModel>()) +
                        "\nТекущее кол-во записей: " + QString::number(qx::dao::count<PersonModel>()));
    }
}

void IndexView::on_AddXmlButton_clicked()
{
    QString xmlFilePath = QFileDialog::getOpenFileName(this, tr("Загрузить файл"), "",
                                                       tr("XML (*.xml);;JSON (*.json);;TXT (*.txt)"));
    int bufferCount = qx::dao::count<PersonModel>();

    if(!xmlFilePath.isEmpty())
    {
        if(dbPushService->addFromXmlFile(xmlFilePath, tableService).isValid() || qx::dao::count<PersonModel>() - bufferCount == 0)
            ErrorMessage("Файл пустой или имеет некорректный формат.");
        else InfoMessage("Файл успешно обработан. Получено записей: " + QString::number(qx::dao::count<PersonModel>() - bufferCount) +
                         "\nТекущее кол-во записей: " + QString::number(qx::dao::count<PersonModel>()));
    }
}

void IndexView::on_DownloadXmlButton_clicked()
{
    QString xmlSavePath = QFileDialog::getSaveFileName(this, tr("Сохранить файл"), "",
                                                       tr("XML (*.xml);;JSON (*.json);;TXT (*.txt)"));

    xmlParser->parseTable(*tableService->GetAllPersons(), xmlSavePath);
}
#define END_XML_BUTTONS }
