#include "matierep.h"

MatiereP::MatiereP()
{
    Identifiant = "";
    Identifiant_Produit = "";
    Type = "";
    Cout = 0.0;
    Statut = false;
}

MatiereP::MatiereP(QString Id, QString IdP, QString type, double c, bool Statut)
{
    Identifiant = Id;
    Identifiant_Produit = IdP;
    Type = type;
    Cout=c;
    this->Statut = Statut;
}

QString MatiereP::getIdentifiant()
{
    return Identifiant;
}
void MatiereP::setIdentifiant(QString id)
{
    Identifiant=id;
}

QString MatiereP::getIdentifiant_Produit()
{
    return Identifiant_Produit;
}
void MatiereP::setIdentifiant_Produit(QString id)
{
    Identifiant_Produit=id;
}

QString MatiereP::getType()
{
    return Type;
}
void MatiereP::setType(QString type)
{
    Type=type;
}

void MatiereP::setStatut(bool Statut)
{
    this->Statut = Statut;
}

bool MatiereP::getStatut()
{
    return Statut;
}


bool MatiereP::addMatierePremiere()
{

        QSqlQuery query_ajout;
        if(query_ajout.exec("INSERT INTO MP (IdMP, Type, IdProduit, Cout, Statut) VALUES ('"+ Identifiant +"','"+ Type +"','" + Identifiant_Produit +"', " + QString::number(Cout) + ", " + QString::number(Statut) + ");"))
        {
            return true;
        }
        else return false;
    return false;
}

bool MatiereP::controlExistance(QString id)
{
    
    QSqlQuery query;

    query.prepare("SELECT IdMP from MP where IdMP=('"+ id + "');");

    if (query.exec())
    {
        if (query.next())
        {
            return true;
        }
    }
    return false;
}

QSqlQueryModel* MatiereP::updateListe()
{
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();
    query->prepare("SELECT * from MP;");
    query->exec();
    modal->setQuery(*query);

    return modal;
}



bool MatiereP::validerDevis()
{
    
    QSqlQuery *qrtUpdate = new QSqlQuery();

    if(!(qrtUpdate->prepare("UPDATE MP SET Statut = :s WHERE IdMP = :i"))) return false;
    qrtUpdate->bindValue(":s", true);
    qrtUpdate->bindValue(":i", Identifiant);
    qrtUpdate->exec();

    //************UPDATE Montant Depenses********
    QSqlQuery *qrtDep = new QSqlQuery ();
    if(!(qrtDep->prepare("update Budgets set MontantDepenses = MontantDepenses + (select Cout from MP where IdMP = :id)"))) return false;
    qrtDep->bindValue(":id", Identifiant);
    qrtDep->exec();


    return true;

}

QSqlQueryModel * MatiereP::afficherDevisNV()
{
    

    QSqlQuery* qrt=new QSqlQuery();
    QSqlQueryModel *model=new QSqlQueryModel;

    qrt->prepare("select IdMP, Cout, Statut from MP where Statut = :s");
    qrt->bindValue(":s", 0);
    qrt->exec();


    model->setQuery(*qrt);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id Devis"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Montant"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Statut"));

return model;

}

