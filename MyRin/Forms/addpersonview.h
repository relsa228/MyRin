#ifndef ADDPERSONVIEW_H
#define ADDPERSONVIEW_H

#include <QDialog>

namespace Ui {
class AddPersonView;
}

class AddPersonView : public QDialog
{
    Q_OBJECT

public:
    explicit AddPersonView(QWidget *parent = nullptr);
    ~AddPersonView();

private:
    Ui::AddPersonView *ui;
};

#endif // ADDPERSONVIEW_H
