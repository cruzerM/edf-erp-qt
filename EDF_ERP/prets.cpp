#include"prets.h"



#include <QDate>

Pret::Pret()
{
    IdPret = 0;
    MontantPret = 0;
    DatePretD = "";
    DatePretF = "";
    TauxInteret = 0;
    MontantFinal = 0;
    Statut = false;
}

/////////////////////////////////////////////////
void Pret::setIDPRET(int IdPret){
    this->IdPret = IdPret;
}

void Pret::setMONTPRET(double MontantPret){
    this->MontantPret = MontantPret;
}

void Pret::setDatePretD(QString DatePretD){
    this->DatePretD = DatePretD;
}
void Pret::setDatePretF(QString DatePretF){
    this->DatePretF = DatePretF;
}
void Pret::setNOMBANQUE(QString NomBanque){
    this->NomBanque = NomBanque;
}

void Pret::setCAUSE(QString Cause){
    this->Cause = Cause;
}

void Pret::setTINT(int TauxInteret){
    this->TauxInteret = TauxInteret;
}

void Pret::setMONTF(double MontantFinal){
    this->MontantFinal = MontantFinal;
}

void Pret::setSTATUT(bool Statut){
    this->Statut = Statut;
}
/////////////////////////////////////////////
int Pret::getIDPRET(){
    return IdPret;
}

double Pret::getMONTPRET(){
    return MontantPret;
}

QString Pret::getNOMBANQUE(){
    return NomBanque;
}
QString Pret::getCAUSE(){
    return Cause;
}

QString Pret::getDatePretD(){
    return DatePretD;
}
QString Pret::getDatePretF(){
    return DatePretF;
}

int Pret::getTINT(){
    return TauxInteret;
}

double Pret::getMONTF(){
    return MontantFinal;
}

bool Pret::getSTATUT(){
    return Statut;
}
////////////////////////////////////////


QSqlQueryModel * Pret::afficherHistoriquePret(){

    //

    QSqlQuery* qrt=new QSqlQuery();
    QSqlQueryModel *model=new QSqlQueryModel;

    qrt->prepare("select * from Prets");
    qrt->exec();


    model->setQuery(*qrt);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id Prêt"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Banque"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Cause"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Montant primaire"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Intèrêt"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Statut"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date début"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Date fin"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Montant final"));

return model;
}


QSqlQueryModel * Pret::afficherPretsNV()
{


    QSqlQuery* qrt=new QSqlQuery();
    QSqlQueryModel *model=new QSqlQueryModel;

    qrt->prepare("select * from Prets where Statut = :s");
    qrt->bindValue(":s", false);
    qrt->exec();


    model->setQuery(*qrt);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id Prêt"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Banque"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Cause"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Montant initiale"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Intèrêt"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Statut"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date début"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Date fin"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Montant final"));

return model;

}

bool Pret::ajouterPret(){


        QSqlQuery *qrt = new QSqlQuery ();
        if(!(qrt->prepare("INSERT INTO Prets (IdPret, Banque, Montant_sansINT, Interet, Date_Debut, Date_Fin, Cause, Statut, Montant_avecINT) VALUES (?,?,?,?,?,?,?,?,?)"))) return false;
        qrt->addBindValue(IdPret);
        qrt->addBindValue(NomBanque);
        qrt->addBindValue(MontantPret);
        qrt->addBindValue(TauxInteret);
        qrt->addBindValue(DatePretD);
        qrt->addBindValue(DatePretF);
        qrt->addBindValue(Cause);
        qrt->addBindValue(Statut);
        qrt->addBindValue(MontantFinal);
        qrt->exec();

        return true;
}

void Pret::calculerInteret()
{
    /*montant = montant + (montant*(float(interet)/100.0));
    return montant;*/
    MontantFinal = MontantPret + (MontantPret*(float(TauxInteret)/100.0));
}


