#include "fproduction.h"
#include "produit.h"
#include "fajoutprod.h"
#include "connexion.h"

#include <QString>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>

using namespace std;

Produit::Produit()
{
    IdProduit="";
    id_project=0;
    projectState="";
    DateDebutProd = "";
    DateFinProd="";
    EmplacementProd="Lyon";
    EmplacementStockage="default";
    Responsable="Chef Projet";
    barcode="";
    Quantite=0;
    But="";
    Entrepot="";
    Categorie="";
    Nom="";
    Duree=0;
    CoutProdFinal = 0;
    CoutProdMax = 0;
    chargeProd = 0.32;
    CoutVenteFinal = 0.15;
    CoutVenteMin = 0;
    chargeVente = 0;
    StatutVente = "";
    StatutProd = "";

}
QString Produit::getEntrepot()
{
    return Entrepot;
}
void Produit::setEntrepot(QString entrp)
{
    Entrepot=entrp;
}

int Produit::getDuree()
{
    return Duree;
}
void Produit::setDuree(int d)
{
    Duree=d;
}

QString Produit::getNom()
{
    return Nom;
}
void Produit::setNom(QString nom)
{
    Nom=nom;
}

QString Produit::getCategorie()
{
    return Categorie;
}
void Produit::setCategorie(QString cat)
{
    Categorie=cat;
}

QString Produit::getBut()
{
    return But;
}
void Produit::setBut(QString B)
{
    But=B;
}

QString Produit::getEmpStock()
{
    return EmplacementStockage;
}
void Produit::setEmpStock(QString emp_stock)
{
    EmplacementStockage=emp_stock;
}

int Produit::getQte()
{
    return Quantite;
}
void Produit::setQte(int quantite)
{
    Quantite=quantite;
}

QString Produit::getBarCode()
{
    return barcode;
}
void Produit::setBarCode(QString bar)
{
    barcode=bar;
}

QString Produit::getEmpProd()
{
    return EmplacementProd;
}
void Produit::setEmpProd(QString emp_prod)
{
    EmplacementProd=emp_prod;
}

QString Produit::getId_prod()
{
    return IdProduit;
}
void Produit::setId_prod(QString idp)
{
    IdProduit=idp;
}

int Produit::getId_proj()
{
    return id_project;
}
void Produit::setId_proj(int idp)
{
    id_project=idp;
}

QString Produit::getProjState()
{
    return projectState;
}
void Produit::setProjState(QString state)
{
    projectState=state;
}

QString Produit::getDateDebut()
{
    return DateDebutProd;
}
void Produit::setDateDebut(QString date)
{
    DateDebutProd=date;
}

QString Produit::getDateFin()
{
    return DateFinProd;
}
void Produit::setDateFin(QString date)
{
    DateFinProd=date;
}

QString Produit::getResponsable()
{
    return Responsable;
}
void Produit::setResponsable(QString resp)
{
    Responsable=resp;
}

double Produit::getCPF()
{
    return CoutProdFinal;
}

void Produit::setCPF(double CoutProdFinal)
{
    this->CoutProdFinal = CoutProdFinal;
}

double Produit::getCPM()
{
    return CoutProdMax;
}

void Produit::setCPM(double CoutProdMax)
{
    this->CoutProdMax = CoutProdMax;
}

double Produit::getChargeProd()
{
    return chargeProd;
}

void Produit::setChargeProd(double chargeProd)
{
    this->chargeProd = chargeProd;
}

/*
* VENTE
*/

double Produit::getCVF()
{
    return CoutVenteFinal;
}

void Produit::setCVF(double CoutVenteFinal)
{
    this->CoutVenteFinal=CoutVenteFinal;
}

double Produit::getCVM()
{
    return CoutVenteMin;
}

void Produit::setCVM(double CoutVenteMin)
{
    this->CoutVenteMin = CoutVenteMin;
}

double Produit::getChargeVente()
{
    return chargeVente;
}

void Produit::setChargeVente(double chargeVente)
{
    this->chargeVente = chargeVente;
}

QString Produit::getStatutProd()
{
    return StatutProd;
}

void Produit::setStatutProd(QString Statut)
{
    this->StatutProd=Statut;
}

QString Produit::getStatutVente()
{
    return StatutVente;
}

void Produit::setStatutVente(QString Statut)
{
    this->StatutVente=Statut;
}

