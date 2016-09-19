#ifndef MESSAGES_H
#define MESSAGES_H

#include <QDialog>
#include "connexion.h"
#include "messagerie.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>
#include <QMessageBox>
#include <QTimer>


namespace Ui {
class Messages;
}

class Messages : public QDialog
{
    Q_OBJECT

public:
    explicit Messages(QWidget *parent = 0);
    explicit Messages (QWidget *parent, QString);
    ~Messages();

private slots:
    void on_but_env_clicked();

    void on_but_lu_clicked();

    bool refresh_messages();

    void temps_reel();

    void on_but_quitter_clicked();

private:
    Ui::Messages *ui;
    Connexion C;
    Messagerie *M;
};

#endif // MESSAGES_H
