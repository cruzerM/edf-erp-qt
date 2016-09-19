#include "production.h"

Production::Production()
{
    IdCommande = 0;
    IdProduit = "";
    Date = "";
    Responsable = "";
    Site_Production = "";
    IdProjet = 0;
    Quantite=0;
    Montant = 0;
    Statut = "";
}

Production::Production(long idV, QString idP, QString date, QString resp, QString site, long idProj, long qte, double mnt, QString statut)
{
    IdCommande = idV;
    IdProduit = idP;
    Date=date;
    Responsable = resp;
    Site_Production = site;
    IdProjet = idProj;
    Quantite = qte;
    Montant = mnt;
    Statut = statut;
}

bool Production::AjoutCommande()
{
    

    QSqlQuery *query = new QSqlQuery();
    qDebug() << "IdProduit " << IdProduit;
    query->prepare("Insert Into Production (IdCommande, IdProduit, Quantite, Responsable, Date, Site, IdProjet, Statut, Montant) values (" + QString::number(IdCommande) + ", '" + IdProduit + "'," + QString::number(extraireQte()) + ",'" + Responsable + "','" + Date +"','"+ Site_Production + "'," + QString::number(IdProjet) + ", '" + Statut + "'," + QString::number(calculerMontantProduction()) + ");");

    if(query->exec())
    {
        Messagerie *M = new Messagerie();
        M->setDestinataire("Amri Mahmoud");
        M->setExpediteur("Responsable Production");
        M->setMessage("Veuiller, je vous pris, confirmer la commande Numero=" + QString::number(IdCommande));
        M->setEtat(1);
        M->envoyerMessage();

        return true;
    }

    else
        return false;

return false;
}

QSqlQueryModel* Production::afficherTypeProjet()
{
    
    QSqlQueryModel *modal_projet = new QSqlQueryModel();
    QSqlQuery *query_projet = new QSqlQuery();
    query_projet->prepare("SELECT DISTINCT IdProjet from Produits");
    query_projet-> exec();
    modal_projet->setQuery(*query_projet);

    return modal_projet;

}

QSqlQueryModel* Production::afficherProduits()
{
    QSqlQueryModel *modal = new QSqlQueryModel();
    
    QSqlQuery *query = new QSqlQuery();

    query->prepare("SELECT IdProjet, Nom, Date_Debut_Production, Date_Fin_Production, Responsable from Produits");
    query-> exec();
    modal->setQuery(*query);

    return modal;
}

double Production::calculerMontantProduction()
{
    
    QSqlQuery *query = new QSqlQuery();

    query->prepare("SELECT Quantite, Cout_Max from Produits where Nom = '" + IdProduit + "';");
    query-> exec();
    if (query->next())
    {
        return ((query->value(1).toDouble()) * (query->value(0).toInt()));
    }
return 0;
}

int Production::extraireQte()
{
    
    QSqlQuery *query = new QSqlQuery();

    query->prepare("SELECT Quantite as qty from Produits where Nom = '" + IdProduit + "';");
    query-> exec();
    if (query->next())
    {
        return query->value(0).toInt();
    }
    return 0;
}

QSqlQueryModel* Production::extraireCommande()
{
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();

    query->prepare("SELECT IdCommande from Production");
    query-> exec();
    modal->setQuery(*query);

    return modal;
}

QSqlQuery* Production::testExistance(int idc)
{

    QSqlQuery *query = new QSqlQuery();
    query->prepare("SELECT * from Production where IdCommande="+ QString::number(idc) + " and Statut != 'Production confirmee';");

    if (query->exec())
    {
        if (query->next())
        {
             return query;
        }
    }

    return query;
}

QSqlQuery* Production::testExistanceConfirmee(int idc)
{

    QSqlQuery *query = new QSqlQuery();
    query->prepare("SELECT * from Production where IdCommande="+ QString::number(idc) + " and Statut = 'Production confirmee';");

    if (query->exec())
    {
        if (query->next())
        {
             return query;
        }
    }

    return query;
}

QSqlRecord Production::renvoiValeurs(int idc)
{

    QSqlQuery query;
    query.prepare("SELECT * from Production where IdCommande=("+ QString::number(idc) + ");");

    if (query.exec())
    {
        if (query.next())
        {
             return query.record();
        }

    }
    return query.record();
}

bool Production::changerEtat(int idc)
{
    QSqlQuery query;
    if(query.exec("UPDATE Production set Statut='Production terminee' where IdCommande = " + QString::number(idc) + ";"))
    {
        return true;
    }
    else
        return false;

return false;
}
