#include "intro.h"
#include "ui_intro.h"

Intro::Intro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Intro)
{
    ui->setupUi(this);

    QAxWidget *flash = new QAxWidget(this);
    flash->resize(600, 250);
    flash->setControl(QString::fromUtf8("{d27cdb6e-ae6d-11cf-96b8-444553540000}"));
    flash->dynamicCall("LoadMovie(long,string)", 0,QDir::currentPath()+"/intro3.swf");
    this->setWindowFlags(Qt::CustomizeWindowHint);
    this->setWindowFlags(Qt::FramelessWindowHint);

    QTimer::singleShot(2800, this, SLOT(close()));
}

Intro::~Intro()
{
    delete ui;
}

