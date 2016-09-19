#include "remplirbd.h"
#include "ui_remplirbd.h"


RemplirBD::RemplirBD(QWidget *parent, int privilege) :
    QDialog(parent),
    ui(new Ui::RemplirBD)
{
    ui->setupUi(this);
    C.setPrivilege(privilege);
    if(privilege == 1)
    {
        ui->CheckValiderPret->setEnabled(false);
        ui->CheckValiderActionnaire->setEnabled(false);
        ui->CheckValiderSponsor->setEnabled(false);
        P.setSTATUT(false);
        S.setSTATUT(false);
        A.setSTATUT(false);
        ui->TextSaisieID->hide();
        ui->frame->hide();
        ui->lineIDPret->setToolTip("Identifiant");
        ui->lineBan->setToolTip("Nom de la banque");
        ui->lineMont->setToolTip("Montant initial");
        ui->lineInt->setToolTip("Intérêt");
        ui->TextCausePret->setToolTip("La cause");
        ui->dateDebutPret->setToolTip("Date du début");
        ui->dateFinPret->setToolTip("Date de la fin");
    }
    else
    {
        ui->CheckValiderPret->setEnabled(true);
        ui->CheckValiderActionnaire->setEnabled(true);
        ui->CheckValiderSponsor->setEnabled(true);
        P.setSTATUT(false);
        S.setSTATUT(false);
        A.setSTATUT(false);
        ui->TextSaisieID->hide();
        ui->frame->hide();
        ui->lineIDPret->setToolTip("Identifiant");
        ui->lineBan->setToolTip("Nom de la banque");
        ui->lineMont->setToolTip("Montant initial");
        ui->lineInt->setToolTip("Intérêt");
        ui->TextCausePret->setToolTip("La cause");
        ui->dateDebutPret->setToolTip("Date du début");
        ui->dateFinPret->setToolTip("Date de la fin");

    }

}

RemplirBD::~RemplirBD()
{
    delete ui;
}

void RemplirBD::ajoutPret()
{
        P.setIDPRET(ui->lineIDPret->text().toInt());
        P.setNOMBANQUE(ui->lineBan->text());
        P.setMONTPRET(ui->lineMont->text().toDouble());
        P.setTINT(ui->lineInt->text().toInt());
        P.setDatePretD(ui->dateDebutPret->text());
        P.setDatePretF(ui->dateFinPret->text());
        P.setCAUSE(ui->TextCausePret->toPlainText());
        P.calculerInteret();
        //P.setMONTF(P.calculerInteret(ui->lineMont->text().toDouble(), ui->lineInt->text().toInt()));
}

void RemplirBD::ajoutSponsor()
{
    S.setIDSPONSOR(ui->lineIDSponsor->text().toInt());
    S.setNOMSPONSOR(ui->lineNomSponsor->text());
    S.setSOMME(ui->lineSommeSponsor->text().toDouble());
    S.setDATEDEBUT(ui->dateDebutSponsor->text());
    S.setDATEFIN(ui->dateFinSponsor->text());
    S.calculerDuree ();

}
void RemplirBD::ajoutActionnaire()
{
    A.setIDACTIONNAIRE(ui->lineIDActionnaire->text().toInt());
    A.setNOMACTIONN(ui->lineNomActionnaire->text());
    A.setMNT(ui->lineSomActionnaire->text().toDouble());
    A.setTDIV(ui->lineDivActionnaire->text().toInt());
    A.setDATEACHAT(ui->dateAchatActionnaire->text());
}

void RemplirBD::on_CheckValiderPret_clicked(bool checked)
{

    if (checked)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Validation Pret", "La validation peut causer quelques problèmes pour l'entreprise\nVoulez-vous continuer", QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)P.setSTATUT(true);
        else  {
            ui->CheckValiderPret->setChecked(false);
            P.setSTATUT(false) ;
            }
    }

}

void RemplirBD::on_enregistrerPret_clicked()
{
   P.setIDPRET(ui->lineIDPret->text().toInt());
    if(ui->lineIDPret->text().isEmpty() || (ui->lineIDPret->text().toInt() == 0) || (ui->lineInt->text().toInt() > 100) || P.verifierExistencePret() )
    {
        ui->lineIDPret->setStyleSheet("QLineEdit{background:yellow;}");
        ui->frame->show();
        //ui->TextSaisieID->show();
        QMessageBox::information(this, "Verifier", "Vérifier vos champs");

    }
    else{
        ui->lineIDPret->setStyleSheet("QLineEdit{background:white;}");
        //ui->TextSaisieID->hide();
        ui->frame->hide();
        //ui->enregistrerPret->setEnabled(true);
        ajoutPret();
        if(P.ajouterPret()) QMessageBox::information(this, "Information", "Ajout éfféctué");
        else QMessageBox::warning(this, "Alerte", "Echec");
    }
}

