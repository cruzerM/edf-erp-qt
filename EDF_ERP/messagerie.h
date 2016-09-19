#ifndef MESSAGERIE_H
#define MESSAGERIE_H

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include "connexion.h"

class Messagerie
{
    QString Destinataire;
    QString Expediteur;
    QString Message;
    QString Date;
    int Etat;

public:
    Messagerie();
    Messagerie(QString, QString, QString, QString, int);
    ~Messagerie();

    void setDestinataire(QString dest) {Destinataire = dest;}
    QString getDestinataire () {return Destinataire;}

    void setExpediteur(QString exp) {Expediteur=exp;}
    QString getExpediteur() {return Expediteur;}

    void setMessage(QString mes) {Message = mes;}
    QString getMessage() {return Message;}

    void setEtat(int etat) {Etat=etat;}
    int getEtat() {return Etat;}

    QString getDate() {return Date;}

    bool envoyerMessage();
    bool lireMessage(QString, QString);
    QSqlQuery recevoirMessage(QString);
    QSqlQueryModel* refreshComboDest();
    QSqlQuery nombreMes(QString);



};

#endif // MESSAGERIE_H
