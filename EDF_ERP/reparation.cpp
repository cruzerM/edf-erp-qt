#include "reparation.h"

Reparation::Reparation()
{
    IdReparation = 0;
    Panne = "";
    Produit = "";
    Etat = "En attente";
    Cout = 0.0;
}

Reparation::Reparation(int id, QString panne, QString prod, QString etat, double cout)
{
    IdReparation = id;
    Panne = panne;
    Produit = prod;
    Etat= etat;
    Cout = cout;
}

bool Reparation::testExistance(int id)
{
    //

    QSqlQuery * query_exist = new QSqlQuery();
    query_exist->prepare("SELECT IdReparation from Reparations where IdReparation = " + QString::number(id) + ";");

    if(query_exist->exec())
    {
        if (query_exist->next())
        {
            return true;
        }
    }
    else return false;

    return false;
}

bool Reparation::instancierReparation()
{
    //

    QSqlQuery * query_ajout = new QSqlQuery();
    query_ajout->prepare("Insert into Reparations (IdReparation, Panne, Etat, Cout, IdProduit) values (" + QString::number(IdReparation) + ",'" + Panne + "','" + Etat + "'," + QString::number(Cout) + ",'" + Produit + "');" );

    if (query_ajout->exec())
    {
        return true;
    }
    else return false;

return false;
}

bool Reparation::validerReparation()
{
   //
   QSqlQuery *qrtUpdate = new QSqlQuery();

   if(!(qrtUpdate->prepare("UPDATE Reparations SET Etat = :s where IdReparation = :id"))) return false;
   qrtUpdate->bindValue(":id", IdReparation);
   qrtUpdate->bindValue(":s", "En marche");
   qrtUpdate->exec();

   /************UPDATE Montant Depenses********/
   QSqlQuery *qrtDep = new QSqlQuery ();
   if(!(qrtDep->prepare("update Budgets set MontantDepenses = MontantDepenses + (select Cout from Reparations where IdReparation = :id)"))) return false;
   qrtDep->bindValue(":id", IdReparation);
   qrtDep->exec();


   return true;

}

QSqlQueryModel *Reparation::afficherReparationNV()
{

   QSqlQuery* qrt=new QSqlQuery();
   QSqlQueryModel *model=new QSqlQueryModel;

   qrt->prepare("select IdReparation, Cout, Etat from Reparations where Etat = :s");
   qrt->bindValue(":s", "En attente");
   qrt->exec();


   model->setQuery(*qrt);
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id Reparation"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Cout"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Etat"));

return model;

}
