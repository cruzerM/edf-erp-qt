#include "valider.h"
#include "ui_valider.h"

Valider::Valider(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Valider)
{
    ui->setupUi(this);
}

Valider::Valider(QWidget *parent , Connexion& C) :
    QMainWindow(parent),
    ui(new Ui::Valider)
{
ui->setupUi(this);
Conn = C;

name_connected = Conn.getLogin();
///////////////////////////////////////////////////////
QTimer* mTimer;
mTimer = new QTimer(this);
mTimer->start(5000);
mTimer->setSingleShot(false);

connect(mTimer, SIGNAL(timeout()), SLOT(refreshAll()));



////////////////////////////////////////////////////////
ui->ValRev->setStyleSheet("QLabel{color:green;}");
ui->ValDep->setStyleSheet("QLabel{color:red;}");

if (Conn.getPrivilege() == 1)
{
    ui->prets->setEnabled(false);
    ui->actionnaires->setEnabled(false);
    ui->produits->setEnabled(false);
    ui->sponsors->setEnabled(false);
    ui->projets->setEnabled(false);
    ui->publicites->setEnabled(false);
    ui->commandes->setEnabled(false);
    ui->tabWidget->setTabEnabled(0, false);
    ui->tabWidget->setTabEnabled(1, false);
    ui->tabWidget->setTabEnabled(2, false);
    ui->tabWidget->setTabEnabled(3, false);
    ui->tabWidget->setTabEnabled(4, false);
    ui->tabWidget->setTabEnabled(5, false);
    ui->tabWidget->setTabEnabled(6, false);
    remplirTabContrat();
    remplirTabPaie();
}
else
{
    ui->prets->setEnabled(true);
    ui->actionnaires->setEnabled(true);
    ui->produits->setEnabled(true);
    ui->sponsors->setEnabled(true);
    ui->projets->setEnabled(true);
    ui->publicites->setEnabled(true);
    ui->commandes->setEnabled(true);
    remplirTabPret();
    remplirTabActionnaire();
    remplirTabCommande();
    remplirTabContrat();
    remplirTabDevis();
    remplirTabPaie();
    remplirTabProjet();
    remplirTabPub();
    remplirTabSponsor();
    remplirTabRep();
    remplirTabProdProduction();
    remplirTabProdVente();
}

}

void Valider::refreshBudGlob()
{
    ui->ValBudGlob->setText(B.calculerBudgetGlobal());
}

void Valider::refreshMntRev()
{
    ui->ValRev->setText(B.afficherRevenus());
}

void Valider::refreshMntDep()
{
    ui->ValDep->setText(B.afficherDepenses());
}

void Valider::refreshAll()
{
    remplirTabPret();
    remplirTabActionnaire();
    remplirTabCommande();
    remplirTabContrat();
    remplirTabDevis();
    remplirTabPaie();
    remplirTabProjet();
    remplirTabPub();
    remplirTabSponsor();
    remplirTabRep();
    remplirTabProdProduction();
    remplirTabProdVente();

    refreshBudGlob();
    refreshMntDep();
    refreshMntRev();
}

Valider::~Valider()
{
    delete ui;
}

void Valider::on_actionAjouter_triggered()
{
    R = new RemplirBD(this, Conn.getPrivilege());
    R->show();
}

void Valider::remplirTabPret()
{
    ui->tabPrets->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tabPrets->setModel(P.afficherPretsNV());
}




void Valider::on_validerButton_clicked()
{
    QModelIndexList indexes = ui->tabPrets->selectionModel()->selection().indexes();
    for( int i=0; i<indexes.count(); i++){
        QModelIndex index = indexes.at(i);
        if (index.column() == 0) P.setIDPRET(index.data().toInt());
        if(index.column() == 5)
        {
            if(index.data().toInt() == 0) {
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Verification validation", "Cette validation peut causer des problèmes à l'entreprise\n Valider quand même ?", QMessageBox::Yes | QMessageBox::No);
                if (reply == QMessageBox::No) break;
                else{
                P.setSTATUT(true);
                if (!(P.validerPret())) QMessageBox::warning(this, "Validation", "Echec validation!");
                else QMessageBox::warning(this, "Validation", "Succès validation!");
                 }
                }

        }
    }
    remplirTabPret();
}

void Valider::on_RefuserButton_clicked()
{
    QModelIndexList indexes = ui->tabPrets->selectionModel()->selection().indexes();
    for( int i=0; i<indexes.count(); i++){
        QModelIndex index = indexes.at(i);
        if (index.column() == 0) P.setIDPRET(index.data().toInt());
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Verification Suppression", "Cette suppression peut causer des problèmes à l'entreprise\n Supprimer quand même ?", QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::No) break;
        else {
                if (!(P.supprimerPret())) QMessageBox::warning(this, "Suppression", "Echec Suppression!");
                else {QMessageBox::warning(this, "Suppression", "Succès Suppression!");break;}
                }

    }
    remplirTabPret();

}

