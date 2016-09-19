
#include "interface_paie_rh.h"
#include "paie.h"
#include "ui_interface_paie_rh.h"


Interface_Paie_RH::Interface_Paie_RH(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Interface_Paie_RH)
{
    ui->setupUi(this);
    ui->tableView_paie->setModel(P.afficher());
    ui->combo_id_emp->setModel(E.extraireListeEmp());
}

Interface_Paie_RH::~Interface_Paie_RH()
{
    delete ui;
}
void Interface_Paie_RH::on_pushButton_bull_verifier_clicked()
{
    P.setidBulletin(ui->lineEdit_bull_id->text().toInt());
    if(P.verifier_id())
    {
        QString emp = QString::number(P.getidEmploye());
        ui->combo_id_emp->setCurrentText(emp);
        ui->lineEdit_bull_periode->setText(P.getperiode());
        ui->doubleSpinBox_bull_fixe->setValue(P.getsalaire_fixe());
        ui->doubleSpinBox_bull_hs->setValue(P.getheure_supp());
        ui->doubleSpinBox_bull_abs->setValue(P.getabsence());
        ui->doubleSpinBox_bull_prime->setValue(P.getprime());
        ui->doubleSpinBox_bull_co->setValue(P.getcotisations());
        ui->doubleSpinBox_bull_csg->setValue(P.getCSG_deductible());
        ui->doubleSpinBox_1bull_csgnon->setValue(P.getCSG_nondeductible());
        if(P.getetat())
        {
            ui->comboBox_bull_etat->setCurrentText("Payee");
        }else
        {
            ui->comboBox_bull_etat->setCurrentText("Non payee");
        }
        QMessageBox::information(this,"","Existe");
        QMessageBox::StandardButton reply;
        reply=QMessageBox::question(this,"Export PDF","Voulez-vous exporter cette donnee en format PDF ?");
        if(reply==QMessageBox::Yes)
        {
            P.export_pdf();
        }
    }else{QMessageBox::information(this,"","N'existe pas");}
}
void Interface_Paie_RH::on_pushButton_bull_ajouter_clicked()
{
    P.setidBulletin(ui->lineEdit_bull_id->text().toInt());
    P.setidEmploye(ui->combo_id_emp->currentText().toInt());
    P.setperiode(ui->lineEdit_bull_periode->text());
    P.setsalaire_fixe(ui->doubleSpinBox_bull_fixe->value());
    P.setheure_supp(ui->doubleSpinBox_bull_hs->value());
    P.setabsence(ui->doubleSpinBox_bull_abs->value());
    P.setprime(ui->doubleSpinBox_bull_prime->value());
    P.setcotisation(ui->doubleSpinBox_bull_co->value());
    P.setCSG_deductible(ui->doubleSpinBox_bull_csg->value());
    P.setCSG_nondeductible(ui->doubleSpinBox_1bull_csgnon->value());
    P.setCRDS(ui->doubleSpinBox_bull_crds->value());
    if(ui->comboBox_bull_etat->currentText()=="Payee")
    {
        P.setetat(true);
    }else{P.setetat(false);}
    P.ajouter();
}
void Interface_Paie_RH::on_pushButton_bull_modifier_clicked()
{
    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(this,"Demande de modification","Voulez-vous modifier cette donnee ?");
    if(reply==QMessageBox::Yes)
    {
    P.setidBulletin(ui->lineEdit_bull_id->text().toInt());
    P.setidEmploye(ui->combo_id_emp->currentText().toInt());
    P.setperiode(ui->lineEdit_bull_periode->text());
    P.setsalaire_fixe(ui->doubleSpinBox_bull_fixe->value());
    P.setheure_supp(ui->doubleSpinBox_bull_hs->value());
    P.setabsence(ui->doubleSpinBox_bull_abs->value());
    P.setprime(ui->doubleSpinBox_bull_prime->value());
    P.setcotisation(ui->doubleSpinBox_bull_co->value());
    P.setCSG_deductible(ui->doubleSpinBox_bull_csg->value());
    P.setCSG_nondeductible(ui->doubleSpinBox_1bull_csgnon->value());
    P.setCRDS(ui->doubleSpinBox_bull_crds->value());
    if(ui->comboBox_bull_etat->currentText()=="Payee")
    {
        P.setetat(true);
    }else{P.setetat(false);}
    P.modifier();
    }
}


void Interface_Paie_RH::on_pushButton_bull_supp_clicked()
{
    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(this,"Demande de suppression","Voulez-vous supprimer cette donnee ?");
    if(reply==QMessageBox::Yes)
    {
    P.setidBulletin(ui->lineEdit_bull_id->text().toInt());
    P.supprimer();
    }
}
void Interface_Paie_RH::on_pushButton_paie_actualiser_clicked()
{
    ui->tableView_paie->setModel(P.afficher());
}


