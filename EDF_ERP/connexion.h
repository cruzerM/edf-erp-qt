#ifndef CONNEXION_H
#define CONNEXION_H
#include <QString>
#include <QDebug>
#include <QSqlDatabase>
#include <QSql>
#include <QSqlQueryModel>
#include <QDir>


class Connexion
{
    QString username;
    QString password;
    int privilege;

public:
    QSqlDatabase DB;
    Connexion();
    Connexion(QString, QString);

    QString getLogin();
    void setLogin(QString);

    QString getMdp();
    void setMdp(QString);

    int getPrivilege() {return privilege;}
    void setPrivilege(int priv) {privilege = priv;}

    bool ConnectionBD();
    void FermerConnexionBD();
    QString ConnBD(QString, QString);
    void initUsers(QString);
    QSqlQuery compterUsers();
};

#endif // CONNEXION_H
