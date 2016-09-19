#include"sponsor.h"


//////////////////////////////////
void Sponsor::setIDSPONSOR(int IdSponsor)
{
    this->IdSponsor = IdSponsor;
}

void Sponsor::setNOMSPONSOR(QString NomSponsor)
{
    this->NomSponsor = NomSponsor;
}

void Sponsor::setSOMME(double Somme)
{
    this->Somme = Somme;
}
void Sponsor::setDATEDEBUT(QString DateDebut)
{
    this->DateDebut = DateDebut;
}

void Sponsor::setDATEFIN (QString DateFin)
{
    this->DateFin = DateFin;
}

void Sponsor::setDUREE(int Duree)
{
    this->Duree = Duree ;
}

void Sponsor::setSTATUT(bool Statut)
{
    this->Statut = Statut;
}

/////////////////////////////////////////
int Sponsor::getIDSPONSOR()
{
    return IdSponsor;
}

QString Sponsor::getNOMSPONSOR()
{
    return NomSponsor;
}

double Sponsor::getSOMME()
{
    return Somme;
}

int Sponsor::getDUREE()
{
    return Duree;
}
QString Sponsor::getDATEDEBUT()
{
    return DateDebut;
}

QString Sponsor::getDATEFIN()
{
    return DateFin;
}

bool Sponsor::getSTATUT()
{
    return Statut;
}
//////////////////////////////////////////


Sponsor::Sponsor()
{
    IdSponsor = 0;
    NomSponsor = "";
    Somme = 0;
    Duree = 0;
    DateDebut = "";
    DateFin = "";
    Statut = 0;
}

bool Sponsor::ajouterSponsor()
{
    
    QSqlQuery *qrt = new QSqlQuery ();
        if(!(qrt->prepare("INSERT INTO Sponsors (IdSponsor, NomSponsor, Somme, Duree, Statut, Date_Debut, Date_Fin) VALUES (?,?,?,?,?,?,?)"))) return false;
        qrt->addBindValue(IdSponsor);
        qrt->addBindValue(NomSponsor);
        qrt->addBindValue(Somme);
        qrt->addBindValue(Duree);
        qrt->addBindValue(Statut);
        qrt->addBindValue(DateDebut);
        qrt->addBindValue(DateFin);

        qrt->exec();

        return true;
}

bool Sponsor::supprimerSponsor()
{
    
    QSqlQuery *qrt = new QSqlQuery();

    if(!(qrt->prepare("delete from Sponsors WHERE IdSponsor = :i"))) return false;
    qrt->bindValue(":i", IdSponsor);
    qrt->exec();
    return true;
}

bool Sponsor::supprimerTTSponsor()
{
    
    QSqlQuery *qrt = new QSqlQuery();
    if(!(qrt->prepare("delete from Sponsors"))) return false;
    qrt->exec();
    return true;
}

bool Sponsor::modifierSponsor()
{
    
    QSqlQuery *qrt = new QSqlQuery ();

    if(!(qrt->prepare("update Sponsors set NomSponsor = :ns, Somme = :sm, Duree = :d, Statut = :s, Date_Debut = :dd, Date_Fin = :df where IdSponsor = :id"))) return false;

    qrt->bindValue(":id", IdSponsor);
    qrt->bindValue(":ns", NomSponsor);
    qrt->bindValue(":sm", Somme);
    qrt->bindValue(":d", Duree);
    qrt->bindValue(":s", Statut);
    qrt->bindValue(":dd", DateDebut);
    qrt->bindValue(":df", DateFin);

    qrt->exec();
    return true;
}

bool Sponsor::validerSponsor()
{
    
    QSqlQuery *qrt = new QSqlQuery();

    if(!(qrt->prepare("UPDATE Sponsors SET Statut = :s WHERE IdSponsor = :i"))) return false;
    qrt->bindValue(":s", true);
    qrt->bindValue(":i", IdSponsor);
    qrt->exec();

    /************UPDATE Montant Revenus********/
    QSqlQuery *qrtRev = new QSqlQuery ();
    if(!(qrtRev->prepare("update Budgets set MontantRevenus = MontantRevenus + (select Somme from Sponsors where IdSponsor = :id)"))) return false;
    qrtRev->bindValue(":id", IdSponsor);
    qrtRev->exec();


    return true;
}

bool Sponsor::afficherSponsor()
{
    
    QSqlQuery *qrt = new QSqlQuery();
    qrt->prepare("select * from Sponsors where IdSponsor = ?");
    qrt->addBindValue(IdSponsor);
    if(qrt->exec()){
        while (qrt->next()) {

            NomSponsor = (qrt->value(1).toString());
            Somme = (qrt->value(2).toDouble());
            Duree = (qrt->value(3).toInt());
            Statut = (qrt->value(5).toBool());
            DateDebut = (qrt->value(6).toString());
            DateFin = (qrt->value(7).toString());

            C.FermerConnexionBD();
            return true;
        }

    }
    return false;
}

bool Sponsor::verifierExistenceSponsor()
{
    
    QSqlQuery *qrt = new QSqlQuery ();
    qrt->prepare("select * from Sponsors WHERE IdSponsor = :i");
    qrt->bindValue(":i", IdSponsor);
    if (qrt->exec())
    {
        if(qrt->next())
        return true;
    }

     else return false;
    return false;
}

QSqlQueryModel * Sponsor::afficherHistoriqueSponsor()
{
    

    QSqlQuery* qrt=new QSqlQuery();
    QSqlQueryModel *model=new QSqlQueryModel;

    qrt->prepare("select * from Sponsors");
    qrt->exec();


    model->setQuery(*qrt);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id Sponsor"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Sponsor"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Somme Emis"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Durée du contrat"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Statut"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date de début"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Date de fin"));

return model;
}

QSqlQueryModel * Sponsor::afficherSponsorNV()
{
    

    QSqlQuery* qrt=new QSqlQuery();
    QSqlQueryModel *model=new QSqlQueryModel;

    qrt->prepare("select * from Sponsors where Statut = :s");
    qrt->bindValue(":s", false);
    qrt->exec();


    model->setQuery(*qrt);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id Sponsor"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Sponsor"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Somme Emis"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Durée du contrat"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Statut"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date de début"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Date de fin"));

return model;
}

void Sponsor::calculerDuree()
{
    QDateTime dated (QDate( DateDebut.mid(6,4).toInt(), DateDebut.mid(3,2).toInt(), DateDebut.mid(0,2).toInt()));
    QDateTime datef (QDate (DateFin.mid(6,4).toInt(), DateFin.mid(3,2).toInt(), DateFin.mid(0,2).toInt())) ;
    Duree = dated.daysTo(datef);
}
