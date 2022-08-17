#include "infomessage.h"

InfoMessage::InfoMessage(QString message)
{
    QMessageBox msg = QMessageBox();
    msg.setWindowIcon(QIcon(":/icon/mainIcon/Icons/calendar3.svg"));
    msg.setWindowTitle("Выполнено");
    msg.setIcon(msg.Information);
    msg.setText(message);
    msg.addButton("Принято", msg.AcceptRole);
    msg.exec();
}
