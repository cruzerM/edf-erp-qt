#include"pub.h"



Pub::Pub()
{
    IdPub = 0;
    CoutPub = 0;
    Statut = false;
}

//////////////
void Pub::setSTATUT(bool Statut)
{
    this->Statut = Statut;
}

void Pub::setIDPUB(int IdPub)
{
    this->IdPub = IdPub;
}

/////////////////
bool Pub::getSTATUT()
{
    return Statut;
}

int Pub::getIDPUB()
{
    return IdPub;
}
//////////////

bool Pub::validerCoutPub()
{
    
    QSqlQuery *qrtUpdate = new QSqlQuery();

    if(!(qrtUpdate->prepare("UPDATE Pubs SET Statut = :s WHERE IdPub = :i"))) return false;
    qrtUpdate->bindValue(":s", true);
    qrtUpdate->bindValue(":i", IdPub);
    qrtUpdate->exec();

    /************UPDATE Montant Depenses********/
    QSqlQuery *qrtDep = new QSqlQuery ();
    if(!(qrtDep->prepare("update Budgets set MontantDepenses = MontantDepenses + (select CoutPub from Pubs where IdPub = :id)"))) return false;
    qrtDep->bindValue(":id", IdPub);
    qrtDep->exec();


    return true;

}
QSqlQueryModel * Pub::afficherPubsNV()
{
    

    QSqlQuery* qrt=new QSqlQuery();
    QSqlQueryModel *model=new QSqlQueryModel;

    qrt->prepare("select * from Pubs where Statut = :s");
    qrt->bindValue(":s", false);
    qrt->exec();


    model->setQuery(*qrt);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id Pub"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Coût Pub"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Statut"));

return model;

}
