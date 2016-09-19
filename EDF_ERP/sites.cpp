#include "sites.h"

Sites::Sites()
{
    Nom = "";
    Ville = "";
    Dept = "";
    Nature = "";
    Capacite = 0;
}

Sites::Sites(QString n, QString v, QString d, QString nat, long cap)
{
    Nom = n;
    Ville = v;
    Dept = d;
    Nature = nat;
    Capacite = cap;
}

bool Sites::ajouterSiteProd()
{
    Connexion C;
    

    QString Emp = Ville + " (" + Dept + ")";
    QSqlQuery *query = new QSqlQuery();

    query->prepare("INSERT INTO Sites (Type, Nom, Emplacement, Nature) values ('Site de Production','" + Nom +"','" + Emp + "','" + Nature + "');");

    if(query->exec())
    {
        return true;
    }

    else
        return false;

return false;
}

bool Sites::ajouterSiteStock()
{
    Connexion C;
    

    QString Emp = Ville + " (" + Dept + ")";
    QSqlQuery *query = new QSqlQuery();

    query->prepare("INSERT INTO Sites (Type, Nom, Emplacement, Nature, Capacite) values ('Site de Stockage','" + Nom +"','" + Emp + "','" + Nature + "'," + QString::number(Capacite) + ");");

    if(query->exec())
    {
        return true;
    }

    else
        return false;

return false;
}


QSqlQueryModel* Sites::afficherSiteProd()
{
    Connexion C;
    

    QSqlQueryModel *modal_site = new QSqlQueryModel();
    QSqlQuery *query_site = new QSqlQuery(C.DB);
    query_site->prepare("SELECT DISTINCT Nom from Sites where Type=('Site de Production');");
    query_site-> exec();
    modal_site->setQuery(*query_site);

    return modal_site;
}

QSqlQueryModel* Sites::afficherSiteStock()
{
    Connexion C;
    

    QSqlQueryModel *modal_site = new QSqlQueryModel();
    QSqlQuery *query_site = new QSqlQuery(C.DB);
    query_site->prepare("SELECT DISTINCT Nom from Sites where Type=('Site de Stockage');");
    query_site-> exec();
    modal_site->setQuery(*query_site);

    return modal_site;
}

QSqlQueryModel* Sites::extraireSiteProd()
{
    Connexion C;
    

    QSqlQueryModel *modal_prod = new QSqlQueryModel();
    QSqlQuery *query_prod = new QSqlQuery(C.DB);

    query_prod->prepare("SELECT * from Sites where Type =('Site de Production');");
    query_prod-> exec();

    modal_prod->setQuery(*query_prod);

    return modal_prod;
}

QSqlQueryModel* Sites::extraireSiteStock()
{
    Connexion C;
    

    QSqlQueryModel *modal_stock = new QSqlQueryModel();
    QSqlQuery *query_stock = new QSqlQuery(C.DB);

    query_stock->prepare("SELECT * from Sites where Type =('Site de Stockage');");
    query_stock-> exec();

    modal_stock->setQuery(*query_stock);

    return modal_stock;
}

QSqlQueryModel* Sites::extraireEmplacement()
{
    Connexion C;
    
    QSqlQueryModel *modal_entr = new QSqlQueryModel();
    QSqlQuery *query_entr = new QSqlQuery(C.DB);
    query_entr->prepare("SELECT DISTINCT Emplacement from Sites;");
    query_entr-> exec();
    modal_entr->setQuery(*query_entr);

    return modal_entr;
}
