#include "login.h"
#include "intro.h"
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QCursor>
#include <QPixmap>

void loadstyle()
{
    QFile data (QDir::currentPath() + "/../Style/style.qss");
    QString style;
    if(data.open(QFile::ReadOnly))
    {
        QTextStream styleIn(&data);
        style = styleIn.readAll();
        data.close();
        qApp->setStyleSheet(style);
    }
}

void chargerIntro()
{
    Intro Int;
    Int.exec();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connexion C;
    C.ConnectionBD();

    loadstyle();

    Login L;

    chargerIntro();

    L.show();


    return a.exec();
}
