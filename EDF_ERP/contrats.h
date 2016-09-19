#ifndef CONTRATS_H
#define CONTRATS_H


#include <QString>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QtPrintSupport/QPrinter>
#include <QFileInfo>
#include <QPainter>
#include <QFileDialog>
#include <QSqlQuery>
#include "connexion.h"

class Contrat {

public:

    Contrat();
    void ajouter();
    QSqlQueryModel * afficher();
    void modifier();
    void supprimer();
    bool verifier_id();
    int getidEmploye();
    void setidEmploye(int);
    int getidContrat();
    void setidContrat(int);
    int getduree_contrat();
    void setduree_contrat(int);
    QString getdate_debut();
    void setdate_debut(QString);
    QString getdate_fin();
    void setdate_fin(QString);
    QString gettype_rupture();
    void settype_rupture(QString);
    QString gettype_contrat();
    void settype_contrat(QString);
    double getmontant();
    void setmontant(double);
    double getindemnite();
    void setindemnite(double);
    bool getetat_contrat();
    void setetat_contrat(bool);
    bool getstatut();
    void setstatut(bool);
    bool validerContrat();
    bool payerIndemnite();
    QSqlQueryModel *afficherContratsNV();

    Connexion C;

private:

    int IdContrat;
    int IdEmploye;
    QString date_debut;
    QString date_fin;
    int duree_contrat;
    double montant;
    double indemnite;
    QString type_rupture;
    QString type_contrat;
    bool etat_contrat;
    bool statut;
};

#endif // CONTRATS_H
