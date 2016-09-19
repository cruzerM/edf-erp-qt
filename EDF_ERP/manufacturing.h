#ifndef MANUFACTURING_H
#define MANUFACTURING_H

#include <QMainWindow>
#include "fmp.h"
#include "connexion.h"
#include "fproduction.h"
#include "freparation.h"
#include "femployes.h"
#include "fsites.h"
#include "fcontrol.h"
#include "messages.h"
#include "mail.h"

namespace Ui {
class Manufacturing;
}

class Manufacturing : public QMainWindow
{
    Q_OBJECT

public:
    explicit Manufacturing(QWidget *parent = 0);
    explicit Manufacturing(QWidget *parent, Connexion& C);
    ~Manufacturing();

private slots:
    void on_but_gestion_emp_clicked();

    void on_but_envoyer_clicked();

    void on_but_gestion_sites_clicked();

    void on_but_gestion_MP_clicked();

    void on_but_gestion_prod_clicked();

    void on_but_control_clicked();

    void on_but_repair_clicked();

    void on_quitter_but_clicked();

    bool setEtat();

    QString nombreMessages();

    bool raf_auto();


    void on_actionEnvoyer_un_Message_triggered();

    void on_actionEnvoyer_un_Mail_triggered();

private:
    Ui::Manufacturing *ui;
    Connexion Conn;
    Messagerie *M;
    Mail *mail;

};

#endif // MANUFACTURING_H
