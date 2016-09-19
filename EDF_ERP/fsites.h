#ifndef FSITES_H
#define FSITES_H

#include <QDialog>
#include <QDebug>
#include "connexion.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "sites.h"

namespace Ui {
class Fsites;
}

class Fsites : public QDialog
{
    Q_OBJECT

public:
    explicit Fsites(QWidget *parent = 0);
    ~Fsites();

private slots:

    void on_ajouter_but_site_clicked();

    void on_refresh_but_site_clicked();

    void on_refresh_but_stock_clicked();

    void on_ajouter_but_stock_clicked();

private:
    Ui::Fsites *ui;
    Connexion C;
    Sites *S;
};

#endif // FSITES_H
