#ifndef MATIEREP_H
#define MATIEREP_H

#include <QString>
#include <QSqlQuery>
#include <QDebug>
#include "connexion.h"
#include <QSqlQueryModel>
#include <QSqlTableModel>

class MatiereP
{
    QString Identifiant;
    QString Type;
    QString Identifiant_Produit;
    double Cout;
    bool Statut;
public:
    MatiereP();
    MatiereP (QString, QString, QString, double, bool);

    void setIdentifiant(QString);
    QString getIdentifiant();

    void setType(QString);
    QString getType();

    void setIdentifiant_Produit(QString);
    QString getIdentifiant_Produit();

    void setCout(double c) {Cout=c;}
    double getCout() {return Cout;}

    void setStatut(bool Statut);
    bool getStatut();

    bool addMatierePremiere();
    bool controlExistance(QString);
    QSqlQueryModel *updateListe();

    double calculerMontantDevis(long);
    bool validerDevis();
    QSqlQueryModel *afficherDevisNV();

    Connexion C;

};

#endif // MATIEREP_H
