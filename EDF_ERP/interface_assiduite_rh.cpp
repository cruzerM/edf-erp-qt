

#include "interface_assiduite_rh.h"
#include "assiduites.h"
#include "ui_interface_assiduite_rh.h"

Interface_Assiduite_RH::Interface_Assiduite_RH(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Interface_Assiduite_RH)
{

    ui->setupUi(this);
    ui->combo_id_emp->setModel(E.extraireListeEmp());
    ui->tableView_assiduite->setModel(A.afficher());
}

Interface_Assiduite_RH::~Interface_Assiduite_RH()
{
    delete ui;
}

void Interface_Assiduite_RH::on_pushButton_assiduite_verifier_clicked()
{

    A.setidAssiduite(ui->lineEdit_assid_id->text().toInt());
    if(A.verifier_id())
    {
        QString employe = QString::number(A.getidEmploye());
        ui->combo_id_emp->setCurrentText(employe);
        ui->lineEdit_assi_periode->setText(A.getperiode());
        ui->lineEdit_assi_date_depart->setText(A.getdate_depart());
        ui->lineEdit_assi_date_reprise->setText(A.getdate_reprise());
        ui->lineEdit_assi_type_conge->setText(A.gettype());
        ui->spinBox_assi_absence->setValue(A.getabsence());
        ui->spinBox_assi_hs->setValue(A.getheure_supplementaire());
        ui->spinBox_assi_retard->setValue(A.getretard());
        if(A.getdisponibilite())
        {
            ui->comboBox_assi_presence->setCurrentText("Present(e)");
        }
        else
        {
         ui->comboBox_assi_presence->setCurrentText("Absent(e)");
        }
        QMessageBox::information(this,"","Existe");
    }else{QMessageBox::information(this,"","N'existe pas");}
}
void Interface_Assiduite_RH::on_pushButton_assiduite_ajouter_clicked()
{
   A.setidAssiduite(ui->lineEdit_assid_id->text().toInt());
   A.setidEmploye(ui->combo_id_emp->currentText().toInt());
   A.setdate_depart(ui->lineEdit_assi_date_depart->text());
   A.setdate_reprise(ui->lineEdit_assi_date_reprise->text());
   A.settype(ui->lineEdit_assi_type_conge->text());
   A.setabsence(ui->spinBox_assi_absence->value());
   A.setretard(ui->spinBox_assi_retard->value());
   A.setheure_supplementaire(ui->spinBox_assi_hs->value());
   A.setperiode(ui->lineEdit_assi_periode->text());
   if(ui->comboBox_assi_presence->currentText()=="Present(e)")
   {
       A.setdisponibilite(true);
   }else
   {
       A.setdisponibilite(false);
   }
   A.ajouter();
}
void Interface_Assiduite_RH::on_pushButton_assiduit_modifier_clicked()
{
    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(this,"Demande de modification","Voulez-vous modifier cette donnee ?");
    if(reply==QMessageBox::Yes)
    {
    A.setidAssiduite(ui->lineEdit_assid_id->text().toInt());
    A.setidEmploye(ui->combo_id_emp->currentText().toInt());
    A.setdate_depart(ui->lineEdit_assi_date_depart->text());
    A.setdate_reprise(ui->lineEdit_assi_date_reprise->text());
    A.settype(ui->lineEdit_assi_type_conge->text());
    A.setabsence(ui->spinBox_assi_absence->value());
    A.setretard(ui->spinBox_assi_retard->value());
    A.setheure_supplementaire(ui->spinBox_assi_hs->value());
    A.setperiode(ui->lineEdit_assi_periode->text());
    if(ui->comboBox_assi_presence->currentText()=="Present(e)")
    {
        A.setdisponibilite(true);
    }else
    {
        A.setdisponibilite(false);
    }
    A.modifier();
    }
}
void Interface_Assiduite_RH::on_pushButton_assiduite_supp_clicked()
{
    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(this,"Demande de suppression","Voulez-vous supprimer cette donnee ?");
    if(reply==QMessageBox::Yes)
    {
    A.setidAssiduite(ui->lineEdit_assid_id->text().toInt());
    A.supprimer();
    }
}

void Interface_Assiduite_RH::on_pushButton_assiduite_actualiser_clicked()
{
    ui->tableView_assiduite->setModel(A.afficher());
}
