#include "manufacturing.h"
#include "ui_manufacturing.h"

Manufacturing::Manufacturing(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Manufacturing)
{
    ui->setupUi(this);
}

Manufacturing::Manufacturing(QWidget *parent, Connexion& C) :
    QMainWindow(parent),
    ui(new Ui::Manufacturing)
{
    Conn=C;
    ui->setupUi(this);
    ui->login_name->setText(Conn.getLogin());
    raf_auto();
    if(Conn.getPrivilege() == 1)
    {
        ui->groupBox_gestion->setEnabled(false);
        ui->groupBox_suivi->setEnabled(true);
    }
    else if (Conn.getPrivilege() == 2)
    {
        ui->groupBox_suivi->setEnabled(false);
        ui->groupBox_gestion->setEnabled(true);
    }
    else
    {
        ui->groupBox_gestion->setEnabled(true);
        ui->groupBox_suivi->setEnabled(true);
    }
}



Manufacturing::~Manufacturing()
{
    delete ui;
}

void Manufacturing::on_but_gestion_emp_clicked()
{
    Femployes Emp;
    Emp.setModal(true);
    Emp.exec();

}

void Manufacturing::on_but_envoyer_clicked()
{
    Messages Msg(this,Conn.getLogin());
    Msg.setModal(true);
    Msg.exec();

}

void Manufacturing::on_but_gestion_sites_clicked()
{
    Fsites Site;
    Site.setModal(true);
    Site.exec();

}

void Manufacturing::on_but_gestion_MP_clicked()
{
    Fmp MP;
    MP.setModal(true);
    MP.exec();

}

void Manufacturing::on_but_gestion_prod_clicked()
{
    Fproduction Prod;
    Prod.setModal(true);
    Prod.exec();
}

void Manufacturing::on_but_control_clicked()
{
    FControl Ctrl;
    Ctrl.setModal(true);
    Ctrl.exec();
}

void Manufacturing::on_but_repair_clicked()
{
    Freparation Repair;
    Repair.setModal(true);
    Repair.exec();

}

void Manufacturing::on_quitter_but_clicked()
{
    Conn.initUsers(Conn.getLogin());
    close();
}

bool Manufacturing::setEtat()
{
        ui->nbre_connectes->setText(Conn.compterUsers().value("Nombre").toString());
        return true;
}

QString Manufacturing::nombreMessages()
{
    QString ch = M->nombreMes(Conn.getLogin()).value("Nombre").toString();
    if (ch!="")
    {
    ui->but_envoyer->setText(ch + " Nouveau(x) Message(s) )");
    return ch;
    }
    else
        return "0";
}

bool Manufacturing::raf_auto()
{
    QTimer* mTimer;
    mTimer = new QTimer(this);
    mTimer->start(500);
    mTimer->setSingleShot(false);

    if (setEtat())
    {
        nombreMessages();
        connect(mTimer, SIGNAL(timeout()), SLOT(setEtat()));
        connect(mTimer, SIGNAL(timeout()), SLOT(nombreMessages()));
                return true;
    }
    return false;
}


void Manufacturing::on_actionEnvoyer_un_Message_triggered()
{
    Messages Msg(this,Conn.getLogin());
    Msg.setModal(true);
    Msg.exec();

}

void Manufacturing::on_actionEnvoyer_un_Mail_triggered()
{
    mail = new Mail(this);
    mail->show();
}
