#include "employes.h"

Employe::Employe()
{
IdEmploye=0;
nom="";
prenom="";
CIN="";
adresse="";
telephone=0;
age=0;
diplome="";
cause_sortie="";
departement="";
poste="";
grade="";
email="";
login="";
mdp="";
privilege=0;
etat_employe=true;
}

void Employe::ajouter()
{

    QSqlQuery query;
    QSqlQuery qrt;
    login=nom+" "+prenom;
    if(poste=="Directeur RH" ||poste=="Directeur Production" )
    {
        privilege=3;
    }else if(poste=="Agent de production"||poste=="Directeur Financier")
    {
        privilege=2;
    }
    else if(poste=="Agent de stock"||poste=="Directeur Comptable")
        {
            privilege=1;
        }
    else
        {
            privilege=0;
        }
    mdp=departement.mid(0,2)+CIN;
        if((query.prepare( "INSERT INTO EMPLOYES (IdEmploye,Nom,Prenom,Adresse,Telephone,CIN,Age,Diplomes,CauseSortie,Departement,Poste,Grade,Email,EtatEmploye) VALUES (?,\'"+this->nom+"\',\'"+this->prenom+"\',\'"+this->adresse+"\',?,?,?,\'"+this->diplome+"\',\'"+this->cause_sortie+"\',\'"+this->departement+"\',\'"+this->poste+"\',\'"+this->grade+"\',\'"+this->email+"\',?)")))

             {
              query.addBindValue(this->IdEmploye);
              query.addBindValue(this->telephone);
              query.addBindValue(this->CIN);
              query.addBindValue(this->age);
              query.addBindValue(this->etat_employe);
              query.exec();
            qDebug() << "Ajout reussie";
             }
        else {qDebug() << "Ajout non reussie ???????";}
        if((qrt.prepare( "INSERT INTO UTILISATEURS (login,password,privilege,IdEmploye,Etat) VALUES (?,?,?,?,0)")))

             {
              qrt.addBindValue(this->login);
              qrt.addBindValue(this->mdp);
              qrt.addBindValue(this->privilege);
              qrt.addBindValue(this->IdEmploye);
              qrt.exec();
            qDebug() << "Ajout Acteur reussie";
             }
        else {qDebug() << "Ajout Acteur non reussie ???????";}
}

