#include "affichepret.h"
#include "ui_affichepret.h"



      /*setStyleSheet("background:transparent");
      setAttribute(Qt::WA_TranslucentBackground);
      setWindowFlags(Qt::FramelessWindowHint);*/
    //ui->ValIdPret->setReadOnly(true);



AffichePret::AffichePret(QWidget *parent, Pret& P, bool cas, int privilege) :
    QDialog(parent),
    ui(new Ui::AffichePret)
{
    ui->setupUi(this);
    ui->ValIdPret->setText(QString::number(P.getIDPRET()));
    ui->ValBanPret->setText(P.getNOMBANQUE());
    ui->ValCausePret->setText(P.getCAUSE());
    ui->ValIntPret->setText(QString::number(P.getTINT()));
    ui->ValMntInitPret->setText(QString::number(P.getMONTPRET()));
    ui->ValMntFinalPret->setText(QString::number(P.getMONTF()));
    ui->ValDateDebPret->setText(P.getDatePretD());
    ui->ValDateFinPret->setText(P.getDatePretF());
    //ui->ValDureePret->setText(P.calculerDureePret());
    ui->ValStatutPret->setText(QString::number(P.getSTATUT()));
    ui->ValDureePret->setText(QString::number(P.calculerDureePret()));
    if (!cas)            //Affichage:false , Modification:true
    {
        setWindowTitle("Affichage");
        ui->EnregistrerPret->hide();
        /*ui->TextDureePret->show();
        ui->ValDureePret->show();
        ui->TextMntFinPret->show();
        ui->ValMntFinalPret->show();*/
/////////////////////////////////////////////////////////////////////////////////////////////////////
        ui->ValIdPret->setReadOnly(true);
        ui->ValBanPret->setReadOnly(true);
        ui->ValCausePret->setReadOnly(true);
        ui->ValIntPret->setReadOnly(true);
        ui->ValMntInitPret->setReadOnly(true);
        ui->ValMntFinalPret->setReadOnly(true);
        ui->ValDateDebPret->setReadOnly(true);
        ui->ValDateFinPret->setReadOnly(true);
        ui->ValDureePret->setReadOnly(true);
        ui->ValStatutPret->setReadOnly(true);
////////////////////////////////////////////////////////////////////////////////////////////////////////
        ui->ValIdPret->setStyleSheet("QLineEdit {border:0px; background:transparent;}");
        ui->ValBanPret->setStyleSheet("QLineEdit {border:0px; background:transparent;}");
        ui->ValCausePret->setStyleSheet("QLineEdit {border:0px; background:transparent;}");
        ui->ValIntPret->setStyleSheet("QLineEdit {border:0px; background:transparent;}");
        ui->ValMntInitPret->setStyleSheet("QLineEdit {border:0px; background:transparent;}");
        ui->ValMntFinalPret->setStyleSheet("QLineEdit {border:0px; background:transparent;}");
        ui->ValDateDebPret->setStyleSheet("QLineEdit {border:0px; background:transparent;}");
        ui->ValDateFinPret->setStyleSheet("QLineEdit {border:0px; background:transparent;}");
        ui->ValDureePret->setStyleSheet("QLineEdit {border:0px; background:transparent;}");
        ui->ValStatutPret->setStyleSheet("QLineEdit {border:0px; background:transparent;}");
/////////////////////////////////////////////////////////////////////////////////////////////////////////
    }
    else if (cas)
    {
        setWindowTitle("Modification");
        ui->EnregistrerPret->show();
        ui->TextDureePret->hide();
        ui->ValDureePret->hide();
        ui->TextMntFinPret->hide();
        ui->ValMntFinalPret->hide();
/////////////////////////////////////////////////////////////////////////////////////////////////////
        ui->ValIdPret->setReadOnly(true);
        ui->ValBanPret->setReadOnly(false);
        ui->ValCausePret->setReadOnly(false);
        ui->ValIntPret->setReadOnly(false);
        ui->ValMntInitPret->setReadOnly(false);
        ui->ValDateDebPret->setReadOnly(false);
        ui->ValDateFinPret->setReadOnly(false);
        if (privilege == 1) ui->ValStatutPret->setReadOnly(true);
        else ui->ValStatutPret->setReadOnly(false);
////////////////////////////////////////////////////////////////////////////////////////////////////////
        ui->ValIdPret->setToolTip("Identifiant");
        ui->ValBanPret->setToolTip("Nom de la banque");
        ui->ValCausePret->setToolTip("Cause");
        ui->ValIntPret->setToolTip("Intérêt");
        ui->ValMntInitPret->setToolTip("Montant initial");
        ui->ValDateDebPret->setToolTip("Date du début");
        ui->ValDateFinPret->setToolTip("Date de la fin");
        ui->ValStatutPret->setToolTip("Statut 0.NV 1.V");
    }

}

AffichePret::~AffichePret()
{
    delete ui;
}


void AffichePret::on_EnregistrerPret_clicked()
{
    /*if(ui->ValBanPret->text().isEmpty() || ui->ValBanPret->text().isEmpty() || ui->ValCausePret->text().isEmpty() || ui->ValIntPret->text().isEmpty() || ui->ValMntInitPret->text().isEmpty() || ui->ValMntFinalPret->text().isEmpty() || ui->ValDateDebPret->text().isEmpty() || ui->ValDateFinPret->text().isEmpty() || ui->ValStatutPret->text().isEmpty() || ui->ValIntPret->text().toInt() >= 100 || ui->ValStatutPret->text().toInt() != 1 || ui->ValStatutPret->text().toInt() != 0 )
    {
        QMessageBox::warning(this, "Vérifier", "Vérifiez vos champs!");
        ui->ValBanPret->setStyleSheet("{background:yellow;}");
    }*/

    if (ui->ValIntPret->text().toInt() > 100)  QMessageBox::warning(this, "Vérifier", "Vérifiez vos champs!");
   // if(P.calculerDureePret() == )
else{
    P.setIDPRET(ui->ValIdPret->text().toInt());
    P.setNOMBANQUE(ui->ValBanPret->text());
    P.setCAUSE(ui->ValCausePret->text());
    P.setTINT(ui->ValIntPret->text().toInt());
    P.setMONTPRET(ui->ValMntInitPret->text().toDouble());
    //P.setMONTF(P.calculerInteret(ui->ValMntInitPret->text().toDouble(), ui->ValIntPret->text().toInt()));
    P.calculerInteret();
    P.setDatePretD(ui->ValDateDebPret->text());
    P.setDatePretF(ui->ValDateFinPret->text());
    P.setSTATUT(ui->ValStatutPret->text().toInt());
    if(!P.modifierPret()) QMessageBox::warning(this, "title", "non");
        this->close();
        //else QMessageBox::warning(this, "Vérifier", "Vérifiez vos champs!");
}



}


