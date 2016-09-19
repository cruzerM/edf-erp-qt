#include "assiduites.h"


Assiduite::Assiduite()
{
    IdAssiduite=0;
    IdEmploye=0;
    date_depart="";
    date_reprise="";
    type="";
    absence=0;
    retard=0;
    heure_supplementaire=0;
    periode="";
    disponibilite=true;
}

void Assiduite::ajouter()
{
    
    QSqlQuery query;
        if((query.prepare( "INSERT INTO ASSIDUITES (IdAssiduite,IdEmploye,Periode,DateDepart,DateReprise,Type,Absence,Retard,HeuresSupp,Disponibilite) VALUES (?,?,?,?,?,?,?,?,?,?);")))

             {
              query.addBindValue(this->IdAssiduite);
              query.addBindValue(this->IdEmploye);
              query.addBindValue(this->periode);
              query.addBindValue(this->date_depart);
              query.addBindValue(this->date_reprise);
              query.addBindValue(this->type);
              query.addBindValue(this->absence);
              query.addBindValue(this->retard);
              query.addBindValue(this->heure_supplementaire);
              query.addBindValue(this->disponibilite);
              query.exec();
            qDebug() << "Ajout reussie";
             }

        else {qDebug() << "Ajout non reussie ???????";}
}

QSqlQueryModel * Assiduite::afficher()
{
    
    QSqlQuery* qrt=new QSqlQuery();
    QSqlQueryModel *model=new QSqlQueryModel();
    qrt->prepare("select IdAssiduite,IdEmploye,Periode,DateDepart,DateReprise,Type,Absence,Retard,HeuresSupp,Disponibilite from ASSIDUITES");
    qrt->exec();
    model->setQuery(*qrt);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IdAssiduite"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("IdEmploye"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Periode"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DateDepart"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DateReprise"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Absence"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Retard"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("HeuresSupp"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("Disponibilite"));
     qDebug() << "Affichage reussie";
return model;
}

void Assiduite::modifier()
{
    
    QSqlQuery query;
        if((query.prepare( "UPDATE ASSIDUITES SET IdEmploye=?,Periode=?,DateDepart=?,DateReprise=?,Type=?,Absence=?,Retard=?,HeuresSupp=?,Disponibilite=? WHERE IdAssiduite=?")))

             {
              query.addBindValue(this->IdEmploye);
              query.addBindValue(this->periode);
              query.addBindValue(this->date_depart);
              query.addBindValue(this->date_reprise);
              query.addBindValue(this->type);
              query.addBindValue(this->absence);
              query.addBindValue(this->retard);
              query.addBindValue(this->heure_supplementaire);
              query.addBindValue(this->disponibilite);
              query.addBindValue(this->IdAssiduite);
              query.exec();
            qDebug() << "Modifie";
             }
        else {qDebug() << "non modifier ???????";}
}

void Assiduite::supprimer()
{
    
    QSqlQuery query;
        if((query.prepare( "DELETE FROM ASSIDUITES WHERE IdAssiduite=?")))
        {
           query.addBindValue(this->IdAssiduite);
            query.exec();
           qDebug() << "Supprimer";
        }
        else {qDebug() << "non supprimer ???????";}
}

bool Assiduite::verifier_id()
{
    
    QSqlQuery query;


         if((query.prepare("select IdAssiduite,IdEmploye,Periode,DateDepart,DateReprise,Type,Absence,Retard,HeuresSupp,Disponibilite from ASSIDUITES WHERE IdAssiduite=?")))
              {
             query.addBindValue(this->IdAssiduite);
              query.exec();
              if(query.next())
              {
                  setidEmploye(query.value(1).toInt());
                  setperiode(query.value(2).toString());
                  setdate_depart(query.value(3).toString());
                  setdate_reprise(query.value(4).toString());
                  settype(query.value(5).toString());
                  setabsence(query.value(6).toInt());
                  setretard(query.value(7).toInt());
                  setheure_supplementaire(query.value(8).toInt());
                  setdisponibilite(query.value(9).toBool());
                return true;
              }else{return false;}

              }
return false;
}

////////////////////////////get & set///////////////////////////////////////////////////

int Assiduite::getidAssiduite()
{
return IdAssiduite;
}

void Assiduite::setidAssiduite(int IdAssiduite)
{
this->IdAssiduite=IdAssiduite;
}
int Assiduite::getidEmploye()
{
return IdEmploye;
}
void Assiduite::setidEmploye(int IdEmploye)
{
this->IdEmploye=IdEmploye;
}
int Assiduite::getabsence()
{
return absence;
}
void Assiduite::setabsence(int absence)
{
this->absence=absence;
}
int Assiduite::getretard()
{
return retard;
}
void Assiduite::setretard(int retard)
{
this->retard=retard;
}
int Assiduite::getheure_supplementaire()
{
return heure_supplementaire;
}
void Assiduite::setheure_supplementaire(int heure_supplementaire)
{
this->heure_supplementaire=heure_supplementaire;
}
QString Assiduite::getdate_depart()
{
   return date_depart;
}

void Assiduite::setdate_depart(QString date_depart)
{
    this->date_depart=date_depart;
}
QString Assiduite::getdate_reprise()
{
   return date_reprise;
}

void Assiduite::setdate_reprise(QString date_reprise)
{
    this->date_reprise=date_reprise;
}
QString Assiduite::gettype()
{
   return type;
}

void Assiduite::settype(QString type)
{
    this->type=type;
}
QString Assiduite::getperiode()
{
   return periode;
}

void Assiduite::setperiode(QString periode)
{
    this->periode=periode;
}
bool Assiduite::getdisponibilite()
{
   return disponibilite;
}

void Assiduite::setdisponibilite(bool disponibilite)
{
    this->disponibilite=disponibilite;
}
