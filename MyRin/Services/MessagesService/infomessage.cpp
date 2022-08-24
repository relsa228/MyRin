#include "infomessage.h"

InfoMessage::InfoMessage(QString message)
{
    QMessageBox msg = QMessageBox();
    msg.setWindowIcon(QIcon(":/icons/mainIcon/Icons/MainIcons/table.svg"));
    msg.setWindowTitle("Выполнено");
    msg.setIcon(msg.Information);
    msg.setText(message);
    msg.addButton("Принято", msg.AcceptRole);
    msg.exec();
}
