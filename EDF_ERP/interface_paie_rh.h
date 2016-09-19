#ifndef INTERFACE_PAIE_RH_H
#define INTERFACE_PAIE_RH_H

#include <QMainWindow>
#include <QApplication>
#include <QWindow>
#include <QString>
#include <QSpinBox>
#include <QMessageBox>
#include <QDoubleSpinBox>
#include "paie.h"
#include "employes.h"
namespace Ui {
class Interface_Paie_RH;
}

class Interface_Paie_RH : public QMainWindow
{
    Q_OBJECT

public:
    explicit Interface_Paie_RH(QWidget *parent = 0);
    ~Interface_Paie_RH();
private slots:
    void on_pushButton_bull_verifier_clicked();
    void on_pushButton_bull_ajouter_clicked();
    void on_pushButton_bull_modifier_clicked();
    void on_pushButton_bull_supp_clicked();
  void on_pushButton_paie_actualiser_clicked();


private:
    Ui::Interface_Paie_RH *ui;
    Paie P;
    Employe E;
};

#endif // INTERFACE_PAIE_RH_H
