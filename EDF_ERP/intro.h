#ifndef INTRO_H
#define INTRO_H

#include <QDialog>
#include <QAxWidget>
#include <QDir>
#include <QTimer>

namespace Ui {
class Intro;
}

class Intro : public QDialog
{
    Q_OBJECT

public:
    explicit Intro(QWidget *parent = 0);
    ~Intro();

private:
    Ui::Intro *ui;

};

#endif // INTRO_H
