#ifndef VALIDER_H
#define VALIDER_H

#include <QTableWidget>
#include <QMessageBox>
#include <QMainWindow>
#include <QString>

#include "budget.h"
#include "remplirbd.h"
#include "prets.h"
#include "actionnaire.h"
#include "sponsor.h"
#include "commande.h"
#include "paie.h"
#include "matierep.h"
#include "produit.h"
#include "projets.h"
#include "contrats.h"
#include "pub.h"
#include "reparation.h"
#include "connexion.h"
#include "messages.h"
#include "mail.h"

namespace Ui {
class Valider;
}

class Valider : public QMainWindow
{
    Q_OBJECT

public:

    QString name_connected;

    explicit Valider(QWidget *parent = 0);
    //explicit Valider(QWidget *parent , int privilege);
    explicit Valider(QWidget *parent , Connexion& );
    void remplirTabPret();
    void remplirTabActionnaire();
    void remplirTabSponsor();
    void remplirTabPaie();
    void remplirTabContrat();
    void remplirTabCommande();
    void remplirTabDevis();
    void remplirTabPub();
    void remplirTabProjet();
    void remplirTabRep();
    void remplirTabProdProduction();
    void remplirTabProdVente();
    ~Valider();


private slots:
    void on_actionAjouter_triggered();

    void on_validerButton_clicked();

    void on_RefuserButton_clicked();

    void on_Refuser_ttButton_clicked();

    void on_validerButtonProjet_clicked();

    void on_validerButtonPub_clicked();

    void on_validerButtonSponsor_clicked();

    void on_validerButtonAction_clicked();

    void on_validerButtonDevis_clicked();

    void on_validerButtonComm_clicked();

    void on_Valider_ttButtonContrat_clicked();

    void on_validerButtonContrat_clicked();

    void on_validerButtonPaie_clicked();

    void on_validerButtonRep_clicked();

    void on_validerButtonProd_clicked();

    void on_validerButtonVente_clicked();

    void refreshBudGlob();
    void refreshMntRev();
    void refreshMntDep();

    void refreshAll();

    void on_actionMessage_s_triggered();

    void on_actionE_Mail_triggered();

    void on_actionFermer_triggered();

private:
    Ui::Valider *ui;
    RemplirBD *R;
    Pret P;
    Actionnaire A;
    Sponsor S;
    Commande C;
    MatiereP MP;
    Produit Prod;
    Projet PJ;
    Contrat CT;
    Pub PB;
    Paie PE;
    Budget B;
    Reparation Rep;
    Messagerie *M;
    Mail *mail;
    Connexion Conn;
};

#endif // VALIDER_H
