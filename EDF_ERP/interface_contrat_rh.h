#ifndef INTERFACE_CONTRAT_RH_H
#define INTERFACE_CONTRAT_RH_H

#include <QMainWindow>
#include <QApplication>
#include <QWindow>
#include <QString>
#include <QSpinBox>
#include <QMessageBox>
#include <QDoubleSpinBox>
#include "contrats.h"
#include "employes.h"
namespace Ui {
class Interface_Contrat_RH;
}

class Interface_Contrat_RH : public QMainWindow
{
    Q_OBJECT

public:
    explicit Interface_Contrat_RH(QWidget *parent = 0);
    ~Interface_Contrat_RH();
private slots:
    void on_pushButton_contrat_verifier_clicked();
    void on_pushButton_contrat_ajouter_clicked();
    void on_pushButton_contrat_modifier_clicked();
    void on_pushButton_contrat_supprimer_clicked();
    void on_pushButton_contrat_afficher_clicked();
private:
    Ui::Interface_Contrat_RH *ui;
    Contrat C;
    Employe E;
};

#endif // INTERFACE_CONTRAT_RH_H
