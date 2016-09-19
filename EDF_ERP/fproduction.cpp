#include "fproduction.h"
#include "ui_fproduction.h"
#include "fajoutprod.h"
#include <QMessageBox>
#include <QComboBox>
#include <QDebug>
Fproduction::Fproduction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Fproduction)
{
    ui->setupUi(this);
    refreshComboProd();
}

Fproduction::~Fproduction()
{
    delete ui;
}

void Fproduction::refreshComboProd()
{

    ui->prod_combo->setModel(Prod.afficherTypeProd());

    ui->combo_projet->setModel(P->afficherTypeProjet());

    ui->combo_site->setModel(S.afficherSiteProd());

    ui->combo_resp->setModel(Resp->extractResponsable());
}


void Fproduction::on_but_refresh_commande_clicked()
{

    ui->tableView_proj->setModel(P->afficherProduits());

    refreshComboProd();
}

void Fproduction::on_commande_text_cursorPositionChanged()
{
    if (ui->commande_text->text() == "" || ui->commande_text->text().toInt()==0)
    {
        ui->commande_text->setStyleSheet("QLineEdit{background: yellow;}");
        ui->combo_resp->setEnabled(false);
        ui->combo_site->setEnabled(false);
        ui->prod_combo->setEnabled(false);
        ui->date_commande->setEnabled(false);
        ui->combo_etat->setEnabled(false);
        ui->but_confirmer_commande->setEnabled(false);
        ui->combo_projet->setEnabled(false);
    }
    else if (P->testExistance(ui->commande_text->text().toInt())->isValid())
    {
        ui->commande_text->setStyleSheet("QLineEdit{background: red;}");
        QMessageBox::warning(this,"Warning", "Existe déja mais pas encore validé!");
    }


    else if(P->testExistanceConfirmee(ui->commande_text->text().toInt())->isValid())
    {
        ui->commande_text->setStyleSheet("QLineEdit{background: red;}");
        QMessageBox::StandardButton rep;
        rep = QMessageBox::information(this, "Notification", "Cette commande a été confirmee, voulez-vous la lancer?", QMessageBox::Yes|QMessageBox::No);
        if (rep== QMessageBox::Yes)
        {
            P->changerEtat(ui->commande_text->text().toInt());
            ui->commande_text->clear();
        }
        else
        {
            ui->commande_text->clear();
        }
    }
    else
    {
        ui->commande_text->setStyleSheet("QLineEdit{background: white;}");
        ui->combo_resp->setEnabled(true);
        ui->combo_site->setEnabled(true);
        ui->prod_combo->setEnabled(true);
        ui->date_commande->setEnabled(true);
        ui->combo_projet->setEnabled(true);
        ui->but_confirmer_commande->setEnabled(true);
    }
}


void Fproduction::on_but_ajout_clicked()
{
    FajoutProd Ajout;
    Ajout.setModal(true);
    Ajout.exec();
}


void Fproduction::on_but_confirmer_commande_clicked()
{
    P = new Production();

    P->setIdCommande(ui->commande_text->text().toLong());
    P->setIdProduit(ui->prod_combo->currentText());
    P->setDate(ui->date_commande->text());
    P->setResponsable(ui->combo_resp->currentText());
    P->setSiteProd(ui->combo_site->currentText());
    P->setIdProjet(ui->combo_projet->currentText().toLong());
    P->setSTATUT(ui->combo_etat->currentText());

    P->AjoutCommande();


}
