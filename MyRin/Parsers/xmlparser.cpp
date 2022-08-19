#include "xmlparser.h"

XmlParser::XmlParser()
{

}

QVector<PersonModel>* XmlParser::parseFile(const QString &fileName)
{
    QVector<PersonModel>* resultVector = new QVector<PersonModel>;

    QFile fileOutOut(fileName);
    if(!fileOutOut.open(QIODevice::ReadOnly | QIODevice::Text))
        return resultVector;

    QXmlStreamReader xmlReader;
    xmlReader.addData(fileOutOut.readAll());

    PersonModel tempPerson;
    while(!xmlReader.atEnd())
    {
     if(xmlReader.isStartElement())
     {
         QString elemName = xmlReader.name().toString();
         if (elemName == "Persons"){}
         else if (elemName == "Person")
             tempPerson = PersonModel();
         else if (elemName == "FirstName")
             tempPerson.FirstName = xmlReader.readElementText();
         else if (elemName == "Surname")
             tempPerson.Surname = xmlReader.readElementText();
         else if (elemName == "Patronymic")
             tempPerson.Patronymic = xmlReader.readElementText();
         else if (elemName == "Email")
             tempPerson.Email = xmlReader.readElementText();
         else if (elemName == "Telephone")
             tempPerson.Telephone = xmlReader.readElementText();
         else if (elemName == "InternalTelephone")
             tempPerson.InternalTelephone = xmlReader.readElementText();
         else if (elemName == "CityTelephone")
             tempPerson.CityTelephone = xmlReader.readElementText();
         else if (elemName == "Telegram")
             tempPerson.Telegram = xmlReader.readElementText();
         else if (elemName == "Description")
         {
             tempPerson.Description = xmlReader.readElementText();
             resultVector->push_back(tempPerson);
         }
         else
             return resultVector;

     }
     xmlReader.readNext();
    }

    return resultVector;
}

void XmlParser::parseTable(const QVector<PersonModel> persons, const QString &fileName)
{
    QDomDocument doc;
    QDomElement root = doc.createElement("Persons");

    foreach (PersonModel person, persons)
    {
        QDomElement personEl = doc.createElement("Person");

        QDomElement name = doc.createElement("FirstName");
        QDomText nameText = doc.createTextNode(person.FirstName);
        name.appendChild(nameText);

        QDomElement sname = doc.createElement("Surname");
        QDomText snameText = doc.createTextNode(person.Surname);
        sname.appendChild(snameText);

        QDomElement pname = doc.createElement("Patronymic");
        QDomText pnameText = doc.createTextNode(person.Patronymic);
        pname.appendChild(pnameText);

        QDomElement email = doc.createElement("Email");
        QDomText emailText = doc.createTextNode(person.Email);
        email.appendChild(emailText);

        QDomElement telephone = doc.createElement("Telephone");
        QDomText telephoneText = doc.createTextNode(person.Telephone);
        telephone.appendChild(telephoneText);

        QDomElement internalTelephone = doc.createElement("InternalTelephone");
        QDomText internalTelephoneText = doc.createTextNode(person.InternalTelephone);
        internalTelephone.appendChild(internalTelephoneText);

        QDomElement cityTelephone = doc.createElement("CityTelephone");
        QDomText cityTelephoneText = doc.createTextNode(person.CityTelephone);
        cityTelephone.appendChild(cityTelephoneText);

        QDomElement telegram = doc.createElement("Telegram");
        QDomText telegramText = doc.createTextNode(person.Telegram);
        telegram.appendChild(telegramText);

        QDomElement description = doc.createElement("Description");
        QDomText descriptionText = doc.createTextNode(person.Description);
        description.appendChild(telegramText);

        personEl.appendChild(name);
        personEl.appendChild(sname);
        personEl.appendChild(pname);
        personEl.appendChild(email);
        personEl.appendChild(telephone);
        personEl.appendChild(internalTelephone);
        personEl.appendChild(cityTelephone);
        personEl.appendChild(telegram);
        personEl.appendChild(description);
        root.appendChild(personEl);
    }
    doc.appendChild(root);

    QFile fileOut(fileName);
    if(fileOut.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream writeStream(&fileOut);
        writeStream << doc.toString();
        fileOut.close();
    }
}
