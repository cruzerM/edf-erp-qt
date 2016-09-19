#include "connexion.h"
#include <QSqlDatabase>
#include <QFileInfo>
#include <QSqlQuery>
#include <QMessageBox>

Connexion::Connexion()
{
    username = "";
    password = "";
    privilege = 0;
}

Connexion::Connexion(QString login, QString mdp)
{
    username = login;
    password = mdp;
}

QString Connexion::getLogin()
{
    return username;
}

void Connexion::setLogin(QString L)
{
    username=L;
}

QString Connexion::getMdp()
{
    return password;
}

void Connexion::setMdp(QString Pwd)
{
    password=Pwd;
}

bool Connexion::ConnectionBD()
{
    QString Path = QDir::currentPath() + "/../database/EDF_ERP_DB.sqlite";

    DB = QSqlDatabase::addDatabase("QSQLITE");

    DB.setDatabaseName(Path);

    QFileInfo checkFile(Path);

   if(checkFile.isReadable())
   {
        if (DB.open())
        {
            return true;
        }
    else
        {
            return false;
        }
    }
   return false;
}

void Connexion::FermerConnexionBD()
{
    DB.close();
}

QString Connexion::ConnBD(QString login, QString mdp)
{
    if (!ConnectionBD())
    {
        qDebug() << "Pas de connexion avec la BD!";
    }

    QSqlQuery qry, quer_nbre;
    if (qry.exec("SELECT login, password, privilege FROM UTILISATEURS WHERE login =\'" + login + "\'AND password =\'" + mdp + "\' and Etat !=1;"))
    {
        quer_nbre.prepare("UPDATE UTILISATEURS set Etat = 1 where login = '"+ login +"';");

        if(qry.next() && quer_nbre.exec())
        {
        QString dept = qry.value("password").toString().mid(0,2);
        int priv = qry.value("privilege").toInt();
        privilege = priv;

            if(dept == "PR")
            {
                if (priv == 1)
                {
                    return dept + QString::number(priv);
                }
                else if (priv == 2)
                {
                    return dept + QString::number(priv);
                }
                else
                {
                    return dept + QString::number(priv);
                }
            }

            else if (dept == "RH")
            {
                return dept ;
            }
            else if (dept == "FI")
            {
                if (priv == 1)
                {
                    return dept + QString::number(priv);
                }

                else
                {
                    return dept + QString::number(priv);
                }
            }
        }
        else
            return "";

    }
    return "";
}

void Connexion::initUsers(QString user)
{
    //ConnectionBD();

    QSqlQuery query_upd ("UPDATE UTILISATEURS set Etat = 0 where (login='"+ user + "');");
    query_upd.exec();
}

QSqlQuery Connexion::compterUsers()
{
    QSqlQuery query("select count(Etat) as Nombre from UTILISATEURS where Etat=1;");

    if (query.exec())
    {
        if(query.next())
        {
        return query;
        }
    }
    return query;
}
