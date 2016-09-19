#ifndef FEMPLOYES_H
#define FEMPLOYES_H

#include <QDialog>
#include "responsable.h"
#include "employes.h"
#include "production.h"

namespace Ui {
class Femployes;
}

class Femployes : public QDialog
{
    Q_OBJECT

public:
    explicit Femployes(QWidget *parent = 0);
    ~Femployes();

private slots:
    void on_id_employe_text_cursorPositionChanged();

    void on_but_affecter_clicked();

    void on_but_modif_clicked();

    void on_but_delete_clicked();


private:
    Ui::Femployes *ui;
    Responsable R;
    Production P;
    Employe E;
};

#endif // FEMPLOYES_H