void RemplirBD::on_VidPret_clicked()
{
    ui->lineIDPret->clear();
    ui->lineBan->clear();
    ui->lineMont->clear();
    ui->lineInt->clear();
    ui->TextCausePret->clear();
    ui->dateDebutPret->setDate(QDate(2000,01,01));
    ui->dateFinPret->setDate(QDate(2000,01,01));
    ui->CheckValiderPret->setChecked(false);
    ui->lineIDPret->setStyleSheet("QLineEdit{background:white;}");
    ui->frame->hide();

}

void RemplirBD::on_ApercuPret_clicked()
{
    ui->tabPretsAjout->setEnabled(true);
    remplirTabPret();
    //sound.playSoundButton();
}

void RemplirBD::remplirTabPret(){

            ui->tabPretsAjout->setEditTriggers(QAbstractItemView::NoEditTriggers);
            ui->tabPretsAjout->setModel(P.afficherHistoriquePret());
}
void RemplirBD::remplirTabSponsor(){

            ui->tabSponsorsAjout->setEditTriggers(QAbstractItemView::NoEditTriggers);
            ui->tabSponsorsAjout->setModel(S.afficherHistoriqueSponsor());
}
void RemplirBD::remplirTabActionnaire(){

            ui->tabActionnairesAjout->setEditTriggers(QAbstractItemView::NoEditTriggers);
            ui->tabActionnairesAjout->setModel(A.afficherHistoriqueActionnaire());
}

void RemplirBD::on_RefreshPret_clicked()
{
    remplirTabPret();
}


void RemplirBD::on_tabPretsAjout_doubleClicked(const QModelIndex &index)
{
    P.setIDPRET(index.data().toInt());
    if (!(P.afficherPret())) qDebug() << "Echec!";
    QMessageBox::StandardButton reply; // Affichage:false   Modification:true
    reply = QMessageBox::question(this, "Affiche/Modif", "Voulez-vous modifier ce prêt ?", QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::No)
    {
        AP = new AffichePret(this, P, false, C.getPrivilege());
        AP->show();
    }
    else
    {
        AP = new AffichePret(this, P, true, C.getPrivilege());
        AP->show();
    }

}

void RemplirBD::on_lineIDPret_cursorPositionChanged()
{
    P.setIDPRET(ui->lineIDPret->text().toInt());
    if (P.verifierExistencePret())
    {
        ui->lineIDPret->setStyleSheet("QLineEdit{background:yellow;}");
        ui->frame->show();
    }
    else
    {
        ui->lineIDPret->setStyleSheet("QLineEdit{background:white;}");
        ui->frame->hide();
    }
}

void RemplirBD::on_enregistrerSponsor_clicked()
{
    if(ui->lineIDSponsor->text().isEmpty() || (ui->lineIDSponsor->text().toInt() == 0) || S.verifierExistenceSponsor())
    {
        ui->lineIDSponsor->setStyleSheet("QLineEdit{background:yellow;}");
        //ui->frame->show();
        //ui->TextSaisieID->show();
        QMessageBox::information(this, "Verifier", "Vérifier vos champs");

    }
    else{
        ui->lineIDSponsor->setStyleSheet("QLineEdit{background:white;}");
        //ui->TextSaisieID->hide();
        //ui->frame->hide();
        //ui->enregistrerPret->setEnabled(true);
        ajoutSponsor();
        if(S.ajouterSponsor()) QMessageBox::information(this, "Information", "Ajout éfféctué");
        else QMessageBox::warning(this, "Alerte", "Echec");
    }

}

void RemplirBD::on_ApercuSponsor_clicked()
{
    ui->tabSponsorsAjout->setEnabled(true);
    remplirTabSponsor();
    //QSound *S = new QSound ("C:/Users/Cruzer/Downloads/switch-3.wav");
    //S->play();
}

void RemplirBD::on_RefreshSponsor_clicked()
{
    remplirTabSponsor();
}

void RemplirBD::on_CheckValiderSponsor_clicked(bool checked)
{
    if (checked)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Validation Sponsor", "La validation peut causer quelques problèmes pour l'entreprise\nVoulez-vous continuer", QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)S.setSTATUT(true);
        else  {
            ui->CheckValiderSponsor->setChecked(false);
            S.setSTATUT(false) ;
            }
    }
}

