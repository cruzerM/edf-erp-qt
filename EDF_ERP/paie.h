#ifndef PAIE_H
#define PAIE_H


#include <QString>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QtPrintSupport/QPrinter>
#include <QFileInfo>
#include <QPainter>
#include <QFileDialog>
#include "connexion.h"


class Paie {


public:

    Paie();
    void ajouter();
    QSqlQueryModel * afficher();
    void modifier();
    void supprimer();
    void export_pdf();
    bool verifier_id();
    int getidBulletin();
    void setidBulletin(int);
    int getidEmploye();
    void setidEmploye(int);
    QString getperiode();
    void setperiode(QString);
    double getsalaire_fixe();
    void setsalaire_fixe(double);
    double getheure_supp();
    void setheure_supp(double);
    double getabsence();
    void setabsence(double);
    double getprime();
    void setprime(double);
    double getsalaire_brut();
    void setsalaire_brut(double);
    double getcotisations();
    void setcotisation(double);
    double getsalaire_net();
    void setsalaire_net(double);
    double getCSG_deductible();
    void setCSG_deductible(double);
    double getCRDS();
    void setCRDS(double);
    double getsalaire_payer();
    void setsalaire_payer(double);
    bool getetat();
    void setetat(bool);
    double getCSG_nondeductible();
    void setCSG_nondeductible(double);
    double getnet_fiscal();
    void setnet_fiscal(double);
    bool validerPaiment();
    QSqlQueryModel *afficherPaieNV();
    Connexion C;

private:

    int IdBulletin;
    int IdEmploye;
    QString periode_payee;
    double salaire_fixe;
    double heure_supplementaire;
    double absence;
    double prime;
    double salaire_brut;
    double cotisations_sociales;
    double salaire_net;
    double CSG_deductible;
    double net_fiscal;
    double CSG_nondeductible;
    double CRDS;
    double salaire_payer;
    bool etat;
};

#endif // PAIE_H
