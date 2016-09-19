#ifndef SITES_H
#define SITES_H
#include "connexion.h"
#include <QSqlQuery>
#include <QSqlQueryModel>


class Sites
{
    QString Nom;
    QString Ville;
    QString Dept;
    QString Nature;
    long Capacite;

public:
    Sites();
    Sites(QString, QString, QString, QString, long);
    ~Sites() {}

    void setNom(QString n) {Nom=n;}
    QString getNom() {return Nom;}

    void setVille(QString v) {Ville=v;}
    QString getVille() {return Ville;}

    void setDept(QString d) {Dept=d;}
    QString getDept() {return Dept;}

    void setNature(QString n) {Nature=n;}
    QString getNature() {return Nature;}

    void setCapacite(long c) {Capacite=c;}
    long getCapacite() {return Capacite;}

    bool ajouterSiteProd();
    bool ajouterSiteStock();

    QSqlQueryModel* afficherSiteProd();
    QSqlQueryModel* afficherSiteStock();
    QSqlQueryModel* extraireSiteProd();
    QSqlQueryModel* extraireSiteStock();
    QSqlQueryModel* extraireEmplacement();

};

#endif // SITES_H
