
#include "interface_employe_rh.h"
#include "employes.h"
#include "ui_interface_employe_rh.h"
#include <sstream>



Interface_Employe_RH::Interface_Employe_RH(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Interface_Employe_RH)
{
    ui->setupUi(this);
    ui->tableView_employe->setModel(E.afficher());

}

Interface_Employe_RH::~Interface_Employe_RH()
{
    delete ui;
}
void Interface_Employe_RH::on_pushButton_emp_aj_clicked()
{

    E.setidEmploye(ui->lineEdit_id->text().toInt());
    E.setnom(ui->lineEdit_nom->text());
    E.setprenom(ui->lineEdit_prenom->text());
    E.setCIN(ui->lineEdit_CIN->text());
    E.setadresse(ui->textEdit_adresse->toPlainText());
    E.settelephone(ui->lineEdit_tele->text().toInt());
    E.setage(ui->spinBox_age->value());
    E.setdiplome(ui->comboBox_diplome->currentText());
    E.setcause_sortie(ui->comboBox_depard->currentText());
    E.setdepartement(ui->comboBox_departement->currentText());
    E.setgrade(ui->comboBox_grade->currentText());
    if (ui->comboBox_grade->currentText() != "Cadre")
    {
        E.setposte("");
    }
    else
    {
        E.setposte(ui->comboBox_poste->currentText());
    }
    E.setemail(ui->lineEdit_email->text());

    if(ui->comboBox_etat->currentText()=="Active")
    {
        E.setetat_employe(true);
    }else {
        E.setetat_employe(false);
    }

    E.ajouter();
}

void Interface_Employe_RH::on_pushButton_emp_mo_clicked()
{
    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(this,"Demande de modification","Voulez-vous modifier cette donnee ?");
    if(reply==QMessageBox::Yes)
    {
        Employe E;
        E.setidEmploye(ui->lineEdit_id->text().toInt());
        E.setnom(ui->lineEdit_nom->text());
        E.setprenom(ui->lineEdit_prenom->text());
        E.setCIN(ui->lineEdit_CIN->text());
        E.setadresse(ui->textEdit_adresse->toPlainText());
        E.settelephone(ui->lineEdit_tele->text().toInt());
        E.setage(ui->spinBox_age->value());
        E.setdiplome(ui->comboBox_diplome->currentText());
        E.setcause_sortie(ui->comboBox_depard->currentText());
        E.setdepartement(ui->comboBox_departement->currentText());
        E.setgrade(ui->comboBox_grade->currentText());
        if (ui->comboBox_grade->currentText() != "Cadre")
        {
            E.setposte("");
        }
        else
        {
            E.setposte(ui->comboBox_poste->currentText());
        }
        E.setemail(ui->lineEdit_email->text());

        if(ui->comboBox_etat->currentText()=="Active")
        {
            E.setetat_employe(true);
        }else {
            E.setetat_employe(false);
        }
        E.modifier();
    }
}


void Interface_Employe_RH::on_pushButton_emp_sup_clicked()
{
    Employe E;
    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(this,"Demande de suppression","Voulez-vous supprimer cette donnee ?");
    if(reply==QMessageBox::Yes)
    {
    E.setidEmploye(ui->lineEdit_id->text().toInt());
    E.supprimer();
    }

}


void Interface_Employe_RH::on_pushButton_emp_verifier_clicked()
{
    Employe E;
    E.setidEmploye(ui->lineEdit_id->text().toInt());
    if(E.verifier_id())
    {
        ui->lineEdit_nom->setText(E.getnom());
        ui->lineEdit_prenom->setText(E.getprenom());
        ui->textEdit_adresse->setPlainText(E.getadresse());
        ui->lineEdit_CIN->setText(E.getCIN());
         QString telephone = QString::number(E.gettelephone());
        ui->lineEdit_tele->setText(telephone);
        ui->spinBox_age->setValue(E.getage());
        ui->comboBox_diplome->setCurrentText(E.getdiplome());
        ui->comboBox_depard->setCurrentText(E.getcause_sortie());
        ui->comboBox_departement->setCurrentText(E.getdepartement());
        ui->comboBox_poste->setCurrentText(E.getposte());
        ui->comboBox_grade->setCurrentText(E.getgrade());
        ui->lineEdit_email->setText(E.getemail());
         if(E.getetat_employe())
         {
             ui->comboBox_etat->setCurrentText("Active");
         }else{
             ui->comboBox_etat->setCurrentText("Inactive");
         }
        QMessageBox::information(this,"","Existe");
    }else{QMessageBox::information(this,"","N'existe pas");}
}

void Interface_Employe_RH::on_pushButton_emp_aff_clicked()
{
    Employe E;
    ui->tableView_employe->setModel(E.afficher());
}

void Interface_Employe_RH::on_comboBox_grade_currentTextChanged(const QString &arg1)
{

    if(arg1=="Cadre")
    {
        ui->comboBox_poste->setEnabled(true);
    }
    else
    {
        ui->comboBox_poste->setEnabled(false);

    }
}
