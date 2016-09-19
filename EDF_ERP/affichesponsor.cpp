#include "affichesponsor.h"
#include "ui_affichesponsor.h"



AfficheSponsor::~AfficheSponsor()
{
    delete ui;
}


AfficheSponsor::AfficheSponsor(QWidget *parent, Sponsor& S, bool cas, int privilege) :
    QDialog(parent),
    ui(new Ui::AfficheSponsor)
{
    ui->setupUi(this);
    ui->ValIdSponsor->setText(QString::number(S.getIDSPONSOR()));
    ui->ValNomSponsor->setText(S.getNOMSPONSOR());
    ui->ValSommeSponsor->setText(QString::number(S.getSOMME()));
    ui->ValDureeSponsor->setText(QString::number(S.getDUREE()));
    ui->ValStatutSponsor->setText(QString::number(S.getSTATUT()));

    if (!cas)            //Affichage:false , Modification:true
    {
        setWindowTitle("Affichage");
        ui->EnregistrerSponsor->hide();
        ui->ValDureeSponsor->setEnabled(false);
/////////////////////////////////////////////////////////////////////////////////////////////////////
        ui->ValIdSponsor->setReadOnly(true);
        ui->ValNomSponsor->setReadOnly(true);
        ui->ValSommeSponsor->setReadOnly(true);
        ui->ValDateDebSponsor->setReadOnly(true);
        ui->ValDateFinSponsor->setReadOnly(true);
        ui->ValDureeSponsor->setReadOnly(true);
        ui->ValStatutSponsor->setReadOnly(true);
////////////////////////////////////////////////////////////////////////////////////////////////////////
        ui->ValIdSponsor->setStyleSheet("QLineEdit {border:0px; background:transparent;}");
        ui->ValNomSponsor->setStyleSheet("QLineEdit {border:0px; background:transparent;}");
        ui->ValSommeSponsor->setStyleSheet("QLineEdit {border:0px; background:transparent;}");
        ui->ValDateDebSponsor->setStyleSheet("QLineEdit {border:0px; background:transparent;}");
        ui->ValDateFinSponsor->setStyleSheet("QLineEdit {border:0px; background:transparent;}");
        ui->ValDureeSponsor->setStyleSheet("QLineEdit {border:0px; background:transparent;}");
        ui->ValStatutSponsor->setStyleSheet("QLineEdit {border:0px; background:transparent;}");
/////////////////////////////////////////////////////////////////////////////////////////////////////////
    }
    else if (cas)
    {
        setWindowTitle("Modification");
        ui->EnregistrerSponsor->show();
        ui->ValDureeSponsor->setEnabled(false);
/////////////////////////////////////////////////////////////////////////////////////////////////////
        ui->ValIdSponsor->setReadOnly(true);
        ui->ValNomSponsor->setReadOnly(false);
        ui->ValSommeSponsor->setReadOnly(false);
        ui->ValDateDebSponsor->setReadOnly(false);
        ui->ValDateFinSponsor->setReadOnly(false);
        ui->ValDureeSponsor->setReadOnly(false);
        if (privilege == 1) ui->ValStatutSponsor->setReadOnly(true);
        else ui->ValStatutSponsor->setReadOnly(false);
////////////////////////////////////////////////////////////////////////////////////////////////////////
        ui->ValIdSponsor->setToolTip("Identifiant");
        ui->ValNomSponsor->setToolTip("Nom du sponsor");
        ui->ValSommeSponsor->setToolTip("Somme à émettre");
        ui->ValDureeSponsor->setToolTip("Durée du contrat");
        ui->ValDateDebSponsor->setToolTip("Date du début");
        ui->ValDateFinSponsor->setToolTip("Date de la fin");
        ui->ValStatutSponsor->setToolTip("Statut 0.NV 1.V");
    }

}

void AfficheSponsor::on_EnregistrerSponsor_clicked()
{
    S.setIDSPONSOR(ui->ValIdSponsor->text().toInt());
    S.setNOMSPONSOR(ui->ValNomSponsor->text());
    S.setSOMME(ui->ValSommeSponsor->text().toDouble());
    S.setDATEDEBUT(ui->ValDateDebSponsor->text());
    S.setDATEFIN(ui->ValDateFinSponsor->text());
    S.setSTATUT(ui->ValStatutSponsor->text().toInt());
    if(!S.modifierSponsor()) QMessageBox::warning(this, "title", "non");

    S.calculerDuree();
    this->close();
}