void RemplirBD::on_VidSponsor_clicked()
{
    ui->lineIDSponsor->clear();
    ui->lineIDSponsor->setStyleSheet("QLineEdit{background:white;}");
    ui->lineNomSponsor->clear();
    ui->lineSommeSponsor->clear();
    ui->dateDebutSponsor->setDate(QDate(2000,01,01));
    ui->dateFinSponsor->setDate(QDate(2000,01,01));
    ui->CheckValiderSponsor->setChecked(false);
}

void RemplirBD::on_lineIDSponsor_cursorPositionChanged()
{
    S.setIDSPONSOR(ui->lineIDSponsor->text().toInt());
    if (S.verifierExistenceSponsor())
    {
        ui->lineIDSponsor->setStyleSheet("QLineEdit{background:yellow;}");
    }
    else
    {
        ui->lineIDSponsor->setStyleSheet("QLineEdit{background:white;}");
    }
}

void RemplirBD::on_CheckValiderActionnaire_clicked(bool checked)
{
    if (checked)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Validation Actionnaire", "La validation peut causer quelques problèmes pour l'entreprise\nVoulez-vous continuer", QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)A.setSTATUT(true);
        else  {
            ui->CheckValiderActionnaire->setChecked(false);
            A.setSTATUT(false) ;
            }
    }
}

void RemplirBD::on_ApercuActionnaire_clicked()
{
    ui->tabActionnairesAjout->setEnabled(true);
    remplirTabActionnaire();
    //QSound *S = new QSound ("C:/Users/Cruzer/Downloads/switch-3.wav");
    //S->play();
}

void RemplirBD::on_RefreshActionnaire_clicked()
{
    remplirTabActionnaire();
}

void RemplirBD::on_VidActionnaire_clicked()
{
    ui->lineIDActionnaire->clear();
    ui->lineIDActionnaire->setStyleSheet("QLineEdit{background:white;}");
    ui->lineNomActionnaire->clear();
    ui->lineSomActionnaire->clear();
    ui->lineDivActionnaire->clear();
    ui->dateAchatActionnaire->setDate(QDate(2000,01,01));
    ui->CheckValiderActionnaire->setChecked(false);
}

void RemplirBD::on_enregistrerActionnaire_clicked()
{
    if(ui->lineIDActionnaire->text().isEmpty() || (ui->lineIDActionnaire->text().toInt() == 0) || A.verifierExistenceActionnaire())
    {
        ui->lineIDActionnaire->setStyleSheet("QLineEdit{background:yellow;}");
        //ui->frame->show();
        //ui->TextSaisieID->show();
        QMessageBox::information(this, "Verifier", "Vérifier vos champs");

    }
    else{
        ui->lineIDActionnaire->setStyleSheet("QLineEdit{background:white;}");
        //ui->TextSaisieID->hide();
        //ui->frame->hide();
        //ui->enregistrerPret->setEnabled(true);
        ajoutActionnaire();
        if(A.ajouterActionnaire()) QMessageBox::information(this, "Information", "Ajout éfféctué");
        else QMessageBox::warning(this, "Alerte", "Echec");
    }
}

void RemplirBD::on_lineIDActionnaire_cursorPositionChanged()
{
    A.setIDACTIONNAIRE(ui->lineIDActionnaire->text().toInt());
    if (A.verifierExistenceActionnaire())
    {
        ui->lineIDActionnaire->setStyleSheet("QLineEdit{background:yellow;}");
    }
    else
    {
        ui->lineIDActionnaire->setStyleSheet("QLineEdit{background:white;}");
    }
}



void RemplirBD::on_tabActionnairesAjout_doubleClicked(const QModelIndex &index)
{
    A.setIDACTIONNAIRE(index.data().toInt());
    if (!(A.afficherActionnaire())) qDebug() << "Echec!";
    QMessageBox::StandardButton reply; // Affichage:false   Modification:true
    reply = QMessageBox::question(this, "Affiche/Modif", "Voulez-vous modifier cet actionnaire ?", QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::No)
    {
        AA = new AfficheActionnaire(this, A, false, C.getPrivilege());
        AA->show();
    }
    else
    {
        AA = new AfficheActionnaire(this, A, true, C.getPrivilege());
        AA->show();
    }

}

void RemplirBD::on_tabSponsorsAjout_doubleClicked(const QModelIndex &index)
{
    S.setIDSPONSOR(index.data().toInt());
    if (!(S.afficherSponsor())) qDebug() << "Echec!";
    QMessageBox::StandardButton reply; // Affichage:false   Modification:true
    reply = QMessageBox::question(this, "Affiche/Modif", "Voulez-vous modifier ce sponsor ?", QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::No)
    {
        AS = new AfficheSponsor(this, S, false, C.getPrivilege());
        AS->show();
    }
    else
    {
        AS = new AfficheSponsor(this, S, true, C.getPrivilege());
        AS->show();
    }
}

