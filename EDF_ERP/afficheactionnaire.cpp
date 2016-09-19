#include "afficheactionnaire.h"
#include "ui_afficheactionnaire.h"


AfficheActionnaire::AfficheActionnaire(QWidget *parent, Actionnaire& A, bool cas, int privilege) :
    QDialog(parent),
    ui(new Ui::AfficheActionnaire)
{
    ui->setupUi(this);
    ui->ValIdActionnaire->setText(QString::number(A.getIDACTIONNAIRE()));
    ui->ValNomActionnaire->setText(A.getNOMACTIONN());
    ui->ValMntActionnaire->setText(QString::number(A.getMNT()));
    ui->ValTDActionnaire->setText(QString::number(A.getTDIV()));
    ui->ValDActionnaire->setText(QString::number(A.calculerDividende()));
    ui->ValDAActionnaire->setText(A.getDATEACHAT());
    ui->ValDureeActionnaire->setText(QString::number(A.calculerDuree()));
    ui->ValStatutActionnaire->setText(QString::number(A.getSTATUT()));

    if (!cas)            //Affichage:false , Modification:true
    {
        setWindowTitle("Affichage");

        ui->EnregistrerActionnaire->hide();
        ui->ValDureeActionnaire->setEnabled(false);
/////////////////////////////////////////////////////////////////////////////////////////////////////
        ui->ValIdActionnaire->setReadOnly(true);
        ui->ValNomActionnaire->setReadOnly(true);
        ui->ValTDActionnaire->setReadOnly(true);
        ui->ValMntActionnaire->setReadOnly(true);
        ui->ValDActionnaire->setReadOnly(true);
        ui->ValDAActionnaire->setReadOnly(true);
        ui->ValStatutActionnaire->setReadOnly(true);
////////////////////////////////////////////////////////////////////////////////////////////////////////
        ui->ValIdActionnaire->setStyleSheet("QLineEdit {border:0px; background:transparent;}");
        ui->ValNomActionnaire->setStyleSheet("QLineEdit {border:0px; background:transparent;}");
        ui->ValTDActionnaire->setStyleSheet("QLineEdit {border:0px; background:transparent;}");
        ui->ValMntActionnaire->setStyleSheet("QLineEdit {border:0px; background:transparent;}");
        ui->ValDActionnaire->setStyleSheet("QLineEdit {border:0px; background:transparent;}");
        ui->ValDAActionnaire->setStyleSheet("QLineEdit {border:0px; background:transparent;}");
        ui->ValDureeActionnaire->setStyleSheet("QLineEdit {border:0px; background:transparent;}");
        ui->ValStatutActionnaire->setStyleSheet("QLineEdit {border:0px; background:transparent;}");
/////////////////////////////////////////////////////////////////////////////////////////////////////////
    }
    else if (cas)
    {
        setWindowTitle("Modification");
        ui->EnregistrerActionnaire->show();
        ui->ValDureeActionnaire->setEnabled(false);
        ui->ValDActionnaire->setEnabled(false);
/////////////////////////////////////////////////////////////////////////////////////////////////////
        ui->ValIdActionnaire->setReadOnly(true);
        ui->ValNomActionnaire->setReadOnly(false);
        ui->ValTDActionnaire->setReadOnly(false);
        ui->ValMntActionnaire->setReadOnly(false);
        ui->ValDAActionnaire->setReadOnly(false);
        if (privilege == 1) ui->ValStatutActionnaire->setReadOnly(true);
        else ui->ValStatutActionnaire->setReadOnly(false);
////////////////////////////////////////////////////////////////////////////////////////////////////////
        ui->ValIdActionnaire->setToolTip("Identifiant");
        ui->ValNomActionnaire->setToolTip("Nom Actionnaire");
        ui->ValTDActionnaire->setToolTip("Taux de la dividende");
        ui->ValMntActionnaire->setToolTip("Montant à émettre");
        ui->ValDActionnaire->setToolTip("Dividende");
        ui->ValDAActionnaire->setToolTip("Date d'achat");
        ui->ValStatutActionnaire->setToolTip("Statut 0.NV 1.V");
    }


}

AfficheActionnaire::~AfficheActionnaire()
{
    delete ui;
}



void AfficheActionnaire::on_EnregistrerActionnaire_clicked()
{
    A.setIDACTIONNAIRE(ui->ValIdActionnaire->text().toInt());
    A.setNOMACTIONN(ui->ValNomActionnaire->text());
    A.setMNT(ui->ValMntActionnaire->text().toDouble());
    A.setTDIV(ui->ValTDActionnaire->text().toInt());
    A.setDATEACHAT(ui->ValDAActionnaire->text());
    A.setSTATUT(ui->ValStatutActionnaire->text().toInt());
    if(!A.modifierActionnaire()) QMessageBox::warning(this, "Echec", "Echéc");

    this->close();
}
