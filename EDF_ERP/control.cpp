#include "control.h"

Control::Control()
{
    Identifiant = 0;
    Qualite = "";
    Echeances = "";
    Type = "";
}

Control::Control(int id, QString qual, QString ech, QString type)
{
    Identifiant = id;
    Qualite = qual;
    Echeances = ech;
    Type = type;
}

int Control::getIdentifiant()
{
    return Identifiant;
}
void Control::setIdentifiant(int id)
{
    Identifiant=id;
}

QString Control::getQualite()
{
    return Qualite;
}
void Control::setQualite(QString qual)
{
    Qualite=qual;
}

QString Control::getEcheances()
{
    return Echeances;
}
void Control::setEcheances(QString ech)
{
    Echeances=ech;
}

QString Control::getType()
{
    return Type;
}
void Control::setType(QString type)
{
    Type=type;
}

bool Control::addControlCycle()
{
    Connexion C;

    //if (C.ConnectionBD())
    //{
        QSqlQuery query_ajout;
        if(query_ajout.exec("INSERT INTO Controls (IdControl, Qualite, Echeances, Type) VALUES ("+ QString::number(Identifiant) +",'"+ Qualite +"','" + Echeances +"','"+ Type +"');"))
        {
            qDebug() << "Ajout effectué!";
            return true;
        }
        else return false;
    //}
    return false;
}

bool Control::controlExistance(int id)
{
    
    QSqlQuery query;

    query.prepare("SELECT * from Controls where IdControl=("+ QString::number(id) + ");");

    if (query.exec())
    {
        if (query.next())
        {
            return true;
        }
    }
    return false;
}