void Valider::on_Refuser_ttButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Verification Suppression", "Cette suppression peut causer des problèmes à l'entreprise\n Supprimer quand même ?", QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::No) return;
        else {
                if (!(P.supprimerTTPret())) QMessageBox::warning(this, "Suppression", "Echec Suppression!");
                else QMessageBox::warning(this, "Suppression", "Succès Suppression!");
                }


    remplirTabPret();

}
///////////////////////////////////////////////////////////////////////////////////
void Valider::remplirTabActionnaire()
{
    ui->tabActionnaires->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tabActionnaires->setModel(A.afficherActionnaireNV());
}

void Valider::remplirTabSponsor()
{
    ui->tabSponsors->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tabSponsors->setModel(S.afficherSponsorNV());
}

void Valider::remplirTabPaie()
{
    ui->tabPaie->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tabPaie->setModel(PE.afficherPaieNV());
}

void Valider::remplirTabContrat()
{
    ui->tabContrats->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tabContrats->setModel(CT.afficherContratsNV());
}

void Valider::remplirTabCommande()
{
    ui->tabCommandes->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tabCommandes->setModel(C.afficherCommandesNV());
}

void Valider::remplirTabDevis()
{
    ui->tabDevis->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tabDevis->setModel(MP.afficherDevisNV());
}

void Valider::remplirTabPub()
{
    ui->tabPubs->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tabPubs->setModel(PB.afficherPubsNV());
}

void Valider::remplirTabProjet()
{
    ui->tabProjets->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tabProjets->setModel(PJ.afficherProjetsNV());
}
void Valider::remplirTabRep()
{
    ui->tabReparation->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tabReparation->setModel(Rep.afficherReparationNV());
}

void Valider::remplirTabProdProduction()
{
    ui->tabProduction->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tabProduction->setModel(Prod.afficherProduitsProdNV());
}

void Valider::remplirTabProdVente()
{
    ui->tabVente->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tabVente->setModel(Prod.afficherProduitsVenteNV());
}
/////////////////////////////////////////////////////////////////////////////////////

void Valider::on_validerButtonProjet_clicked()
{
    QModelIndexList indexes = ui->tabProjets->selectionModel()->selection().indexes();
    for( int i=0; i<indexes.count(); i++){
        QModelIndex index = indexes.at(i);


        if (index.column() == 0) PJ.setIDPROJET(index.data().toInt());

        if(index.column() == 2)
        {
            if(index.data().toInt() == 0) {
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Verification validation", "Cette validation peut causer des problèmes à l'entreprise\n Valider quand même ?", QMessageBox::Yes | QMessageBox::No);
                if (reply == QMessageBox::No) break;
                else{
                PJ.setSTATUT(true);
                if (!(PJ.validerBudgetProjet())) QMessageBox::warning(this, "Validation", "Echec validation!");
                else QMessageBox::warning(this, "Validation", "Succès validation!");
                 }
                }

        }
    }
    remplirTabProjet();

}

void Valider::on_validerButtonPub_clicked()
{
    QModelIndexList indexes = ui->tabPubs->selectionModel()->selection().indexes();
    for( int i=0; i<indexes.count(); i++){
        QModelIndex index = indexes.at(i);


        if (index.column() == 0) PB.setIDPUB(index.data().toInt());

        if(index.column() == 2)
        {
            if(index.data().toInt() == 0) {
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Verification validation", "Cette validation peut causer des problèmes à l'entreprise\n Valider quand même ?", QMessageBox::Yes | QMessageBox::No);
                if (reply == QMessageBox::No) break;
                else{
                PB.setSTATUT(true);
                if (!(PB.validerCoutPub())) QMessageBox::warning(this, "Validation", "Echec validation!");
                else QMessageBox::warning(this, "Validation", "Succès validation!");
                 }
                }

        }
    }
    remplirTabPub();

}

void Valider::on_validerButtonSponsor_clicked()
{
    QModelIndexList indexes = ui->tabSponsors->selectionModel()->selection().indexes();
    for( int i=0; i<indexes.count(); i++){
        QModelIndex index = indexes.at(i);


        if (index.column() == 0) S.setIDSPONSOR(index.data().toInt());

        if(index.column() == 5)
        {
            if(index.data().toInt() == 0) {
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Verification validation", "Cette validation peut causer des problèmes à l'entreprise\n Valider quand même ?", QMessageBox::Yes | QMessageBox::No);
                if (reply == QMessageBox::No) break;
                else{
                S.setSTATUT(true);
                if (!(S.validerSponsor())) QMessageBox::warning(this, "Validation", "Echec validation!");
                else QMessageBox::warning(this, "Validation", "Succès validation!");
                 }
                }

        }
    }
    remplirTabSponsor();

}

