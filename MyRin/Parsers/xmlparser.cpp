#include "xmlparser.h"

XmlParser::XmlParser()
{

}

QVector<Person>* XmlParser::parseFile(const QString &fileName)
{
    QVector<Person>* resultVector = new QVector<Person>;

    QFile fileOutOut(fileName);
    if(!fileOutOut.open(QIODevice::ReadOnly | QIODevice::Text))
        return resultVector;

    QXmlStreamReader xmlReader;
    xmlReader.addData(fileOutOut.readAll());

    Person tempPerson("", "", "", "", "", "", "");
    while(!xmlReader.atEnd())
    {
     if(xmlReader.isStartElement())
     {
         QString elemName = xmlReader.name().toString();
         if (elemName == "Persons"){}
         else if (elemName == "Person")
             tempPerson = Person("", "", "", "", "", "", "");
         else if (elemName == "FirstName")
             tempPerson.setFirstName(xmlReader.readElementText());
         else if (elemName == "Surname")
             tempPerson.setSurname(xmlReader.readElementText());
         else if (elemName == "Patronymic")
             tempPerson.setPatronymic(xmlReader.readElementText());
         else if (elemName == "Email")
             tempPerson.setEmail(xmlReader.readElementText());
         else if (elemName == "Telephone")
             tempPerson.setTelephone(xmlReader.readElementText());
         else if (elemName == "Telegram")
             tempPerson.setTelegram(xmlReader.readElementText());
         else if (elemName == "Description")
         {
             tempPerson.setTelegram(xmlReader.readElementText());
             resultVector->push_back(tempPerson);
         }
         else
             return resultVector;

     }
     xmlReader.readNext();
    }

    return resultVector;
}

void XmlParser::parseTable(const QVector<Person> persons, const QString &fileName)
{
    QDomDocument doc;
    QDomElement root = doc.createElement("Persons");

    foreach (Person person, persons)
    {
        QDomElement personEl = doc.createElement("Person");

        QDomElement name = doc.createElement("FirstName");
        QDomText nameText = doc.createTextNode(person.getFirstName());
        name.appendChild(nameText);

        QDomElement sname = doc.createElement("Surname");
        QDomText snameText = doc.createTextNode(person.getSurname());
        sname.appendChild(snameText);

        QDomElement pname = doc.createElement("Patronymic");
        QDomText pnameText = doc.createTextNode(person.getPatronymic());
        pname.appendChild(pnameText);

        QDomElement email = doc.createElement("Email");
        QDomText emailText = doc.createTextNode(person.getEmail());
        email.appendChild(emailText);

        QDomElement telephone = doc.createElement("Telephone");
        QDomText telephoneText = doc.createTextNode(person.getTelephone());
        telephone.appendChild(telephoneText);

        QDomElement telegram = doc.createElement("Telegram");
        QDomText telegramText = doc.createTextNode(person.getTelegram());
        telegram.appendChild(telegramText);

        QDomElement description = doc.createElement("Description");
        QDomText descriptionText = doc.createTextNode(person.getDescription());
        description.appendChild(telegramText);

        personEl.appendChild(name);
        personEl.appendChild(sname);
        personEl.appendChild(pname);
        personEl.appendChild(email);
        personEl.appendChild(telephone);
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
