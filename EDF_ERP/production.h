#ifndef PRODUCTION_H
#define PRODUCTION_H

#include <QString>
#include "connexion.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlQueryModel>
#include "messagerie.h"

class Production
{
    long IdCommande;
    QString IdProduit;
    QString Date;
    QString Responsable;
    QString Site_Production;
    long IdProjet;
    long Quantite;
    double Montant;
    QString Statut;

    public:
    Production();
    Production(long, QString, QString, QString, QString, long, long, double, QString);
    ~Production(){}

    void setIdCommande(long idV) {IdCommande = idV;}
    long getIdCommande() {return IdCommande;}

    void setIdProduit(QString idP) {IdProduit = idP;}
    QString getIdProduit() {return IdProduit;}

    void setDate(QString date) {Date = date;}
    QString getDate() {return Date;}

    void setResponsable(QString resp) {Responsable = resp;}
    QString getResponsable() {return Responsable;}

    void setSiteProd(QString site) {Site_Production = site;}
    QString getSiteProd() {return Site_Production;}

    void setIdProjet(long idProj) {IdProjet = idProj;}
    long getIdProjet() {return IdProjet;}

    void setQuantite(long qte) {Quantite = qte;}
    long getQuantite() {return Quantite;}

    void setSTATUT(QString stat) {Statut = stat;}
    QString getSTATUT() {return Statut;}


    bool AjoutCommande();
    QSqlQueryModel* afficherTypeProjet();
    QSqlQueryModel* afficherProduits();

    double calculerMontantProduction();
    int extraireQte();
    QSqlQueryModel* extraireCommande();

    QSqlQuery* testExistance(int);
    QSqlQuery* testExistanceConfirmee(int);
    QSqlRecord renvoiValeurs(int);

    bool changerEtat(int);



    Connexion C;
};

#endif // PRODUCTION_H
