#ifndef FPRODUCTION_H
#define FPRODUCTION_H

#include <QDialog>
#include <QSqlTableModel>
#include "connexion.h"
#include "production.h"
#include <QSqlQuery>
#include "produit.h"
#include "sites.h"
#include "responsable.h"

namespace Ui {
class Fproduction;
}

class Fproduction : public QDialog
{
    Q_OBJECT

public:
    explicit Fproduction(QWidget *parent = 0);
    ~Fproduction();
    void refreshComboProd();

private slots:

    void on_but_refresh_commande_clicked();

    void on_commande_text_cursorPositionChanged();

    void on_but_ajout_clicked();

    void on_but_confirmer_commande_clicked();

private:
    Ui::Fproduction *ui;
    Connexion C;
    Production *P;
    Produit Prod;
    Sites S;
    Responsable *Resp;
};

#endif // FPRODUCTION_H
