#include "thefinalscore.h"
#include "ui_thefinalscore.h"

TheFinalScore::TheFinalScore(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TheFinalScore)
{
    ui->setupUi(this);
}

TheFinalScore::~TheFinalScore()
{
    delete ui;
}