void Valider::on_validerButtonAction_clicked()
{
    QModelIndexList indexes = ui->tabActionnaires->selectionModel()->selection().indexes();
    for( int i=0; i<indexes.count(); i++){
        QModelIndex index = indexes.at(i);


        if (index.column() == 0) A.setIDACTIONNAIRE(index.data().toInt());

        if(index.column() == 5)
        {
            if(index.data().toInt() == 0) {
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Verification validation", "Cette validation peut causer des problèmes à l'entreprise\n Valider quand même ?", QMessageBox::Yes | QMessageBox::No);
                if (reply == QMessageBox::No) break;
                else{
                A.setSTATUT(true);
                if (!(A.validerActionnaire())) QMessageBox::warning(this, "Validation", "Echec validation!");
                else QMessageBox::warning(this, "Validation", "Succès validation!");
                 }
                }

        }
    }
    remplirTabActionnaire();

}

void Valider::on_validerButtonDevis_clicked()
{
    QModelIndexList indexes = ui->tabDevis->selectionModel()->selection().indexes();
    for( int i=0; i<indexes.count(); i++){
        QModelIndex index = indexes.at(i);


        if (index.column() == 0) MP.setIdentifiant(index.data().toString());

        if(index.column() == 2)
        {
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Verification validation", "Cette validation peut causer des problèmes à l'entreprise\n Valider quand même ?", QMessageBox::Yes | QMessageBox::No);
                if (reply == QMessageBox::No) break;
                else{
                MP.setStatut(true);
                if (!(MP.validerDevis())) QMessageBox::warning(this, "Validation", "Echec validation!");
                else QMessageBox::warning(this, "Validation", "Succès validation!");
                 }

        }
    }
    remplirTabDevis();


}

void Valider::on_validerButtonComm_clicked()
{
    QModelIndexList indexes = ui->tabCommandes->selectionModel()->selection().indexes();
    for( int i=0; i<indexes.count(); i++){
        QModelIndex index = indexes.at(i);


        if (index.column() == 0) C.setIDCOMMANDE(index.data().toInt());

        if(index.column() == 2)
        {
            if(index.data().toInt() == 0) {
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Verification validation", "Cette validation peut causer des problèmes à l'entreprise\n Valider quand même ?", QMessageBox::Yes | QMessageBox::No);
                if (reply == QMessageBox::No) break;
                else{
                C.setSTATUT(true);
                if (!(C.validerCommande())) QMessageBox::warning(this, "Validation", "Echec validation!");
                else QMessageBox::warning(this, "Validation", "Succès validation!");
                 }
                }

        }
    }
    remplirTabCommande();

}

void Valider::on_Valider_ttButtonContrat_clicked()
{
    QModelIndexList indexes = ui->tabContrats->selectionModel()->selection().indexes();
    for( int i=0; i<indexes.count(); i++){
        QModelIndex index = indexes.at(i);


        if (index.column() == 0) CT.setidContrat(index.data().toInt());
        if(index.column() == 4){
            if (index.data().toInt() == 1)
            {
                QMessageBox::warning(this, "Verification Validation", "Ce contrat n'est pas achevé");
                return;
            }
        }
        if(index.column() == 5)
        {
            if(index.data().toInt() == 0) {
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Verification validation", "Cette validation peut causer des problèmes à l'entreprise\n Valider quand même ?", QMessageBox::Yes | QMessageBox::No);
                if (reply == QMessageBox::No) break;
                else{
                CT.setstatut(true);
                if (!(CT.payerIndemnite())) QMessageBox::warning(this, "Validation", "Echec validation!");
                else QMessageBox::warning(this, "Validation", "Succès validation!");
                 }
                }

        }
    }
    remplirTabContrat();

}

void Valider::on_validerButtonContrat_clicked()
{
    QModelIndexList indexes = ui->tabContrats->selectionModel()->selection().indexes();
    for( int i=0; i<indexes.count(); i++){
        QModelIndex index = indexes.at(i);


        if (index.column() == 0) CT.setidContrat(index.data().toInt());
        if(index.column() == 4){
            if (index.data().toInt() == 0)
            {
                QMessageBox::warning(this, "Verification Validation", "Ce contrat est achevé");
                return;
            }
        }
        if(index.column() == 4)
        {
            if(index.data().toInt() == 0) {
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Verification validation", "Cette validation peut causer des problèmes à l'entreprise\n Valider quand même ?", QMessageBox::Yes | QMessageBox::No);
                if (reply == QMessageBox::No) break;
                else{
                CT.setstatut(true);
                if (!(CT.validerContrat())) QMessageBox::warning(this, "Validation", "Echec validation!");
                else QMessageBox::warning(this, "Validation", "Succès validation!");
                 }
                }

        }
    }
    remplirTabContrat();

}