QSqlQueryModel * Employe::afficher()
{

    QSqlQuery* qrt=new QSqlQuery();
    QSqlQueryModel *model=new QSqlQueryModel();
    qrt->prepare("select IdEmploye,Nom,Prenom,Adresse,Telephone,CIN,Age,Diplomes,CauseSortie,Departement,Poste,Grade,Email,EtatEmploye from EMPLOYES");
    qrt->exec();
    model->setQuery(*qrt);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IdEmploye"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Telephone"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Age"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Diplomes"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("CauseSortie"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("Departement"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("Poste"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("Grade"));
    model->setHeaderData(12, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(13, Qt::Horizontal, QObject::tr("EtatEmploye"));
     qDebug() << "Affichage reussie";
return model;
}


void Employe::modifier()
{

    QSqlQuery query;
    QSqlQuery qrt;
    login=nom+" "+prenom;
    if(poste=="Directeur RH" ||poste=="Directeur Production" )
    {
        privilege=3;
    }else if(poste=="Agent de production"||poste=="Directeur financier")
    {
        privilege=2;
    }
    else if(poste=="Agent de stock"||poste=="Directeur comptable")
        {
            privilege=1;
        }
    else
        {
            privilege=0;
        }
    mdp=departement.mid(0,2)+CIN;
        if((query.prepare( "UPDATE EMPLOYES SET Nom=?,Prenom=?,Adresse=?,Telephone=?,CIN=?,Age=?,Diplomes=?,CauseSortie=?,Departement=?,Poste=?,Grade=?,Email=?,EtatEmploye=? WHERE IdEmploye=?")))

             {
              query.addBindValue(this->nom);
              query.addBindValue(this->prenom);
              query.addBindValue(this->adresse);
              query.addBindValue(this->telephone);
              query.addBindValue(this->CIN);
              query.addBindValue(this->age);
              query.addBindValue(this->diplome);
              query.addBindValue(this->cause_sortie);
              query.addBindValue(this->departement);
              query.addBindValue(this->poste);
              query.addBindValue(this->grade);
              query.addBindValue(this->email);
              query.addBindValue(this->etat_employe);
              query.addBindValue(this->IdEmploye);
              query.exec();
            qDebug() << "Modifie";
             }
        else {qDebug() << "non modifier ???????";}

        if((qrt.prepare( "UPDATE UTILISATEURS SET login=?,password=?,privilege=?,Etat=0 WHERE IdEmploye=?")))

             {
              qrt.addBindValue(this->login);
              qrt.addBindValue(this->mdp);
              qrt.addBindValue(this->privilege);
              qrt.addBindValue(this->IdEmploye);
              qrt.exec();
            qDebug() << "acteur Modifie";
             }
        else {qDebug() << "acteur non modifier ???????";}
}




void Employe::supprimer()
{

     QSqlQuery query;
     QSqlQuery qrt;
         if((query.prepare( "DELETE FROM EMPLOYES WHERE IdEmploye=?")))
         {
            query.addBindValue(this->IdEmploye);
             query.exec();
            qDebug() << "Supprimer";
         }
         else {qDebug() << "non supprimer ???????";}

         if((qrt.prepare( "DELETE FROM UTILISATEURS WHERE IdEmploye=?")))
         {
            qrt.addBindValue(this->IdEmploye);
             qrt.exec();
            qDebug() << "Acteur Supprimer";
         }
         else {qDebug() << "Acteur non supprimer ???????";}
}

bool Employe::verifier_id()
{

    QSqlQuery query;


         if((query.prepare("SELECT IdEmploye,Nom,Prenom,Adresse,Telephone,CIN,Age,Diplomes,CauseSortie,Departement,Poste,Grade,Email,EtatEmploye FROM EMPLOYES WHERE IdEmploye=?")))
              {
             query.addBindValue(this->IdEmploye);
              query.exec();
              if(query.next())
              {
                  setnom(query.value(1).toString());
                  setprenom(query.value(2).toString());
                  setadresse(query.value(3).toString());
                  settelephone(query.value(4).toInt());
                  setCIN(query.value(5).toString());
                  setage(query.value(6).toInt());
                  setdiplome(query.value(7).toString());
                  setcause_sortie(query.value(8).toString());
                  setdepartement(query.value(9).toString());
                  setposte(query.value(10).toString());
                  setgrade(query.value(11).toString());
                  setemail(query.value(12).toString());
                  setetat_employe(query.value(13).toBool());
                return true;
              }else{return false;}

              }
return false;
}
////////////////////////////get & set///////////////////////////////////////////////////
int Employe::getidEmploye()
{
return IdEmploye;
}

void Employe::setidEmploye(int IdEmploye)
{
this->IdEmploye=IdEmploye;
}

int Employe::getage()
{
return age;
}

void Employe::setage(int age)
{
this->age=age;
}

int Employe::gettelephone()
{
return telephone;
}

void Employe::settelephone(int telephone)
{
this->telephone=telephone;
}

QString Employe::getCIN()
{
return CIN;
}

void Employe::setCIN(QString CIN)
{
this->CIN=CIN;
}

QString Employe::getnom()
{
return nom;
}

void Employe::setnom(QString nom)
{
this->nom=nom;
}


QString Employe::getprenom()
{
return prenom;
}

void Employe::setprenom(QString prenom)
{
this->prenom=prenom;
}

QString Employe::getadresse()
{
return adresse;
}

void Employe::setadresse(QString adresse)
{
this->adresse=adresse;
}

QString Employe::getdiplome()
{
return diplome;
}

void Employe::setdiplome(QString diplome)
{
this->diplome=diplome;
}

QString Employe::getdepartement()
{
return departement;
}

void Employe::setdepartement(QString departement)
{
this->departement=departement;
}

QString Employe::getposte()
{
return poste;
}

void Employe::setposte(QString poste)
{
this->poste=poste;
}

QString Employe::getgrade()
{
return grade;
}

void Employe::setgrade(QString grade)
{
this->grade=grade;
}

QString Employe::getemail()
{
return email;
}

void Employe::setemail(QString email)
{
this->email=email;
}

QString Employe::getcause_sortie()
{
return cause_sortie;
}

void Employe::setcause_sortie(QString cause_sortie)
{
this->cause_sortie=cause_sortie;
}
bool Employe::getetat_employe()
{
return etat_employe;
}

void Employe::setetat_employe(bool etat_employe)
{
this->etat_employe=etat_employe;
}

QString Employe::getlogin()
{
return login;
}

void Employe::setlogin(QString login)
{
this->login=login;
}

QString Employe::getmdp()
{
return mdp;
}

void Employe::setmdp(QString mdp)
{
this->mdp=mdp;
}

int Employe::getprivilege()
{
return privilege;
}

void Employe::setprivilege(int privilege)
{
this->privilege=privilege;
}


QSqlQueryModel* Employe::extraireListeEmp()
{

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery(C.DB);

    query->prepare("SELECT IdEmploye from EMPLOYES ORDER BY IdEmploye ASC");
    query->exec();
    model->setQuery(*query);

    return model;
}

QSqlQueryModel* Employe::extraireListePostes()
{

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery(C.DB);

    query->prepare("SELECT DISTINCT Poste from EMPLOYES");
    query->exec();
    model->setQuery(*query);

    return model;
}

QSqlQueryModel* Employe::extraireListeGrades()
{

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery(C.DB);

    query->prepare("SELECT DISTINCT Grade from EMPLOYES");
    query->exec();
    model->setQuery(*query);

    return model;
}

QSqlQueryModel* Employe::extraireDispo()
{

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery(C.DB);

    query->prepare("SELECT DISTINCT Disponibilite from EMPLOYES");
    query->exec();
    model->setQuery(*query);

    return model;
}


bool Employe::testExistanceEmp(QString id)
{
    QSqlQuery query;
    query.prepare("select IdEmploye from Employes where IdEmploye = '" + id +"';");
    if (query.exec())
    {
        if (query.next())
        {
            return true;
        }
        else return false;
    }
return false;
}




