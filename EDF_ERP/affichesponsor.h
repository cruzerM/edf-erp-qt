#ifndef AFFICHESPONSOR_H
#define AFFICHESPONSOR_H

#include <QDialog>
#include <QString>
//#include <QPalette>
#include <QTextEdit>

#include "sponsor.h"

namespace Ui {
class AfficheSponsor;
}

class AfficheSponsor : public QDialog
{
    Q_OBJECT

public:
    AfficheSponsor(QWidget *parent, Sponsor&, bool, int privilege);
    ~AfficheSponsor();

private slots:
    void on_EnregistrerSponsor_clicked();

private:
    Ui::AfficheSponsor *ui;
    Sponsor S;
};

#endif // AFFICHESPONSOR_H
