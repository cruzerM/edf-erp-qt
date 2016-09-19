#ifndef INTERFACE_MENU_RH_H
#define INTERFACE_MENU_RH_H

#include <QMainWindow>
#include <QApplication>
#include <QWindow>
#include <QString>
#include <QSpinBox>
#include <QMessageBox>
#include <QDoubleSpinBox>
#include "interface_employe_rh.h"
#include "interface_paie_rh.h"
#include "interface_contrat_rh.h"
#include "interface_assiduite_rh.h"
#include "messages.h"
#include "mail.h"


namespace Ui {
class Interface_menu_RH;
}

class Interface_menu_RH : public QMainWindow
{
    Q_OBJECT

public:
    explicit Interface_menu_RH(QWidget *parent = 0);
    ~Interface_menu_RH();

private slots:
    void on_pushButton_employe_clicked();
    void on_pushButton_assiduite_clicked();
    void on_pushButton_paie_clicked();
    void on_pushButton_contrat_clicked();

    void on_actionQuitter_triggered();
    void on_actionEnvoyer_un_message_triggered();

    void on_actionEnvoyer_un_email_triggered();

private:
    Ui::Interface_menu_RH *ui;
    Interface_Employe_RH *employe;
    Interface_Paie_RH *paie;
    Interface_Assiduite_RH *assiduite;
    Interface_Contrat_RH *contrat;

    Messages *M;
    Connexion *C;
    Mail *mail;
};

#endif // INTERFACE_MENU_RH_H
