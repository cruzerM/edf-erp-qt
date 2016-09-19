#include "ui_interface_menu_rh.h"
#include "interface_menu_rh.h"
#include "interface_employe_rh.h"
#include "interface_paie_rh.h"
#include "interface_assiduite_rh.h"
#include "interface_contrat_rh.h"

Interface_menu_RH::Interface_menu_RH(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Interface_menu_RH)
{
    ui->setupUi(this);
}

Interface_menu_RH::~Interface_menu_RH()
{
    delete ui;
}

void Interface_menu_RH::on_pushButton_employe_clicked()
{
    employe=new Interface_Employe_RH();
    employe->show();
}

void Interface_menu_RH::on_pushButton_assiduite_clicked()
{
    assiduite=new Interface_Assiduite_RH(this);
    assiduite->show();
}

void Interface_menu_RH::on_pushButton_paie_clicked()
{
    paie=new Interface_Paie_RH(this);
    paie->show();
}

void Interface_menu_RH::on_pushButton_contrat_clicked()
{
    contrat=new Interface_Contrat_RH(this);
    contrat->show();
}



void Interface_menu_RH::on_actionQuitter_triggered()
{
    C->initUsers("Hannachi Ghassen");

    this->close();
}

void Interface_menu_RH::on_actionEnvoyer_un_message_triggered()
{
    M = new Messages(this, "Hannachi Ghassen");
    M->exec();
}

void Interface_menu_RH::on_actionEnvoyer_un_email_triggered()
{
    mail = new Mail(this);
    mail->show();
}
