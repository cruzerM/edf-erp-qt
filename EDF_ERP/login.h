#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QDebug>
#include <QSql>
#include <QSqlDatabase>
#include <QFileInfo>
#include "connexion.h"
#include "interface_menu_rh.h"
#include "valider.h"
#include "manufacturing.h"
#include "intro.h"
#include "sound.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();


public slots:
    void on_clear_button_clicked();
    void on_connect_clicked();

private slots:
    void on_exit_clicked();


private:
    Ui::Login *ui;
    Interface_menu_RH *MenuRH;
    Valider *Finances;
    Manufacturing *Production;

    Sound *Son;

    Connexion C;
};
#endif // LOGIN_H
