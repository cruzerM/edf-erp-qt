#ifndef FCONTROL_H
#define FCONTROL_H

#include <QDialog>
#include "control.h"

namespace Ui {
class FControl;
}

class FControl : public QDialog
{
    Q_OBJECT

public:
    explicit FControl(QWidget *parent = 0);
    ~FControl();

private slots:

    void on_id_control_text_cursorPositionChanged();

    void on_but_ajouter_clicked();


private:
    Ui::FControl *ui;
    Control *Cont;
    Connexion *C;
};

#endif // FCONTROL_H