bool Pret::afficherPret()
{

    QSqlQuery *qrt = new QSqlQuery();
    qrt->prepare("select * from Prets where IdPret = ?");
    qrt->addBindValue(IdPret);
    if(qrt->exec()){
        while (qrt->next()) {

            NomBanque = (qrt->value(1).toString());
            Cause = (qrt->value(2).toString());
            MontantPret = (qrt->value(3).toDouble());
            TauxInteret = (qrt->value (4).toInt());
            Statut = (qrt->value(5).toBool());
            DatePretD = (qrt->value(6).toString());
            DatePretF = (qrt->value(7).toString());
            MontantFinal = (qrt->value(8).toDouble());


            C.FermerConnexionBD();
            return true;
        }

    }
    return false;
}

bool Pret::validerPret()
{

    QSqlQuery *qrtUpdate = new QSqlQuery();

    if(!(qrtUpdate->prepare("UPDATE Prets SET Statut = :s WHERE IdPret = :i"))) return false;
    qrtUpdate->bindValue(":s", true);
    qrtUpdate->bindValue(":i", IdPret);
    qrtUpdate->exec();

    /************UPDATE Montant Revenus********/
    QSqlQuery *qrtRev = new QSqlQuery ();
    if(!(qrtRev->prepare("update Budgets set MontantRevenus = MontantRevenus + (select Montant_sansINT from Prets where IdPret = :id)"))) return false;
    qrtRev->bindValue(":id", IdPret);
    qrtRev->exec();

    /************UPDATE Montant Depenses********/
    QSqlQuery *qrtDep = new QSqlQuery ();
    if(!(qrtDep->prepare("update Budgets set MontantDepenses = MontantDepenses + (select Montant_avecINT from Prets where IdPret = :id)"))) return false;
    qrtDep->bindValue(":id", IdPret);
    qrtDep->exec();


    return true;
}

int Pret::calculerDureePret()
{
    int dd = DatePretD.mid(0,2).toInt();
    int md = DatePretD.mid(3,2).toInt();
    int yd = DatePretD.mid(6,4).toInt();
    int df = DatePretF.mid(0,2).toInt();
    int mf = DatePretF.mid(3,2).toInt();
    int yf = DatePretF.mid(6,4).toInt();
    QDateTime dated (QDate(yd, md, dd));
    QDateTime datef (QDate(yf, mf, df));
    qint64 date = dated.daysTo(datef);
    //QString duree = QString("%1 jour(s) %2 mois %3 année(s)").arg(qAbs(dd-df)).arg(qAbs(md-mf)).arg(qAbs(yd-yf));
    return date;
}

bool Pret::modifierPret()
{

    QSqlQuery *qrt = new QSqlQuery ();

    if(!(qrt->prepare("update Prets set Banque = :b, Cause = :c, Montant_sansINT = :mi, Interet = :i, Statut = :s, Date_Debut = :dd, Date_Fin = :df, Montant_avecINT = :mf where IdPret = :id"))) return false;

    qrt->bindValue(":id", IdPret);
    qrt->bindValue(":b", NomBanque);
    qrt->bindValue(":c", Cause);
    qrt->bindValue(":mi", MontantPret);
    qrt->bindValue(":i", TauxInteret);
    qrt->bindValue(":s", Statut);
    qrt->bindValue(":dd", DatePretD);
    qrt->bindValue(":df", DatePretF);
    qrt->bindValue(":mf", MontantFinal);
    qrt->exec();
    return true;
}


bool Pret::supprimerPret()
{

    QSqlQuery *qrt = new QSqlQuery();

    if(!(qrt->prepare("delete from Prets WHERE IdPret = :i"))) return false;
    qrt->bindValue(":i", IdPret);
    qrt->exec();
    return true;
}

bool Pret::supprimerTTPret()
{

    QSqlQuery *qrt = new QSqlQuery();
    if(!(qrt->prepare("delete from Prets where Statut = :s"))) return false;
    qrt->bindValue(":s", false);
    qrt->exec();
    return true;
}

bool Pret::verifierExistencePret()
{

    QSqlQuery *qrt = new QSqlQuery ();
    qrt->prepare("select * from Prets WHERE IdPret = :i");
    qrt->bindValue(":i", IdPret);
    if (qrt->exec())
    {
        if(qrt->next())
        return true;
    }

     else return false;
    return false;
}
