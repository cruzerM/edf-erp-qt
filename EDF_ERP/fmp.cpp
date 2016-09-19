#include "fmp.h"
#include "ui_fmp.h"
#include <QMessageBox>
Fmp::Fmp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Fmp)
{
    ui->setupUi(this);
    //on_but_refresh_clicked();
}

Fmp::~Fmp()
{
    delete ui;
}

void Fmp::on_identMP_cursorPositionChanged()
{
    if (ui->identMP->text() == "" || ui->identMP->text().toInt()==0 || MP->controlExistance(ui->identMP->text()))
    {
        ui->identMP->setStyleSheet("QLineEdit{background: yellow;}");
        ui->but_ajouter->setEnabled(false);
        ui->groupBox_actes->setEnabled(false);
        ui->tableMP->setEnabled(false);
    }

    else
    {
        ui->identMP->setStyleSheet("QLineEdit{background: white;}");
        ui->but_ajouter->setEnabled(true);
        ui->groupBox_actes->setEnabled(true);
        ui->tableMP->setEnabled(true);
    }
}
void Fmp::on_but_ajouter_clicked()
{
    MP = new MatiereP();
    MP->setIdentifiant(ui->identMP->text());
    MP->setIdentifiant_Produit(ui->IdentProd->text());
    MP->setType(ui->combo_type->currentText());
    MP->setCout(ui->cout_text->text().toDouble());

    if(MP->addMatierePremiere())
    {
        QMessageBox::information(this, "Information", "Ajout éfféctué");
        ui->combo_type->setCurrentIndex(0);
        ui->IdentProd->setText("");
        ui->identMP->setText("");
    }

    else
    {
        QMessageBox::critical(this, "Critique", "Impossible d'ajouter cet élément");
    }
}

void Fmp::on_but_refresh_clicked()
{
    ui->tableMP->setModel(MP->updateListe());
}
