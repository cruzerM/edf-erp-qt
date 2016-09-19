#include"commande.h"


Commande::Commande()
{
     IdCommande = 0;
     Somme = 0;
     Statut = false;

}

/////////////
void Commande::setSTATUT(bool Statut)
{
    this->Statut = Statut;
}

void Commande::setIDCOMMANDE(int IdCommande)
{
    this->IdCommande = IdCommande;
}

bool Commande::getSTATUT()
{
    return Statut;
}

int Commande::getIDCOMMANDE()
{
    return IdCommande;
}

/////////////

bool Commande::validerCommande()
{
    
    QSqlQuery *qrtUpdate = new QSqlQuery();

    if(!(qrtUpdate->prepare("UPDATE Commandes SET Statut = :s WHERE IdCommande = :i"))) return false;
    qrtUpdate->bindValue(":s", true);
    qrtUpdate->bindValue(":i", IdCommande);
    qrtUpdate->exec();

    /************UPDATE Montant Depenses********/
    QSqlQuery *qrtDep = new QSqlQuery ();
    if(!(qrtDep->prepare("update Budgets set MontantDepenses = MontantDepenses + (select Somme from Commandes where IdCommande = :id)"))) return false;
    qrtDep->bindValue(":id", IdCommande);
    qrtDep->exec();


    return true;

}

QSqlQueryModel * Commande::afficherCommandesNV()
{
    

    QSqlQuery* qrt=new QSqlQuery();
    QSqlQueryModel *model=new QSqlQueryModel;

    qrt->prepare("select * from Commandes where Statut = :s");
    qrt->bindValue(":s", false);
    qrt->exec();


    model->setQuery(*qrt);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id Commande"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Somme Commande"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Statut"));

return model;

}
