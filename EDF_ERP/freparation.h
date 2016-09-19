#ifndef FREPARATION_H
#define FREPARATION_H

#include <QDialog>
#include <QSqlQueryModel>
#include <QMessageBox>
#include "produit.h"
#include "reparation.h"

namespace Ui {
class Freparation;
}

class Freparation : public QDialog
{
    Q_OBJECT

public:
    explicit Freparation(QWidget *parent = 0);
    ~Freparation();

private slots:
    void on_id_repair_text_cursorPositionChanged();

    void on_confirm_but_clicked();

private:
    Ui::Freparation *ui;
    Produit P;
    Reparation *R;
};

#endif // FREPARATION_H
