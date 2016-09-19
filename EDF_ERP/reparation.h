#ifndef REPARATION_H
#define REPARATION_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "connexion.h"


class Reparation
{
    int IdReparation;
    QString Panne;
    QString Produit;
    QString Etat;
    double Cout;


public:
    Reparation();
    Reparation (int, QString, QString, QString, double);

    void setIdPreparation(int id) {IdReparation = id;}
    void setPanne(QString panne) {Panne = panne;}
    void setProduit(QString prod) {Produit = prod;}
    void setEtat(QString etat) {Etat=etat;}
    void setCout(double cout) {Cout = cout;}

    bool instancierReparation();
    bool testExistance(int);

    bool validerReparation();
    QSqlQueryModel *afficherReparationNV();

    Connexion C;
};

#endif // REPARATION_H
