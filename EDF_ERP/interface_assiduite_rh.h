#ifndef INTERFACE_ASSIDUITE_RH_H
#define INTERFACE_ASSIDUITE_RH_H

#include <QMainWindow>
#include <QApplication>
#include <QWindow>
#include <QString>
#include <QSpinBox>
#include <QMessageBox>
#include <QDoubleSpinBox>
#include <QComboBox>
#include "assiduites.h"
#include "employes.h"
namespace Ui {
class Interface_Assiduite_RH;
}

class Interface_Assiduite_RH : public QMainWindow
{
    Q_OBJECT

public:
    explicit Interface_Assiduite_RH(QWidget *parent = 0);
    ~Interface_Assiduite_RH();
private slots:
    void on_pushButton_assiduite_verifier_clicked();
    void on_pushButton_assiduite_ajouter_clicked();
    void on_pushButton_assiduit_modifier_clicked();
    void on_pushButton_assiduite_supp_clicked();

    void on_pushButton_assiduite_actualiser_clicked();
private:
    Ui::Interface_Assiduite_RH *ui;
    Assiduite A;
    Employe E;
};

#endif // INTERFACE_ASSIDUITE_RH_H
