#include "fajoutprod.h"
#include "ui_fajoutprod.h"
#include "produit.h"




FajoutProd::FajoutProd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FajoutProd)
{
    C.ConnectionBD();
    test=false;
    ui->setupUi(this);
    ui->groupBox_affich->hide();
    resize(width(), height() -  ui->groupBox_affich->height());
    ui->but_refresh->setEnabled(false);
    ui->date_duree->setEnabled(false);
    ui->barcode_text->setEnabled(true);
    on_but_refresh_clicked();


}

FajoutProd::~FajoutProd()
{
    delete ui;
}


void FajoutProd::on_but_afficher_prod_clicked()
{
    /*
     *Affichage en liste
     */
    ui->table_produits->setModel(P->afficherProduits());

    if(!test)
    {
    resize(width(), height() +  ui->groupBox_affich->height());
    ui->groupBox_affich->show();
    test=true;
    ui->but_afficher_prod->setText("Dissimuler");
    ui->but_refresh->setEnabled(true);

    }
    else
    {
        resize(width(), height() -  ui->groupBox_affich->height());
        ui->groupBox_affich->hide();
        test=false;
        ui->but_afficher_prod->setText("Afficher");
        ui->but_refresh->setEnabled(false);
    }
}

void FajoutProd::on_but_creer_prod_clicked()
{
    /*
     *CREATION
     */

    if (ui->but_creer_prod->text()=="Creer")
    {
    P = new Produit();
        if (ui->nomprod_text->text() == "")
        {
            ui->nomprod_text->setStyleSheet("QLineEdit{background: yellow;}");
        }
    QString temp = ui->checkBox_acheter->text();
        if (ui->checkBox_vendre->isChecked())
        {
            temp =ui->checkBox_vendre->text();
        }
    bool test_checkbox = true;
        if (ui->checkBox_vendre->isChecked() && ui->checkBox_acheter->isChecked())
        {

            QMessageBox::warning(this, "Alerte!", "Verifier les données que vous avez saisi!");
            ui->checkBox_vendre->setStyleSheet("QCheckBox{color:red;}");
            ui->checkBox_acheter->setStyleSheet("QCheckBox{color:red;}");
            test_checkbox = false;
        }
            if(test_checkbox)
            {
                // Duree
            ui->date_duree->setText(QString::number(P->calculDuree(ui->date_debut->text(), ui->date_fin->text())));
            // Ajout
            P->setNom(ui->nomprod_text->text());
            P->setEntrepot(ui->combo_entrepot_stock->currentText());
            P->setCategorie(ui->combo_categories->currentText());
            P->setEmpStock(ui->combo_site_stock->currentText());
            P->setBut(temp);
            P->setQte(ui->quantite->text().toInt());
            P->setBarCode(ui->barcode_text->text());
            P->setId_prod(ui->id_produit->text());
            P->setId_proj(ui->ident_proj->text().toInt());
            P->setProjState(ui->combo_projectstate->currentText());
            P->setDateDebut(ui->date_debut->text());
            P->setDateFin(ui->date_fin->text());
            P->setDuree(P->calculDuree(ui->date_debut->text(), ui->date_fin->text()));
            P->setResponsable(ui->combo_resp->currentText());
            P->setCPM(ui->cout_text->text().toDouble());

                if (P->AjoutProd())
                {
                    QMessageBox::information(this, "Notice", "Ajout éffectué avec succés");

                    ui->barcode_text->setStyleSheet("QLineEdit{background: white;}");
                    ui->ident_proj->setStyleSheet("QLineEdit{background: white;}");
                    ui->id_produit->setStyleSheet("QLineEdit{background: white;}");
                    ui->nomprod_text->setText("");
                }
                else
                {
                    ui->barcode_text->setStyleSheet("QLineEdit{background: red;}");
                    ui->ident_proj->setStyleSheet("QLineEdit{background: red;}");
                    ui->id_produit->setStyleSheet("QLineEdit{background: red;}");
                }
            }
    }

    /*
     *MODIFICATION
     */

    else
    { 
        P = new Produit();
        P->setCPM(ui->cout_text->text().toDouble());
        P->setQte(ui->quantite->text().toInt());
        P->setProjState(ui->combo_projectstate->currentText());
        P->setDateDebut(ui->date_debut->text());
        P->setDateFin(ui->date_fin->text());
        P->setDuree(ui->date_duree->text().toInt());
        P->setNom(ui->nomprod_text->text());

            if (P->ModifProd())
            {
                QMessageBox::information(this, "Information", "Produit changé!");
                ui->but_creer_prod->setText("Creer");
                ui->nomprod_text->setText("");
                ui->ident_proj->setEnabled(true);
                ui->id_produit->setEnabled(true);
                ui->barcode_text->setEnabled(true);
                ui->combo_categories->setEnabled(true);
                ui->combo_entrepot_stock->setEnabled(true);
                ui->combo_resp->setEnabled(true);
                ui->combo_site_stock->setEnabled(true);
                ui->combo_projectstate->setEnabled(true);

                ui->ident_proj->setText("");
                ui->id_produit->setText("");
                ui->barcode_text->setText("");
                ui->quantite->setText("");
                ui->cout_text->setText("");
                ui->date_debut->setText("");
                ui->date_fin->setText("");
                ui->date_duree->setText("");
                ui->combo_categories->setCurrentIndex(0);
                ui->combo_entrepot_stock->setCurrentIndex(0);
                ui->combo_resp->setCurrentIndex(0);
                ui->combo_site_stock->setCurrentIndex(0);
                ui->combo_projectstate->setCurrentIndex(0);
            }
    }
}



