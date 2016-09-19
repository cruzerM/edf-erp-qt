#include "femployes.h"
#include "ui_femployes.h"
#include <QMessageBox>

Femployes::Femployes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Femployes)
{
    ui->setupUi(this);
    ui->combo_commande->setModel(P.extraireCommande());
    ui->combo_poste->setModel(E.extraireListePostes());
    ui->combo_grade->setModel(E.extraireListeGrades());
}

Femployes::~Femployes()
{
    delete ui;
}


void Femployes::on_id_employe_text_cursorPositionChanged()
{
    if (ui->id_employe_text->text() == ""|| ui->id_employe_text->text().toInt()==0 || (!(E.testExistanceEmp(ui->id_employe_text->text()))))
    {
        ui->combo_dispo->setEnabled(false);
        ui->combo_grade->setEnabled(false);
        ui->combo_poste->setEnabled(false);
        ui->date_debut->setEnabled(false);
        ui->date_fin->setEnabled(false);
        ui->combo_commande->setEnabled(false);
    }
    else
    {
        QSqlRecord rec = R.chercherAffectation(ui->id_employe_text->text().toInt());

        ui->id_employe_text->setText(rec.value("IdEmploye").toString());
        ui->combo_commande->setCurrentText(rec.value("IdDevis").toString());
        ui->combo_dispo->setCurrentText(rec.value("Disponibilite").toString());
        ui->combo_grade->setCurrentText(rec.value("Grade").toString());
        ui->combo_poste->setCurrentText(rec.value("Poste").toString());
        ui->date_debut->setDate(rec.value("DateDebut").toDate());
        ui->date_fin->setDate(rec.value("DateFin").toDate());

        qDebug() << rec.value("DateFin").toString();
        ui->date_debut->setEnabled(true);
        ui->date_fin->setEnabled(true);
        ui->combo_commande->setEnabled(true);
    }
}
void Femployes::on_but_affecter_clicked()
{

    R.setIdEmploye(ui->id_employe_text->text().toInt());
    R.setIdCommande(ui->combo_commande->currentText().toInt());
    R.setGrade(ui->combo_grade->currentText());
    R.setPoste(ui->combo_poste->currentText());
    R.setDisponibilite(ui->combo_dispo->currentText());
    R.setDateDeb(ui->date_debut->text());
    R.setDateFin(ui->date_fin->text());
    R.setDuree(R.calculDuree(ui->date_debut->date().toString(), ui->date_fin->date().toString()));

    if (R.ajouterAffectation())
    {
        QMessageBox::information(this, "Information", "Employé affecté!");
    }
    else
        QMessageBox::warning(this, "Alerte", "Affectation non-éffectué");
}

void Femployes::on_but_modif_clicked()
{
    QSqlRecord rec = R.chercherAffectation(ui->id_employe_text->text().toInt());

    ui->id_employe_text->setText(rec.value("IdEmploye").toString());
    ui->combo_commande->setCurrentText(rec.value("IdDevis").toString());
    ui->combo_dispo->setCurrentText(rec.value("Disponibilite").toString());
    ui->combo_grade->setCurrentText(rec.value("Grade").toString());
    ui->combo_poste->setCurrentText(rec.value("Poste").toString());
    ui->date_debut->setDate(rec.value("DateDebut").toDate());
    ui->date_fin->setDate(rec.value("DateFin").toDate());

    R.setIdEmploye(ui->id_employe_text->text().toInt());
    R.setIdCommande(ui->combo_commande->currentText().toInt());
    R.setDisponibilite(ui->combo_dispo->currentText());
    R.setDateDeb(ui->date_debut->text());
    R.setDateFin(ui->date_fin->text());
    R.setPoste(ui->combo_poste->currentText());
    R.setDuree(R.calculDuree(ui->date_debut->text(), ui->date_fin->text()));

    R.modifierAffectation();
}

void Femployes::on_but_delete_clicked()
{
    if (R.supprimerAffectation(ui->id_employe_text->text().toInt()))
    {
        QMessageBox::information(this, "Information", "L'employé est désormais non affecté!");
    }
    else
        QMessageBox::warning(this, "Alerte", "Non-éffectué");
}
