#ifndef RESPONSABLE_H
#define RESPONSABLE_H
#include "connexion.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlQueryModel>
#include <QDateTime>

class Responsable
{
    int IdEmploye;
    QString Poste;
    QString Grade;
    QString Disponibilite;
    QString Date_Debut;
    QString Date_Fin;
    long Duree_Travail;
    int IdCommande;

public:
    Responsable();
    Responsable(int, QString, QString, QString, QString, QString, long, int);
    ~Responsable() {}

    void setIdEmploye(int IdE) {IdEmploye = IdE;}
    void setPoste(QString poste) {Poste = poste;}
    void setGrade(QString grade) {Grade = grade;}
    void setDisponibilite(QString dispo) {Disponibilite = dispo;}
    void setDuree(long duree) {Duree_Travail=duree;}
    void setDateDeb(QString datedeb) {Date_Debut = datedeb;}
    void setDateFin(QString datefin) {Date_Fin = datefin;}
    QString getDateDeb() {return Date_Debut;}
    QString getDateFin() {return Date_Fin;}
    void setIdCommande(int idC) {IdCommande=idC;}

    bool ajouterAffectation();
    QSqlRecord chercherAffectation(int);
    bool modifierAffectation();
    bool supprimerAffectation(int);
    QSqlQueryModel *extractResponsable();

    long calculDuree(QString, QString);

    Connexion C;
};

#endif // RESPONSABLE_H
