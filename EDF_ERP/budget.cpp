#include "budget.h"

////////////////////////
void Budget::setIDBUDGET(int IdBudget)
{
    this->IdBudget = IdBudget;
}

void Budget::setBUDGETGLOB(double BudgetGlobal)
{
    this->BudgetGlobal = BudgetGlobal;
}

void Budget::setMNTREV(double MontantRevenus)
{
    this->MontantRevenus = MontantRevenus;
}

void Budget::setMNTDEP(double MontantDepenses)
{
    this->MontantDepenses = MontantDepenses;
}

void Budget::setTAXEREV(double TaxeRev) // à vérifier !!
{
    this->TaxeRev = TaxeRev ;
}

/////////////////////////
int Budget::getIDBUDGET()
{
    return IdBudget;
}


double Budget::getBUDGETGLOB()
{
    return BudgetGlobal;
}

double Budget::getMNTREV()
{
    return MontantRevenus;
}

double Budget::getMNTDEP()
{
    return MontantDepenses;
}

double Budget::getTAXEREV()
{
    return TaxeRev;
}


/////////////////////////

Budget::Budget ()
{
    IdBudget = 1;
    BudgetGlobal = 0;
    MontantRevenus = 0;
    MontantDepenses = 0;
    TaxeRev = 0;
}


QString Budget::afficherRevenus()
{

    QSqlQuery *qrt = new QSqlQuery();
    QString MontantRevenuss = "";
    if(!(qrt->prepare("select MontantRevenus from Budgets"))) return MontantRevenuss;
    if(qrt->exec()){
        while (qrt->next()) {
            MontantRevenuss = (qrt->value(0).toString());
        }
    }
    MontantRevenus = MontantRevenuss.toDouble();
    return MontantRevenuss;
}
QString Budget::afficherDepenses()
{

    QSqlQuery *qrt = new QSqlQuery();
    QString MontantDepensess = "";
    if(!(qrt->prepare("select MontantDepenses from Budgets"))) return MontantDepensess;
    if(qrt->exec()){
        while (qrt->next()) {
            MontantDepensess = (qrt->value(0).toString());
        }
    }
    MontantDepenses = MontantDepensess.toDouble();
    return MontantDepensess;
}

QString Budget::calculerBudgetGlobal() //Utilisation de TaxeRev ici !!
{

    QSqlQuery *qrtUpdate = new QSqlQuery ();
    QString BudgetGloball = "";
    if (!(qrtUpdate->prepare("update Budgets set BudgetGlobal = (MontantRevenus+(MontantRevenus*TaxeRev)) - MontantDepenses "))) return BudgetGloball;
    qrtUpdate->exec();
    QSqlQuery *qrtRead = new QSqlQuery ();
    if(!(qrtRead->prepare("select BudgetGlobal from Budgets"))) return BudgetGloball;
    if(qrtRead->exec()){
        while (qrtRead->next()) {
            BudgetGloball = (qrtRead->value(0).toString());
        }
    }

    BudgetGlobal = BudgetGloball.toDouble();

    return BudgetGloball;
}

