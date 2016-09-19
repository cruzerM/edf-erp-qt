#include "messagerie.h"

Messagerie::Messagerie()
{
    Destinataire = "";
    Expediteur = "";
    Message = "";
    Date = "";
    Etat = 0;
}

Messagerie::Messagerie(QString d, QString s, QString m, QString date, int e)
{
    Destinataire = d;
    Expediteur = s;
    Message = m;
    Date = date;
    Etat = e;
}

bool Messagerie::envoyerMessage()
{
    
    QSqlQuery query;
    query.prepare("INSERT INTO Messages (Destinataire, Expediteur, Msg, Etat) Values ('" + Destinataire + "','" + Expediteur + "','"+ Message +"',"+ QString::number(1)+");");
    if (query.exec())
    {
        return true;
    }
    else
    {
        return false;
    }

    return false;
}

QSqlQuery Messagerie::recevoirMessage(QString exp)
{
    
    QSqlQuery query_reception("SELECT Expediteur, Date, Msg from Messages where Etat=1 and Destinataire = '"+ exp + "';");
    if (query_reception.exec())
    {
        if (query_reception.next())
        {
            return query_reception;
        }
    }
    return query_reception;
}

QSqlQueryModel* Messagerie::refreshComboDest()
{
    
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();

    query->prepare("SELECT login from UTILISATEURS;");
    query->exec();

    modal->setQuery(*query);

    return modal;
}

bool Messagerie::lireMessage(QString exp, QString mes)
{
    QSqlQuery query_update("delete from Messages where Expediteur = '" + exp + "' and Msg = '" + mes + "';");
    if(query_update.exec())
    {
        return true;
    }
    else
    {
        return false;
    }
return false;
}

QSqlQuery Messagerie::nombreMes(QString exp)
{
    
    QSqlQuery query("select count(Etat) as Nombre from Messages where Etat=1 and Destinataire == '"+ exp + "';");

    if (query.exec())
    {
        if(query.next())
        {
            return query;
        }
    }
    return query;
}
