#include "last_screen.h"
#include "ui_last_screen.h"

Last_Screen::Last_Screen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Last_Screen)
{
    ui->setupUi(this);

}

Last_Screen::~Last_Screen()
{
    delete ui;
}
