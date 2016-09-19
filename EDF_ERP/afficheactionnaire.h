#ifndef AFFICHEACTIONNAIRE_H
#define AFFICHEACTIONNAIRE_H

#include <QDialog>
#include <QString>

#include "actionnaire.h"

namespace Ui {
class AfficheActionnaire;
}

class AfficheActionnaire : public QDialog
{
    Q_OBJECT

public:
    AfficheActionnaire(QWidget *parent, Actionnaire&, bool, int privilege);
    ~AfficheActionnaire();

private slots:
    void on_EnregistrerActionnaire_clicked();

private:
    Ui::AfficheActionnaire *ui;
    Actionnaire A;
};

#endif // AFFICHEACTIONNAIRE_H
