#ifndef EMPLOYES_H
#define EMPLOYES_H

#include <QString>
#include <QMessageBox>
#include <QSqlQueryModel>
#include "connexion.h"
#include <QSqlQuery>

class Employe {

public:

    Employe();
    ~Employe() {}
    void ajouter();
    QSqlQueryModel * afficher();
    void modifier();
    void supprimer();
    bool verifier_id();
    int getidEmploye();
    void setidEmploye(int);
    QString getnom();
    void setnom(QString);
    QString getprenom();
    void setprenom(QString);
    QString getCIN();
    void setCIN(QString);
    QString getadresse();
    void setadresse(QString);
    int gettelephone();
    void settelephone(int);
    int getage();
    void setage(int);
    QString getdiplome();
    void setdiplome(QString);
    QString getcause_sortie();
    void setcause_sortie(QString);
    QString getdepartement();
    void setdepartement(QString);
    QString getposte();
    void setposte(QString);
    QString getgrade();
    void setgrade(QString);
    QString getemail();
    void setemail(QString);
    bool getetat_employe();
    void setetat_employe(bool);
    QString getlogin();
    void setlogin(QString);
    QString getmdp();
    void setmdp(QString);
    int getprivilege();
    void setprivilege(int);

    QSqlQueryModel* extraireListeEmp();
    bool testExistanceEmp(QString);

    QSqlQueryModel* extraireListePostes();
    QSqlQueryModel* extraireListeGrades();
    QSqlQueryModel* extraireDispo();

    Connexion C;

private:

    int IdEmploye;
    QString nom;
    QString prenom;
    QString CIN;
    QString adresse;
    int telephone;
    int age;
    QString diplome;
    QString cause_sortie;
    QString departement;
    QString poste;
    QString grade;
    QString email;
    bool etat_employe;
    QString login;
    QString mdp;
    int privilege;
};

#endif // EMPLOYES_H
