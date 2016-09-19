#include "fcontrol.h"
#include "ui_fcontrol.h"
#include <QMessageBox>
FControl::FControl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FControl)
{
    ui->setupUi(this);
}

FControl::~FControl()
{
    delete ui;
}


void FControl::on_id_control_text_cursorPositionChanged()
{
    if (ui->id_control_text->text() == "" || ui->id_control_text->text().toInt()==0)
    {
        ui->id_control_text->setStyleSheet("QLineEdit{background: yellow;}");
        ui->groupe_actes->setEnabled(false);
        ui->but_ajouter->setEnabled(false);
    }

    else if(Cont->controlExistance(ui->id_control_text->text().toInt()))
    {
        QMessageBox::warning(this,"Alerte","Cet identifiant existe déja!");
        ui->id_control_text->setStyleSheet("QLineEdit{background: yellow;}");
        ui->groupe_actes->setEnabled(false);
        ui->but_ajouter->setEnabled(false);

    }
    else
    {
        ui->id_control_text->setStyleSheet("QLineEdit{background: white;}");
        ui->groupe_actes->setEnabled(true);
        ui->but_ajouter->setEnabled(true);
    }
}

void FControl::on_but_ajouter_clicked()
{
    Cont = new Control();

    Cont->setIdentifiant(ui->id_control_text->text().toInt());
    Cont->setQualite(ui->combo_qualite->currentText());
    Cont->setEcheances(ui->echenaces_text->text());
    Cont->setType(ui->combo_type_prod->currentText());

    if(Cont->addControlCycle())
    {
        QMessageBox::information(this, "Information", "Ajout éfféctué");
        ui->combo_qualite->setCurrentIndex(0);
        ui->combo_type_prod->setCurrentIndex(0);
        ui->id_control_text->setText("");
        ui->echenaces_text->setText("");
    }

    else
    {
        QMessageBox::critical(this, "Critique", "Impossible d'ajouter cet élément");
    }
}
