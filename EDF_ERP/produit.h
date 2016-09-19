#ifndef PRODUIT_H
#define PRODUIT_H

//#include "fproduction.h"
#include <QString>
#include <QDate>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "connexion.h"
#include "messagerie.h"


class Produit
{
    //Ceci est pour tester
    QString IdProduit;
    int id_project;
    QString projectState;
    QString type;
    QString DateDebutProd;
    QString DateFinProd;
    int Duree;
    QString EmplacementProd;
    QString EmplacementStockage;
    QString Responsable;
    int Quantite;
    QString barcode;
    QString Entrepot;
    QString Categorie;
    QString But;
    QString Nom;
    QString StatutProd;
    QString StatutVente;

    /*
    *Cout de la production
    */
    double CoutProdFinal;
    double CoutProdMax;
    double chargeProd;

    /*
    *Cout de la vente
    */
    double CoutVenteFinal;
    double CoutVenteMin;
    double chargeVente;

public:
    Produit();
    ~Produit(){}
    /*
     *Getters && Setters
     */
    QString getEntrepot();
    void setEntrepot(QString);
    QString getNom();
    void setNom(QString);
    QString getCategorie();
    void setCategorie(QString);
    QString getBut();
    void setBut(QString);

    QString getEmpStock();
    void setEmpStock(QString);
    int getQte();
    void setQte(int);
    QString getBarCode();
    void setBarCode(QString);

    QString getEmpProd();
    void setEmpProd(QString);
    QString getId_prod();
    void setId_prod(QString);
    int getId_proj();
    void setId_proj(int);

    QString getProjState();
    void setProjState(QString);
    QString getDateDebut();
    void setDateDebut(QString);
    QString getDateFin();
    void setDateFin(QString);

    QString getResponsable();
    void setResponsable(QString);
    int getDuree();
    void setDuree(int);

    QString getStatutProd();
    void setStatutProd(QString);
    QString getStatutVente();
    void setStatutVente(QString);

    /*
    * PRODUCTION
    */

    double getCPF();
    void setCPF(double);
    double getCPM();
    void setCPM(double);
    double getChargeProd();
    void setChargeProd(double);

    /*
    * VENTE
    */

    double getCVF();
    void setCVF(double);
    double getCVM();
    void setCVM(double);
    double getChargeVente();
    void setChargeVente(double);

    /*
     *Methodes a appliquer
     */

    bool AjoutProd();
    qint64 calculDuree(QString, QString);
    QSqlQueryModel* afficherProduits();
    QSqlQueryModel* afficherTypeProd();
    QSqlRecord renvoiValeurs(QString);
    QSqlQueryModel* extraireProduits();
    bool ModifProd();
    QSqlQuery *testExistance(QString);



    bool validerProduitProduction();
    bool validerProduitVente();
    void calculerCoutProdMax();
    void calculerCoutVenteMin();
    void calculerDepensesProd();
    void calculerRevenusVente();
    QSqlQueryModel* afficherProduitsProdNV();
    QSqlQueryModel* afficherProduitsVenteNV();
    bool supprimerProduit();

    Connexion C;

};


#endif // PRODUIT_H