void FajoutProd::on_but_quitter_clicked()
{
    close();
}

void FajoutProd::on_nomprod_text_cursorPositionChanged()
{
    if (ui->nomprod_text->text() == "" || ui->nomprod_text->text().toInt()!=0)
    {
        ui->nomprod_text->setStyleSheet("QLineEdit{background: yellow;}");
        ui->checkBox_acheter->setEnabled(false);
        ui->checkBox_vendre->setEnabled(false);
        ui->tab_ajout_prod->setEnabled(false);
        ui->combo_categories->setEnabled(false);
        ui->but_creer_prod->setEnabled(false);
   }

    else
    {
        /*
         *Test existance nom && Modification
         */
        QSqlQuery *query = P->testExistance(ui->nomprod_text->text());
        if (query->isValid())
        {
                QMessageBox::StandardButton rep;
                rep = QMessageBox::question(this, "Alerte!", "Voulez vous vraiment modifier le produit selectionné?", QMessageBox::Yes | QMessageBox::No);

                if(rep==QMessageBox::Yes)
                {
                                QSqlRecord rec = P->renvoiValeurs(ui->nomprod_text->text());

                                int idprod = rec.indexOf("IdProduit");
                                int idproj = rec.indexOf("IdProjet");
                                int empl = rec.indexOf("Emplacement_Stockage");
                                int entr = rec.indexOf("Entrepot");
                                int cat = rec.indexOf("Categorie");
                                int but = rec.indexOf("But");
                                int code = rec.indexOf("Code_Barres");
                                int etat = rec.indexOf("Etat_Projet");
                                int dateD = rec.indexOf("Date_Debut_Production");
                                int dateF = rec.indexOf("Date_Fin_Production");
                                int resp = rec.indexOf("Responsable");
                                int cout = rec.indexOf("Cout");
                                int qte = rec.indexOf("Quantite");
                                int duree = rec.indexOf("Duree");

                                /*
                                 *Renvoi des valeurs a l'interface
                                 */

                                ui->ident_proj->setText(query->value(idproj).toString());
                                ui->id_produit->setText(query->value(idprod).toString());
                                ui->combo_site_stock->setCurrentText(query->value(empl).toString());
                                ui->combo_entrepot_stock->setCurrentText(query->value(entr).toString());
                                ui->combo_categories->setCurrentText(query->value(cat).toString());
                                if (query->value(but).toString() == "A vendre")
                                {
                                    ui->checkBox_vendre->setChecked(true);
                                }
                                else if (query->value(but).toString() == "A acheter")
                                {
                                    ui->checkBox_acheter->setChecked(true);
                                }
                                ui->barcode_text->setText(query->value(code).toString());
                                ui->combo_projectstate->setCurrentText(query->value(etat).toString());
                                ui->date_debut->setText(query->value(dateD).toString());
                                ui->date_fin->setText(query->value(dateF).toString());
                                ui->date_duree->setText(query->value(duree).toString());
                                ui->combo_resp->setCurrentText(query->value(resp).toString());
                                ui->cout_text->setText(query->value(cout).toString());
                                ui->quantite->setText(query->value(qte).toString());

                                /*
                                 *Changement - Modifier
                                 */

                                ui->but_creer_prod->setText("Modifier");

                                ui->ident_proj->setEnabled(false);
                                ui->id_produit->setEnabled(false);
                                ui->barcode_text->setEnabled(false);
                                ui->combo_categories->setEnabled(false);
                                ui->combo_entrepot_stock->setEnabled(false);
                                ui->combo_resp->setEnabled(false);
                                ui->combo_site_stock->setEnabled(false);
                                ui->checkBox_acheter->setChecked(false);
                                ui->checkBox_vendre->setChecked(false);
                                ui->combo_projectstate->setEnabled(false);

                                /*
                                 *Timer
                                 */

                                Ai();
            }
        }

        ui->nomprod_text->setStyleSheet("QLineEdit{background: white;}");
        ui->checkBox_acheter->setEnabled(true);
        ui->checkBox_vendre->setEnabled(true);
        ui->tab_ajout_prod->setEnabled(true);
        ui->combo_categories->setEnabled(true);
        ui->but_creer_prod->setEnabled(true);
        //ui->groupBox_affich->setEnabled(true);
   }
}



