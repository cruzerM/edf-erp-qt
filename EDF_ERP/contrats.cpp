#include "contrats.h"


Contrat::Contrat()
{
    IdContrat = 0;
    IdEmploye = 0;
    date_debut = "";
    date_fin="";
    duree_contrat=0;
    montant=0;
    indemnite=0;
    type_rupture="";
    type_contrat="";
    etat_contrat=true;
    statut=false;
}

void Contrat::ajouter()
{
    
    QSqlQuery query;
        if((query.prepare( "INSERT INTO CONTRATS (IdContrat,IdEmploye,DateDebut,DateFin,Duree,TypeContrat,Montant,TypeRupture,Indemnite,Etat,Statut) VALUES (?,?,\'"+this->date_debut+"\',\'"+this->date_fin+"\',?,\'"+this->type_contrat+"\',?,\'"+this->type_rupture+"\',?,?,?)")))

             {
            query.addBindValue(this->IdContrat);
            query.addBindValue(this->IdEmploye);
            query.addBindValue(this->duree_contrat);
            query.addBindValue(this->montant);
            query.addBindValue(this->indemnite);
            query.addBindValue(this->etat_contrat);
            query.addBindValue(this->statut);
            query.exec();
            qDebug() << "Ajout reussie";
             }
        else {qDebug() << "Ajout non reussie ???????";}
}

