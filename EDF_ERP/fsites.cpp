#include "fsites.h"
#include "ui_fsites.h"
#include <QMessageBox>
Fsites::Fsites(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Fsites)
{
    ui->setupUi(this);

    ui->table_sites_prod->setModel(S->extraireSiteProd());
    ui->table_sites_stock->setModel(S->extraireSiteStock());
}

Fsites::~Fsites()
{
    delete ui;
}

void Fsites::on_ajouter_but_site_clicked()
{
    S = new Sites();

    S->setNom(ui->nom_text_prod->text());
    S->setVille(ui->ville_text_prod->text());
    S->setDept(ui->dept_text_prod->text());
    S->setNature(ui->combo_nature_site->currentText());

    if(S->ajouterSiteProd())
    {
        QMessageBox::information(this, "Information", "Site de Production ajouté avec succés!");
    }
    else
        QMessageBox::warning(this, "Alerte", "Site de Production non ajouté!");
}

void Fsites::on_refresh_but_site_clicked()
{
    ui->table_sites_prod->setModel(S->extraireSiteProd());
}

void Fsites::on_refresh_but_stock_clicked()
{
    ui->table_sites_stock->setModel(S->extraireSiteStock());
}

void Fsites::on_ajouter_but_stock_clicked()
{
    S = new Sites();

    S->setNom(ui->nom_text_stock->text());
    S->setVille(ui->ville_text_stock->text());
    S->setDept(ui->dept_text_stock->text());
    S->setNature(ui->combo_nature_stock->currentText());
    S->setCapacite(ui->qty_stock_text->text().toLong());

    if(S->ajouterSiteStock())
    {
        QMessageBox::information(this, "Information", "Site de Stockage ajouté avec succés!");
    }
    else
        QMessageBox::warning(this, "Alerte", "Site de Stockage non ajouté!");
}

