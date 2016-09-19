#ifndef SOUND_H
#define SOUND_H

#include <QString>
#include <QtMultimedia/QSound>
#include <QtMultimedia/QSoundEffect>
#include <QUrl>
#include <QDebug>
#include <QMediaPlayer>
#include <QFile>
#include <QFileInfo>
#include <QDir>

class Sound
{
    /*
     *General sounds
     */
    QString cheminBouton;
    QString cheminTables;
    QString cheminIntro;
    QString cheminFermeture;
    QString cheminChangVals;
    QString cheminWarnings;
    QString cheminQuestions;
    QString cheminInfos;

    QString accueil;

    /*
     *Production Sounds
     */

    QString Bienvenue;
    QString existeDeja;
    QString doneProd;
    QString ajoutEffectue;
    QString modifSuccess;

public:
    Sound ();
    //Sound (QString, QString, QString, QString, QString, QString ,QString, QString);

    /*
    void playSoundButton();
    void playSoundTabs();
    void playSoundIntro();
    void playSoundFerm();
    void playSoundChangVals();
    void playSoundWarns();
    void playSoundQuests();
    void playSoundInfos();
    */

    void play(QString);

};



#endif // SOUND_H
