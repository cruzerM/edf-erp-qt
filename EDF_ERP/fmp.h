#ifndef FMP_H
#define FMP_H

#include <QDialog>
#include <QSqlQueryModel>
#include "connexion.h"
#include "matierep.h"

namespace Ui {
class Fmp;
}

class Fmp : public QDialog
{
    Q_OBJECT

public:
    explicit Fmp(QWidget *parent = 0);
    ~Fmp();

private slots:
    void on_identMP_cursorPositionChanged();

    void on_but_ajouter_clicked();

    void on_but_refresh_clicked();

private:
    Ui::Fmp *ui;
    Connexion *C;
    MatiereP *MP;
};

#endif // FMP_H
