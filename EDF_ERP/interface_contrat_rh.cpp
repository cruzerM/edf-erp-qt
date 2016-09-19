
#include "interface_contrat_rh.h"
#include "contrats.h"
#include "ui_interface_contrat_rh.h"




Interface_Contrat_RH::Interface_Contrat_RH(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Interface_Contrat_RH)
{
    ui->setupUi(this);
    ui->tableView_contrat->setModel(C.afficher());
    ui->combo_id_emp->setModel(E.extraireListeEmp());
}

Interface_Contrat_RH::~Interface_Contrat_RH()
{
    delete ui;
}

void Interface_Contrat_RH::on_pushButton_contrat_verifier_clicked()
{   
     C.setidContrat(ui->lineEdit_cont_id->text().toInt());
     if(C.verifier_id())
     {
         QString employe = QString::number(C.getidEmploye());
         ui->combo_id_emp->setCurrentText(employe);
         ui->lineEdit_contrat_date_debut->setText(C.getdate_debut());
         ui->lineEdit_contrat_date_fin->setText(C.getdate_fin());
         ui->spinBox_contrat_duree->setValue(C.getduree_contrat());
         ui->comboBox_contrat_type->setCurrentText(C.gettype_contrat());
         ui->doubleSpinBox_contrat_montant->setValue(C.getmontant());
         ui->comboBox_contrat_rup->setCurrentText(C.gettype_rupture());
         ui->doubleSpinBox_contrat_indem->setValue(C.getindemnite());
         if(C.getetat_contrat())
         {
             ui->comboBox_contrat_etat->setCurrentText("En cours");
         }else{ui->comboBox_contrat_etat->setCurrentText("Acheve");}
         if(C.getstatut())
         {
             ui->comboBox_contrat_statut->setCurrentText("Payee");
         }else{ui->comboBox_contrat_statut->setCurrentText("Non payee");}
         QMessageBox::information(this,"","Existe");
     }else{QMessageBox::information(this,"","N'existe pas");}
}
void Interface_Contrat_RH::on_pushButton_contrat_ajouter_clicked()
{
    C.setidContrat(ui->lineEdit_cont_id->text().toInt());
    C.setidEmploye(ui->combo_id_emp->currentText().toInt());
    C.setdate_debut(ui->lineEdit_contrat_date_debut->text());
    C.setdate_fin(ui->lineEdit_contrat_date_fin->text());
    C.setduree_contrat(ui->spinBox_contrat_duree->value());
    C.setmontant(ui->doubleSpinBox_contrat_montant->value());
    C.setindemnite(ui->doubleSpinBox_contrat_indem->value());
    C.settype_rupture(ui->comboBox_contrat_rup->currentText());
    C.settype_contrat(ui->comboBox_contrat_type->currentText());
    if(ui->comboBox_contrat_etat->currentText()=="En cours")
    {
        C.setetat_contrat(true);
    }else{C.setetat_contrat(false);}
    if(ui->comboBox_contrat_statut->currentText()=="Payee")
    {
        C.setstatut(true);
    }else{C.setstatut(false);}
    C.ajouter();
}
void Interface_Contrat_RH::on_pushButton_contrat_modifier_clicked()
{
    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(this,"Demande de modification","Voulez-vous modifier cette donnee ?");
    if(reply==QMessageBox::Yes)
    {
    C.setidContrat(ui->lineEdit_cont_id->text().toInt());
    C.setidEmploye(ui->combo_id_emp->currentText().toInt());
    C.setdate_debut(ui->lineEdit_contrat_date_debut->text());
    C.setdate_fin(ui->lineEdit_contrat_date_fin->text());
    C.setduree_contrat(ui->spinBox_contrat_duree->value());
    C.setmontant(ui->doubleSpinBox_contrat_montant->value());
    C.setindemnite(ui->doubleSpinBox_contrat_indem->value());
    C.settype_rupture(ui->comboBox_contrat_rup->currentText());
    C.settype_contrat(ui->comboBox_contrat_type->currentText());
    if(ui->comboBox_contrat_etat->currentText()=="En cours")
    {
        C.setetat_contrat(true);
    }else{C.setetat_contrat(false);}
    if(ui->comboBox_contrat_statut->currentText()=="Payee")
    {
        C.setstatut(true);
    }else{C.setstatut(false);}
    C.modifier();
    }
}
void Interface_Contrat_RH::on_pushButton_contrat_supprimer_clicked()
{
    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(this,"Demande de suppression","Voulez-vous supprimer cette donnee ?");
    if(reply==QMessageBox::Yes)
    {
    C.setidContrat(ui->lineEdit_cont_id->text().toInt());
    C.supprimer();
    }
}
void Interface_Contrat_RH::on_pushButton_contrat_afficher_clicked()
{
ui->tableView_contrat->setModel(C.afficher());
}
