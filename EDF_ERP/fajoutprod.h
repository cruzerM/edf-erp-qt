#ifndef FAJOUTPROD_H
#define FAJOUTPROD_H

#include <QDialog>
#include <QSqlTableModel>
#include <QtMultimedia/QSound>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDateTime>
#include <QDate>
#include <QDebug>
#include <QString>
#include "connexion.h"
#include <QSqlRecord>
#include <QTimer>
#include <QThread>
#include "produit.h"
#include "fproduction.h"
#include "sites.h"
#include "responsable.h"

namespace Ui {
class FajoutProd;
}

class FajoutProd : public QDialog
{
    Q_OBJECT

public:
    explicit FajoutProd(QWidget *parent = 0);
    ~FajoutProd();
public slots:
    bool ref_duree();
private slots:
    void on_but_afficher_prod_clicked();

    void on_but_creer_prod_clicked();

    void on_but_quitter_clicked();

    void on_nomprod_text_cursorPositionChanged();

    void on_groupBox_affich_clicked();

    void on_but_refresh_clicked();

    void on_checkBox_acheter_stateChanged();

    void on_checkBox_vendre_stateChanged();

    void Ai();

    void on_date_duree_textChanged();

private:
    Ui::FajoutProd *ui;
    Produit *P;
    QSqlTableModel *model;
    Fproduction *Prod;
    bool test;
    Connexion C;
    Sites S;
    Responsable Resp;
};

#endif // FAJOUTPROD_H