void FajoutProd::on_groupBox_affich_clicked()
{
    resize(width(), height() -  ui->groupBox_affich->height());
}


void FajoutProd::on_but_refresh_clicked()
{

    ui->table_produits->setModel(P->extraireProduits());

    ui->combo_site_stock->setModel(S.afficherSiteProd());

    ui->combo_resp->setModel(Resp.extractResponsable());

    ui->combo_entrepot_stock->setModel(S.extraireEmplacement());
}

void FajoutProd::on_checkBox_acheter_stateChanged()
{
    Connexion C;
    if (ui->checkBox_acheter->isChecked())
    {
    ui->combo_site_stock->setModel(S.afficherSiteStock());
    }
}

void FajoutProd::on_checkBox_vendre_stateChanged()
{
    Connexion C;
    if (ui->checkBox_vendre->isChecked())
    {
    ui->combo_site_stock->setModel(S.afficherSiteProd());
    }
}

bool FajoutProd::ref_duree()
{
    if (ui->date_duree->text().toInt() > 0)
    {
        ui->date_duree->setText(QString::number(ui->date_duree->text().toInt() - 1));
        return true;
    }
    else
        return false;
}

void FajoutProd::Ai()
{
    /*
     *TIMER SUR LA DUREE
     */
    QTimer* mTimer;
    mTimer = new QTimer(this);
    mTimer->start(500);
    mTimer->setSingleShot(false);

    if (ref_duree())
    {
        connect(mTimer, SIGNAL(timeout()), SLOT(ref_duree()));
    }

}

void FajoutProd::on_date_duree_textChanged()
{
    if (ui->date_duree->text() == "0")
    {
        QSound *prod = new QSound(QDir::currentPath() + "/../sounds/production_achevee.wav");
        prod->play();

    }
}