QSqlQueryModel *  Contrat::afficher()
{
    
    QSqlQuery* qrt=new QSqlQuery();
    QSqlQueryModel *model=new QSqlQueryModel();
    qrt->prepare("select IdContrat,IdEmploye,DateDebut,DateFin,Duree,TypeContrat,Montant,TypeRupture,Indemnite,Etat,Statut from CONTRATS");
    qrt->exec();
    model->setQuery(*qrt);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IdContrat"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("IdEmploye"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DateDebut"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DateFin"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Duree"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("TypeContrat"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Montant"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("TypeRupture"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Indemnite"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("Etat"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("Statut"));
return model;
}

void Contrat::modifier()
{
  
        QSqlQuery query;
        if((query.prepare( "UPDATE CONTRATS SET IdEmploye=?,DateDebut=?,DateFin=?,Duree=?,TypeContrat=?,Montant=?,TypeRupture=?,Indemnite=?,Etat=?,Statut=? WHERE IdContrat=?")))

             {
              query.addBindValue(this->IdEmploye);
              query.addBindValue(this->date_debut);
              query.addBindValue(this->date_fin);
              query.addBindValue(this->duree_contrat);
              query.addBindValue(this->type_contrat);
              query.addBindValue(this->montant);
              query.addBindValue(this->type_rupture);
              query.addBindValue(this->indemnite);
              query.addBindValue(this->etat_contrat);
              query.addBindValue(this->statut);
              query.addBindValue(this->IdContrat);
              query.exec();
            qDebug() << "Modifie";
             }
        else {qDebug() << "non modifier ???????";}
}

void Contrat::supprimer()
{
        
        QSqlQuery query;
         if((query.prepare( "DELETE FROM CONTRATS WHERE IdContrat=?")))
         {
            query.addBindValue(this->IdContrat);
             query.exec();
            qDebug() << "Supprimer";
         }
         else {qDebug() << "non supprimer ???????";}
}

bool Contrat::verifier_id()
{
    
    QSqlQuery query;

         if((query.prepare("SELECT IdEmploye,DateDebut,DateFin,Duree,TypeContrat,Montant,TypeRupture,Indemnite,Etat,Statut FROM CONTRATS WHERE IdContrat=?")))
              {
             query.addBindValue(this->IdContrat);
              query.exec();
              if(query.next())
              {
                  setidEmploye(query.value(0).toInt());
                  setdate_debut(query.value(1).toString());
                  setdate_fin(query.value(2).toString());
                  setduree_contrat(query.value(3).toInt());
                  settype_contrat(query.value(4).toString());
                  setmontant(query.value(5).toDouble());
                  settype_rupture(query.value(6).toString());
                  setindemnite(query.value(7).toDouble());
                  setetat_contrat(query.value(8).toBool());
                  setstatut(query.value(9).toBool());
                  return true;
              }else{return false;}

              }
return false;
}
////////////////////////////get & set///////////////////////////////////////////////////

int Contrat::getidEmploye()
{
return IdEmploye;
}

void Contrat::setidEmploye(int IdEmploye)
{
this->IdEmploye=IdEmploye;
}
int Contrat::getidContrat()
{
return IdContrat;
}

void Contrat::setidContrat(int IdContrat)
{
this->IdContrat=IdContrat;
}
int Contrat::getduree_contrat()
{
return duree_contrat;
}

void Contrat::setduree_contrat(int duree_contrat)
{
this->duree_contrat=duree_contrat;
}
QString Contrat::getdate_debut()
{
return date_debut;
}

void Contrat::setdate_debut(QString date_debut)
{
this->date_debut=date_debut;
}
QString Contrat::getdate_fin()
{
return date_fin;
}

void Contrat::setdate_fin(QString date_fin)
{
this->date_fin=date_fin;
}

QString Contrat::gettype_rupture()
{
return type_rupture;
}

void Contrat::settype_rupture(QString type_rupture)
{
this->type_rupture=type_rupture;
}

QString Contrat::gettype_contrat()
{
return type_contrat;
}

void Contrat::settype_contrat(QString type_contrat)
{
this->type_contrat=type_contrat;
}

double Contrat::getmontant()
{
return montant;
}

void Contrat::setmontant(double montant)
{
this->montant=montant;
}
double Contrat::getindemnite()
{
return indemnite;
}

void Contrat::setindemnite(double indemnite)
{
this->indemnite=indemnite;
}
bool Contrat::getetat_contrat()
{
return etat_contrat;
}

void Contrat::setetat_contrat(bool etat_contrat)
{
this->etat_contrat=etat_contrat;
}

bool Contrat::getstatut()
{
return statut;
}

void Contrat::setstatut(bool statut)
{
this->statut=statut;
}
/////////////////////////////////////////////////////////////////////////////////////////////////


bool Contrat::validerContrat()
{
    
    QSqlQuery *qrtUpdate = new QSqlQuery();

    if(!(qrtUpdate->prepare("UPDATE Contrats SET Statut = :s WHERE (IdContrat = :i and TypeRupture = '' and Etat = :e) "))) return false;
    qrtUpdate->bindValue(":s", true);
    qrtUpdate->bindValue(":i", IdContrat);
    qrtUpdate->bindValue(":e", true);
    if(!qrtUpdate->exec()) return false;

    /************UPDATE Montant Depenses********/
    QSqlQuery *qrtDep = new QSqlQuery ();
    if(!(qrtDep->prepare("update Budgets set MontantDepenses = MontantDepenses + (select Montant from Contrats where IdContrat = :id)"))) return false;
    qrtDep->bindValue(":id", IdContrat);
    qrtDep->exec();


    return true;


}

bool Contrat::payerIndemnite()
{
    
    QSqlQuery *qrtUpdate = new QSqlQuery();

    if(!(qrtUpdate->prepare("UPDATE Contrats SET Statut = :s WHERE (IdContrat = :i and TypeRupture != :t and Etat = :e) "))) return false;
    qrtUpdate->bindValue(":s", true);
    qrtUpdate->bindValue(":i", IdContrat);
    qrtUpdate->bindValue(":t", "");
    qrtUpdate->bindValue(":e", false);
    if(!qrtUpdate->exec()) return false;

    /************UPDATE Montant Depenses********/
    QSqlQuery *qrtDep = new QSqlQuery ();
    if(!(qrtDep->prepare("update Budgets set MontantDepenses = MontantDepenses + (select Indemnite from Contrats where IdContrat = :id)"))) return false;
    qrtDep->bindValue(":id", IdContrat);
    qrtDep->exec();


    return true;

}

QSqlQueryModel * Contrat::afficherContratsNV()
{
    

    QSqlQuery* qrt=new QSqlQuery();
    QSqlQueryModel *model=new QSqlQueryModel;

    qrt->prepare("select IdContrat, IdEmploye, Montant, Indemnite, Etat, Statut from Contrats where Statut = :s");
    qrt->bindValue(":s", false);
    qrt->exec();


    model->setQuery(*qrt);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id Contrat"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Id Employe"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Montant"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("indemnite"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Statut"));

return model;

}

