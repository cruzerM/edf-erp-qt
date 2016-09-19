#include "freparation.h"
#include "ui_freparation.h"
#include <QMessageBox>
Freparation::Freparation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Freparation)
{
    ui->setupUi(this);
    ui->combo_prod->setModel(P.afficherTypeProd());
}

Freparation::~Freparation()
{
    delete ui;
}

void Freparation::on_id_repair_text_cursorPositionChanged()
{
    if ((ui->id_repair_text->text() == "") || ((ui->id_repair_text->text().toInt() == 0)) || R->testExistance(ui->id_repair_text->text().toInt()) )
    {
        ui->id_repair_text->setStyleSheet("QLineEdit{background: yellow;}");
        ui->confirm_but->setEnabled(false);
        ui->groupe_actes->setEnabled(false);
    }
    else
    {
        ui->id_repair_text->setStyleSheet("QLineEdit{background: white;}");
        ui->confirm_but->setEnabled(true);
        ui->groupe_actes->setEnabled(true);
    }
}

void Freparation::on_confirm_but_clicked()
{
    R = new Reparation();

    R->setIdPreparation(ui->id_repair_text->text().toInt());
    R->setCout(ui->cout_text->text().toDouble());
    R->setEtat(ui->combo_etat->currentText());
    R->setPanne(ui->panne_text->text());
    R->setProduit(ui->combo_prod->currentText());

    if (R->instancierReparation())
    {
        QMessageBox::information(this, "Information", "Instanciation de Reparation éfféctué!");
    }
    else
    {
        QMessageBox::warning(this, "Alerte", "Instanciation de Reparation non-éfféctué!");

    }
}
