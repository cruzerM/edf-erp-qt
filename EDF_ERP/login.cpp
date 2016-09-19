#include "connexion.h"
#include <QSqlQuery>
#include <QWidget>
#include <QString>
#include <QFileInfo>
#include <QMessageBox>
#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    Son->play("Accueil");

    this->setWindowTitle("Login EDF ERP");

    if (C.ConnectionBD())
         {
             ui->label_status->setText(("[++] Connecté a la Base de données!"));
         }
     else
         {
             ui->label_status->setText(("[!!!] Base de données inexistante!"));
         };
}

Login::~Login()
{
    delete ui;
    qDebug() << "Cloture de la connexion avec la base de données.";
    C.FermerConnexionBD();
}




void Login::on_connect_clicked()
{
    QString Username, Password, dept;
    int pri;
    Username = ui->login_text->text();
    Password = ui->pwd_text->text();

    Connexion(Username, Password);

    QString acces = C.ConnBD(Username,Password);
    dept = acces.mid(0,2);
    pri = acces.mid(2,1).toInt();
    if(acces!="4")
        {
            ui->label_status->setText("[++] Login & Mot de passe valides!");
            C.setLogin(Username);
            C.setPrivilege(pri);

            if (dept == "RH")
            {
                MenuRH = new Interface_menu_RH();
                MenuRH->show();
            }
            else if(dept == "FI")
            {
                Finances = new Valider(this, C);
                Finances->show();
            }
            else if(dept == "PR")
            {
                Production = new Manufacturing(this,C);
                Production->show();
                this->setWindowTitle(Production->windowTitle());
            }
        }
    else
        {
            ui->label_status->setText("[--] Invalide ou Déja connécté!");
        }
}

void Login::on_clear_button_clicked()
{
    ui->login_text->setText("");
    ui->pwd_text->setText("");
    ui->label_status->setText("[* *] En attente...");
}

void Login::on_exit_clicked()
{
    C.initUsers(ui->login_text->text());
    close();
}

