#include "responsable.h"
#include <QString>

Responsable::Responsable()
{
    IdEmploye = 0;
    Poste = "";
    Grade = "";
    Disponibilite = "";
    Date_Debut = "";
    Date_Fin = "";
    Duree_Travail = 0;
    IdCommande = 0;
}

Responsable::Responsable(int idE, QString poste, QString grade, QString datedeb, QString datefin, QString dispo, long duree, int idC)
{
    IdEmploye = idE;
    Poste = poste;
    Grade = grade;
    Disponibilite = dispo;
    Date_Debut = datedeb;
    Date_Fin = datefin;
    Duree_Travail = duree;
    IdCommande=idC;
}

bool Responsable::ajouterAffectation()
{
    
    QSqlQuery *query_ajout = new QSqlQuery();

    query_ajout->prepare("UPDATE Employes set Duree =" + QString::number(calculDuree(Date_Debut, Date_Fin)) + ", Disponibilite = '" + Disponibilite + "', IdDevis = " + QString::number(IdCommande) + ", DateDebut = '" + Date_Debut + "', DateFin = '"+ Date_Fin + "' where IdEmploye = " + QString::number(IdEmploye) + ";");
    if (query_ajout->exec())
    {
        return true;
    }
    else
        return false;

return false;
}

QSqlQueryModel* Responsable::extractResponsable()
{
    

    QSqlQueryModel *modal_resp = new QSqlQueryModel();
    QSqlQuery *query_resp = new QSqlQuery();
    query_resp->prepare("SELECT DISTINCT IdEmploye from Employes where Grade = 'Ouvrier'");
    query_resp-> exec();
    modal_resp->setQuery(*query_resp);

    return modal_resp;
}


QSqlRecord Responsable::chercherAffectation(int id)
{
    

    QSqlQuery query;
    query.prepare("SELECT IdEmploye, DateDebut, DateFin, Disponibilite, Poste, Grade, IdDevis from Employes where IdEmploye = " + QString::number(id) + ";");
    if (query.exec())
    {
        if (query.next())
        {
             return query.record();
        }

    }
    return query.record();
}

bool Responsable::modifierAffectation()
{
    if(ajouterAffectation())
    {
        return true;
    }
    else
        return false;

return false;
}

bool Responsable::supprimerAffectation(int id)
{
    

    QSqlQuery *query = new QSqlQuery(C.DB);
    query->prepare("UPDATE EMPLOYES set IdDevis = 0 where IdEmploye = " + QString::number(id) + ";");
    if (query->exec())
    {
        return true;
    }
    else
        return false;

return false;
}

long Responsable::calculDuree(QString DateD, QString DateF)
{
    int dd = DateD.mid(0,2).toInt();
    int md = DateD.mid(3,2).toInt();
    int ad = DateD.mid(6,4).toInt();
    int df = DateF.mid(0,2).toInt();
    int mf = DateF.mid(3,2).toInt();
    int af = DateF.mid(6,4).toInt();

    QDateTime dateDeb (QDate(ad, md, dd));
    QDateTime dateFin (QDate(af, mf, df));

    return dateDeb.daysTo(dateFin);
}