bool Produit::AjoutProd()
{
    if (C.ConnectionBD())
    {
        QSqlQuery query_ajout;
        if(query_ajout.exec("INSERT INTO Produits (IdProduit, IdProjet, Nom, Emplacement_Stockage, Entrepot, Categorie, But, Code_Barres, Etat_Projet, Date_Debut_Production, Date_Fin_Production,Duree, Responsable, Cout_Max, Quantite, StatutProd, StatutVente) VALUES ('"+ IdProduit +"',"+ QString::number(id_project) +",'" + Nom +"','"+ EmplacementProd +"','"+ Entrepot +"','" + Categorie +"','" + But + "','" + barcode + "','" + projectState + "','" + DateDebutProd + "','" + DateFinProd + "'," + QString::number(Duree) +  ",'"+Responsable+ "'," + QString::number(CoutProdMax) + "," + QString::number(Quantite) +",'" + StatutProd + "','');"))
        {
            qDebug() << "Ajout effectué!";
            return true;
        }
        else return false;
    }
    return false;
}

qint64 Produit::calculDuree(QString DateD, QString DateF)
{
    int dd = DateD.mid(0,2).toInt();
    int md = DateD.mid(3,2).toInt();
    int ad = DateD.mid(6,4).toInt();
    int df = DateF.mid(0,2).toInt();
    int mf = DateF.mid(3,2).toInt();
    int af = DateF.mid(6,4).toInt();

    QDateTime dateDeb (QDate(ad, md, dd));
    QDateTime dateFin (QDate(af, mf, df));

    return dateDeb.daysTo(dateFin);
}

QSqlQueryModel* Produit::afficherProduits()
{
    
    QSqlQueryModel *modal = new QSqlQueryModel();

    QSqlQuery *query = new QSqlQuery();
    query->prepare("SELECT * from Produits ORDER BY IdProduit ASC");
    query-> exec();
    modal->setQuery(*query);

    return modal;
}

QSqlQueryModel* Produit::afficherTypeProd()
{
    
    QSqlQueryModel *modal_produit = new QSqlQueryModel();

    QSqlQuery *query_produit = new QSqlQuery();
    query_produit->prepare("SELECT Nom from Produits where StatutProd = 'Confirmé'");
    query_produit-> exec();
    modal_produit->setQuery(*query_produit);

    return modal_produit;
}

QSqlRecord Produit::renvoiValeurs(QString nom)
{
    
    QSqlQuery query;
    query.prepare("SELECT * from Produits where Nom=('"+ nom + "');");

    if (query.exec())
    {
        if (query.next())
        {
             return query.record();
        }

    }
    return query.record();
}

QSqlQueryModel* Produit::extraireProduits()
{
    QSqlQueryModel *modal = new QSqlQueryModel();
    
    QSqlQuery *query = new QSqlQuery();

    query->prepare("SELECT * from Produits");
    query-> exec();
    modal->setQuery(*query);

    return modal;
}


bool Produit::ModifProd()
{
    
    QSqlQuery query;

    query.prepare("Update Produits set Cout_Max=(" + QString::number(CoutProdMax) + "), Quantite =(" + QString::number(Quantite) + "), Etat_Projet=('" + projectState + "'), Date_Debut_Production = ('" + DateDebutProd + "'), Date_Fin_Production=('" + DateFinProd + "'), Duree=(" + QString::number(Duree) + ") where (Nom = ('" + Nom + "'));");

            if (query.exec())
            {
                return true;
            }

        else return false;
return false;
}

QSqlQuery* Produit::testExistance(QString nom)
{
    
    QSqlQuery *query = new QSqlQuery();
    query->prepare("SELECT * from Produits where Nom=('"+ nom + "');");

    if (query->exec())
    {
        if (query->next())
        {
             return query;
        }
    }

    return query;
}

bool Produit::supprimerProduit()
{

    QSqlQuery *qrt = new QSqlQuery();

    if(!(qrt->prepare("delete from Produits WHERE IdProduit = :i"))) return false;
    qrt->bindValue(":i", IdProduit);
    qrt->exec();
    return true;
}
bool Produit::validerProduitProduction()
{
    
    QSqlQuery *qrtUpdate = new QSqlQuery();

       if(!(qrtUpdate->prepare("UPDATE Production SET Statut = :s WHERE IdProduit = :i and Statut = :sp"))) return false;
       qrtUpdate->bindValue(":s", "Production confirmee");
       qrtUpdate->bindValue(":i", IdProduit);
       qrtUpdate->bindValue(":sp", "Production en attente");
       if(qrtUpdate->exec())
       {
           calculerCoutProdMax();
           return true;
       }
       else
           return false;

return false;

}

