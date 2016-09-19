#ifndef INTERFACE_EMPLOYE_RH_H
#define INTERFACE_EMPLOYE_RH_H

#include <QMainWindow>
#include <QApplication>
#include <QWindow>
#include <QString>
#include <QSpinBox>
#include <QMessageBox>
#include <QDoubleSpinBox>
#include <QLineEdit>
#include <QComboBox>
#include "employes.h"
namespace Ui {
class Interface_Employe_RH;
}

class Interface_Employe_RH : public QMainWindow
{
    Q_OBJECT

public:
    explicit Interface_Employe_RH(QWidget *parent = 0);
    ~Interface_Employe_RH();
private slots:
void on_pushButton_emp_aj_clicked();
void on_pushButton_emp_mo_clicked();
void on_pushButton_emp_sup_clicked();
void on_pushButton_emp_verifier_clicked();
void on_pushButton_emp_aff_clicked();
void on_comboBox_grade_currentTextChanged(const QString &arg1);

private:
    Ui::Interface_Employe_RH *ui;
    Employe E;

};

#endif // INTERFACE_EMPLOYE_RH_H