void Valider::on_validerButtonPaie_clicked()
{
    QModelIndexList indexes = ui->tabPaie->selectionModel()->selection().indexes();
    for( int i=0; i<indexes.count(); i++){
        QModelIndex index = indexes.at(i);


        if (index.column() == 0) PE.setidBulletin(index.data().toInt());

        if(index.column() == 3)
        {
            if(index.data().toInt() == 0) {
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Verification validation", "Cette validation peut causer des problèmes à l'entreprise\n Valider quand même ?", QMessageBox::Yes | QMessageBox::No);
                if (reply == QMessageBox::No) break;
                else{
                PE.setetat(true);
                if (!(PE.validerPaiment())) QMessageBox::warning(this, "Validation", "Echec validation!");
                else QMessageBox::warning(this, "Validation", "Succès validation!");
                 }
                }

        }
    }
    remplirTabPaie();
}

void Valider::on_validerButtonRep_clicked()
{
    QModelIndexList indexes = ui->tabReparation->selectionModel()->selection().indexes();
    for( int i=0; i<indexes.count(); i++){
        QModelIndex index = indexes.at(i);


        if (index.column() == 0) Rep.setIdPreparation(index.data().toInt());

        if(index.column() == 2)
        {
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Verification validation", "Cette validation peut causer des problèmes à l'entreprise\n Valider quand même ?", QMessageBox::Yes | QMessageBox::No);
                if (reply == QMessageBox::No) break;
                else{
                Rep.setEtat("En marche");
                if (!(Rep.validerReparation())) QMessageBox::warning(this, "Validation", "Echec validation!");
                else QMessageBox::warning(this, "Validation", "Succès validation!");
                 }

        }
    }
    remplirTabRep();

}

void Valider::on_validerButtonProd_clicked()
{
    QModelIndexList indexes = ui->tabProduction->selectionModel()->selection().indexes();
    qDebug() << indexes.count();
    for( int i=0; i<indexes.count(); i++){
        QModelIndex index = indexes.at(i);


        if (index.column() == 0) Prod.setId_prod(index.data().toString());
        if(index.column() == 3) Prod.setCPM(index.data().toDouble());

        if(index.column() == 4)
        {
            if(index.data().toInt() == 0) {
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Verification validation", "Cette validation peut causer des problèmes à l'entreprise\n Valider quand même ?", QMessageBox::Yes | QMessageBox::No);
                if (reply == QMessageBox::No) break;
                else{
                    Prod.setStatutProd("Production confirmee");
                if (!(Prod.validerProduitProduction())) QMessageBox::warning(this, "Validation", "Echec validation!");
                else
                {
                    M = new Messagerie();
                    M->setDestinataire("Mejri Hedi");
                    M->setExpediteur("Departement des Finances");
                    M->setMessage("J'ai bien confirmé le lancement de production du Produit : " + Prod.getId_prod());
                    M->setEtat(1);
                    if (M->envoyerMessage())
                    {
                        qDebug() << "Succés";
                    }
                    QMessageBox::warning(this, "Validation", "Succès validation!");
                }
                 }
                }

        }
    }
    remplirTabProdProduction();


}

void Valider::on_validerButtonVente_clicked()
{
    QModelIndexList indexes = ui->tabVente->selectionModel()->selection().indexes();
    for( int i=0; i<indexes.count(); i++){
        QModelIndex index = indexes.at(i);


        if (index.column() == 0) Prod.setId_prod(index.data().toString());
        if(index.column() == 3) Prod.setCPF(index.data().toDouble());

        if(index.column() == 4)
        {
            if(index.data().toInt() == 0) {
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Verification validation", "Cette validation peut causer des problèmes à l'entreprise\n Valider quand même ?", QMessageBox::Yes | QMessageBox::No);
                if (reply == QMessageBox::No) break;
                else{
                    Prod.setStatutVente("Vente confirmee");
                if (!(Prod.validerProduitVente())) QMessageBox::warning(this, "Validation", "Echec validation!");
                else QMessageBox::warning(this, "Validation", "Succès validation!");
                 }
                }

        }
    }
    remplirTabProdVente();


}

void Valider::on_actionMessage_s_triggered()
{

    Messages Msg(this,Conn.getLogin());
    Msg.setModal(true);
    Msg.exec();

}

void Valider::on_actionE_Mail_triggered()
{
    mail = new Mail(this);
    mail->show();
}

void Valider::on_actionFermer_triggered()
{
    Conn.initUsers(name_connected);

    this->close();
}