bool Produit::validerProduitVente()
{

    QSqlQuery *qrtUpdate = new QSqlQuery();

       if(!(qrtUpdate->prepare("UPDATE Produits SET StatutVente = :s WHERE IdProduit = :i and StatutVente = :sp"))) return false;
       qrtUpdate->bindValue(":s", "Vente confirmee");
       qrtUpdate->bindValue(":i", IdProduit);
       qrtUpdate->bindValue(":sp", "Vente en attente");
       qrtUpdate->exec();

       calculerCoutVenteMin();

       return true;

}
void Produit::calculerCoutProdMax()
{
    
    QSqlQuery *qrtUpdate = new QSqlQuery();

       if(!(qrtUpdate->prepare("UPDATE Produits SET Cout_Max = :s WHERE IdProduit = :i"))) return ;
       CoutProdMax += CoutProdMax*chargeProd;
       qrtUpdate->bindValue(":s", CoutProdMax);
       qrtUpdate->bindValue(":i", IdProduit);
       qrtUpdate->exec();
       //calculerDepensesProd();
}

void Produit::calculerCoutVenteMin()
{
    

    QSqlQuery *qrtUpdate = new QSqlQuery();

       if(!(qrtUpdate->prepare("UPDATE Produits SET Cout_Min = :s, StatutVente =:ss WHERE IdProduit = :i and StatutProd = :sp"))) return ;
       CoutVenteMin = CoutProdFinal + (CoutProdFinal*chargeVente);
       qrtUpdate->bindValue(":s", CoutVenteMin);
       qrtUpdate->bindValue(":ss", "Vente confirmee");
       qrtUpdate->bindValue(":i", IdProduit);
       qrtUpdate->bindValue(":sp", "Production terminee");
       qrtUpdate->bindValue(":sv", "Vente en attente");
       qrtUpdate->exec();
       //calculerRevenusVente();

}

void Produit::calculerDepensesProd()
{
    
    /************UPDATE Montant Depenses********/
      QSqlQuery *qrtDep = new QSqlQuery ();
      if(!(qrtDep->prepare("update Budgets set MontantDepenses = MontantDepenses + (select Montant from Produits where IdProduit = :id and Statut = :sp)"))) return;
      qrtDep->bindValue(":id", IdProduit);
      qrtDep->bindValue(":sp", "Production terminee");
      qrtDep->exec();
}

void Produit::calculerRevenusVente()
{
    
    /************UPDATE Montant Revenus********/
       QSqlQuery *qrtDep = new QSqlQuery ();
       if(!(qrtDep->prepare("update Budgets set MontantRevenus = MontantRevenus + (select (Cout_Vente*Quantite_Vente) from Produits where IdProduit = :id and StatutVente = :sv)"))) return;
       qrtDep->bindValue(":id", IdProduit);
       qrtDep->bindValue(":st", "Vente terminee");
       qrtDep->exec();
       supprimerProduit();
}

QSqlQueryModel * Produit::afficherProduitsProdNV()
{
    

    QSqlQuery* qrt=new QSqlQuery();
    QSqlQueryModel *model=new QSqlQueryModel;

    qrt->prepare("select IdProduit, IdProjet, Quantite, Montant, Statut from Production where Statut = :s");
    qrt->bindValue(":s", "Production en attente");
    qrt->exec();


    model->setQuery(*qrt);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id Produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Id Projet"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Quantite"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Montnat"));



return model;

}

QSqlQueryModel * Produit::afficherProduitsVenteNV()
{


    QSqlQuery* qrt=new QSqlQuery();
    QSqlQueryModel *model=new QSqlQueryModel;

    qrt->prepare("select IdProduit, IdProjet, Quantite, Montant, Statut from Production where Statut = :s");
    qrt->bindValue(":s", "Production terminee");
    qrt->exec();


    model->setQuery(*qrt);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id Produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Id Projet"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Quantite"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Montant"));


return model;

}
