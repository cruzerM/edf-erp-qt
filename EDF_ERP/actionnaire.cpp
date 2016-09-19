#include "actionnaire.h"



///////////////////////////////////////
void Actionnaire::setIDACTIONNAIRE(int IdActionnaire)
{
    this->IdActionnaire = IdActionnaire;
}

void Actionnaire::setNOMACTIONN(QString NomActionnaire)
{
    this->NomActionnaire = NomActionnaire;
}

void Actionnaire::setTDIV(int TauxDividende)
{
    this->TauxDividende = TauxDividende;
}

void Actionnaire::setMNT(double Montant)
{
    this->Montant = Montant;
}

void Actionnaire::setDATEACHAT(QString DateAchat)
{
    this->DateAchat = DateAchat;
}

void Actionnaire::setSTATUT(bool Statut)
{
    this->Statut = Statut;
}
/////////////////////////////////////
int Actionnaire::getIDACTIONNAIRE()
{
    return IdActionnaire;
}

QString Actionnaire::getNOMACTIONN()
{
    return NomActionnaire;
}

int Actionnaire::getTDIV()
{
    return TauxDividende;
}

double Actionnaire::getMNT()
{
    return Montant;
}

QString Actionnaire::getDATEACHAT()
{
    return DateAchat;
}

bool Actionnaire::getSTATUT()
{
    return Statut;
}

/////////////////////////////////////


Actionnaire::Actionnaire ()
{
    IdActionnaire = 0;
    NomActionnaire = "";
    TauxDividende = 0;
    Montant = 0;
    DateAchat = "";
    Statut = 0;
}

bool Actionnaire::ajouterActionnaire()
{

        QSqlQuery *qrt = new QSqlQuery ();
        if(!(qrt->prepare("INSERT INTO Actionnaires (IdActionnaire, Taux_Dividende, MontantEmis, NomActionnaire, DateAchat, Statut) VALUES (?,?,?,?,?,?)"))) return false;
        qrt->addBindValue(IdActionnaire);
        qrt->addBindValue(TauxDividende);
        qrt->addBindValue(Montant);
        qrt->addBindValue(NomActionnaire);
        qrt->addBindValue(DateAchat);
        qrt->addBindValue(Statut);
        qrt->exec();

        return true;
}

bool Actionnaire::supprimerActionnaire()
{

    QSqlQuery *qrt = new QSqlQuery();

    if(!(qrt->prepare("delete from Actionnaires WHERE IdActionnaire = :i"))) return false;
    qrt->bindValue(":i", IdActionnaire);
    qrt->exec();
    return true;
}

bool Actionnaire::supprimerTTActionnaire()
{

    QSqlQuery *qrt = new QSqlQuery();
    if(!(qrt->prepare("delete from Actionnaires"))) return false;
    qrt->exec();
    return true;
}

bool Actionnaire::modifierActionnaire()
{

    QSqlQuery *qrt = new QSqlQuery ();

    if(!(qrt->prepare("update Actionnaires set NomActionnaire = :na, Taux_Dividende = :td, MontantEmis = :me, DateAchat = :da, Statut = :s where IdActionnaire = :id"))) return false;

    qrt->bindValue(":id", IdActionnaire);
    qrt->bindValue(":na", NomActionnaire);
    qrt->bindValue(":td", TauxDividende);
    qrt->bindValue(":me", Montant);
    qrt->bindValue(":da", DateAchat);
    qrt->bindValue(":s", Statut);
    qrt->exec();
    return true;
}

bool Actionnaire::validerActionnaire()
{

    QSqlQuery *qrt = new QSqlQuery();

    if(!(qrt->prepare("UPDATE Actionnaires SET Statut = :s WHERE IdActionnaire = :i"))) return false;
    qrt->bindValue(":s", true);
    qrt->bindValue(":i", IdActionnaire);
    qrt->exec();

    afficherActionnaire();
    /************UPDATE Montant Revenus********/
    QSqlQuery *qrtRev = new QSqlQuery ();
    if(!(qrtRev->prepare("update Budgets set MontantRevenus = MontantRevenus + (select MontantEmis from Actionnaires where IdActionnaire = :id)"))) return false;
    qrtRev->bindValue(":id", IdActionnaire);
    qrtRev->exec();

    /************UPDATE Montant Depenses********/
    QSqlQuery *qrtDep = new QSqlQuery ();
    if(!(qrtDep->prepare("update Budgets set MontantDepenses = MontantDepenses + "+QString::number(calculerDividende())+" "))) return false;
    qrtDep->exec();


    return true;
}

double Actionnaire::calculerDividende()
{
    return (Montant*(float(TauxDividende)/100.0));
}

bool Actionnaire::afficherActionnaire()
{

    QSqlQuery *qrt = new QSqlQuery();
    qrt->prepare("select * from Actionnaires where IdActionnaire = ?");
    qrt->addBindValue(IdActionnaire);
    if(qrt->exec()){
        while (qrt->next()) {

            TauxDividende = (qrt->value(1).toInt());
            Montant = (qrt->value(2).toDouble());
            NomActionnaire = (qrt->value(3).toString());
            Statut = (qrt->value(4).toBool());
            DateAchat = (qrt->value(5).toString());

            return true;
        }

    }
    return false;
}

bool Actionnaire::verifierExistenceActionnaire()
{

    QSqlQuery *qrt = new QSqlQuery ();
    qrt->prepare("select * from Actionnaires WHERE IdActionnaire= :i");
    qrt->bindValue(":i", IdActionnaire);
    if (qrt->exec())
    {
        if(qrt->next())
        return true;
    }

     else return false;
    return false;
}

QSqlQueryModel * Actionnaire::afficherHistoriqueActionnaire()
{


    QSqlQuery* qrt=new QSqlQuery();
    QSqlQueryModel *model=new QSqlQueryModel;

    qrt->prepare("select * from Actionnaires");
    qrt->exec();


    model->setQuery(*qrt);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id Actionnaire"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Taux Dividende"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Montant Emis"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom Actionnaire"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Statut"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date Achat"));

return model;
}

QSqlQueryModel * Actionnaire::afficherActionnaireNV()
{


    QSqlQuery* qrt=new QSqlQuery();
    QSqlQueryModel *model=new QSqlQueryModel;

    qrt->prepare("select * from Actionnaires where Statut = :s");
    qrt->bindValue(":s", false);
    qrt->exec();


    model->setQuery(*qrt);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id Actionnaire"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Taux Dividende"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Montant Emis"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom Actionnaire"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Statut"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Achat"));

return model;
}

int Actionnaire::calculerDuree()
{
    QDateTime dated (QDate( DateAchat.mid(6,4).toInt(), DateAchat.mid(3,2).toInt(), DateAchat.mid(0,2).toInt()));
    QDateTime datef (QDate::currentDate());
    int duree = dated.daysTo(datef);
    return duree;
}
