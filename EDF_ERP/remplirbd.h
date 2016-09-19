#ifndef REMPLIRBD_H
#define REMPLIRBD_H

#include <QDialog>
#include <QObject>
#include <Qdate>
#include <QMessageBox>
#include <QtMultimedia/QSound>

#include "prets.h"
#include "sponsor.h"
#include "actionnaire.h"
#include "affichepret.h"
#include "affichesponsor.h"
#include "afficheactionnaire.h"
#include "connexion.h"
//#include "sound.h"

namespace Ui {
class RemplirBD;
}

class RemplirBD : public QDialog
{
    Q_OBJECT

public:
    explicit RemplirBD(QWidget *parent, int privilege);
    void ajoutPret();
    void remplirTabPret();
    void ajoutSponsor();
    void remplirTabSponsor();
    void ajoutActionnaire();
    void remplirTabActionnaire();
    ~RemplirBD();

private slots:


    void on_CheckValiderPret_clicked(bool checked);

    void on_enregistrerPret_clicked();

    void on_VidPret_clicked();

    void on_ApercuPret_clicked();

    void on_RefreshPret_clicked();

    void on_tabPretsAjout_doubleClicked(const QModelIndex &index);

    void on_lineIDPret_cursorPositionChanged();

    void on_enregistrerSponsor_clicked();

    void on_ApercuSponsor_clicked();

    void on_RefreshSponsor_clicked();

    void on_CheckValiderSponsor_clicked(bool checked);

    void on_VidSponsor_clicked();

    void on_lineIDSponsor_cursorPositionChanged();

    void on_CheckValiderActionnaire_clicked(bool checked);

    void on_ApercuActionnaire_clicked();

    void on_RefreshActionnaire_clicked();

    void on_VidActionnaire_clicked();

    void on_enregistrerActionnaire_clicked();

    void on_lineIDActionnaire_cursorPositionChanged();

    void on_tabActionnairesAjout_doubleClicked(const QModelIndex &index);

    void on_tabSponsorsAjout_doubleClicked(const QModelIndex &index);

private:
    Ui::RemplirBD *ui;
    AffichePret *AP;
    AfficheSponsor *AS;
    AfficheActionnaire *AA;
    Pret P;
    Sponsor S;
    Actionnaire A;
    Connexion C;
    //Sound sound;
};

#endif // REMPLIRBD_H
