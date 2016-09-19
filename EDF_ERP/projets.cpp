#include "projets.h"




Projet::Projet()
{
     IdProjet = 0;
     BudgetProjet = 0;
     Statut = false;
}

///////////
int Projet::getIDPROJET()
{
    return IdProjet;
}

double Projet::getBUDPROJ()
{
    return BudgetProjet;
}

bool Projet::getSTATUT()
{
    return Statut;
}

void Projet::setIDPROJET(int IdProjet)
{
    this->IdProjet = IdProjet;
}

void Projet::setBUDPROJ(double BudgetProjet)
{
    this->BudgetProjet = BudgetProjet;
}

void Projet::setSTATUT(bool Statut)
{
    this->Statut = Statut;
}

///////////


bool Projet::validerBudgetProjet()
{
    
    QSqlQuery *qrt = new QSqlQuery();

    if(!(qrt->prepare("UPDATE Projets SET Statut = :s where IdProjet = :id"))) return false;
    qrt->bindValue(":id", IdProjet);
    qrt->bindValue(":s", true);
    qrt->exec();

    /************UPDATE Montant Depenses********/
    QSqlQuery *qrtDep = new QSqlQuery ();
    if(!(qrtDep->prepare("update Budgets set MontantDepenses = MontantDepenses + (select BudgetProjet from Projets where IdProjet = :id)"))) return false;
    qrtDep->bindValue(":id", IdProjet);
    qrtDep->exec();


    return true;
}

QSqlQueryModel * Projet::afficherProjetsNV()
{
    

    QSqlQuery* qrt=new QSqlQuery();
    QSqlQueryModel *model=new QSqlQueryModel;

    qrt->prepare("select * from Projets where Statut = :s");
    qrt->bindValue(":s", false);
    qrt->exec();


    model->setQuery(*qrt);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id Projet"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Budget Projet"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Statut"));

return model;

}
