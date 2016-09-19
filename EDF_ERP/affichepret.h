#ifndef AFFICHEPRET_H
#define AFFICHEPRET_H

#include <QDialog>
#include <QString>
//#include <QPalette>
#include <QTextEdit>

#include "prets.h"


namespace Ui {
class AffichePret;
}

class AffichePret : public QDialog
{
    Q_OBJECT

public:
    AffichePret (QWidget *parent, Pret &, bool, int privilege);
    ~AffichePret();

private slots:
    void on_EnregistrerPret_clicked();

private:
    Ui::AffichePret *ui;
    Pret P;
};

#endif // AFFICHEPRET_H
