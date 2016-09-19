#ifndef ASSIDUITES_H
#define ASSIDUITES_H

#include <QString>
#include <QMessageBox>
#include <QSqlQueryModel>
#include "connexion.h"
#include <QSqlQuery>

class Assiduite {

public:

    Assiduite();
    ~Assiduite() {}
    void ajouter();
    QSqlQueryModel * afficher();
    void modifier();
    void supprimer();
    bool verifier_id();
    int getidAssiduite();
    void setidAssiduite(int);
    int getidEmploye();
    void setidEmploye(int);
    int getabsence();
    void setabsence(int);
    int getretard();
    void setretard(int);
    int getheure_supplementaire();
    void setheure_supplementaire(int);
    QString getdate_depart();
    void setdate_depart(QString);
    QString getdate_reprise();
    void setdate_reprise(QString);
    QString gettype();
    void settype(QString);
    QString getperiode();
    void setperiode(QString);
    bool getdisponibilite();
    void setdisponibilite(bool);

    Connexion C;

private:

    int IdAssiduite;
    int IdEmploye;
    QString date_depart;
    QString date_reprise;
    QString type;
    int absence;
    int retard;
    int heure_supplementaire;
    QString periode;
    bool disponibilite;
};


#endif // ASSIDUITES_H
