#include "sound.h"


Sound::Sound()
{
    /*
    cheminBouton = "E:/2ème année/Projet C++/Qt/ModuleFinance/soundBouton.wav";
    cheminBouton = QDir::currentPath() + "\..\Sounds\soundBouton.wav";
    cheminTables = QDir::currentPath() + "\..\Sounds\soundTabs.wav";
    cheminIntro = QDir::currentPath() + "\..\Sounds\soundIntro.wav";              //Introduire dans l'animation Flash après !
    cheminFermeture = QDir::currentPath() + "\..\Sounds\soundFermeture.wav";      //Introduire dans l'animation Flash après ??
    cheminChangVals = QDir::currentPath() + "\..\Sounds\soundChangVals.wav";
    cheminWarnings = QDir::currentPath() + "\..\Sounds\soundWarns.wav";
    cheminQuestions = QDir::currentPath() + "\..\Sounds\soundQuests.wav";
    cheminInfos = QDir::currentPath() + "\..\Sounds\soundInfos.wav";
    */

    /*
    accueil = QDir::currentPath() + "/../sounds/accueil.wav";
    Bienvenue = QDir::currentPath() + "/../sounds/bienvenue_dept.wav";
    existeDeja = QDir::currentPath() + "/../sounds/prod_existe.wav";
    doneProd = QDir::currentPath() + "/../sounds/production_achevee.wav";
    ajoutEffectue = QDir::currentPath() + "/../sounds/produit_ajoute.wav";
    modifSuccess = QDir::currentPath() + "/../sounds/succes_modif.wav";
    */


}
/*
Sound::Sound (QString cheminBouton, QString cheminTables, QString cheminIntro, QString cheminFermeture, QString cheminChangVals, QString cheminWarnings, QString cheminQuestions, QString cheminInfos)
{
    this->cheminBouton = cheminBouton;
    this->cheminTables = cheminTables;
    this->cheminIntro = cheminIntro;
    this->cheminFermeture = cheminFermeture;
    this->cheminChangVals = cheminChangVals;
    this->cheminWarnings = cheminWarnings;
    this->cheminQuestions = cheminQuestions;
    this->cheminInfos = cheminInfos;
}

void Sound::playSoundButton()
{
    QSound *S = new QSound (cheminBouton);
    S->play();
}

void Sound::playSoundTabs()
{
    QSound *S = new QSound (cheminTables);
    S->play();
}

void Sound::playSoundIntro()
{
    QSound *S = new QSound (cheminIntro);
    S->play();
}

void Sound::playSoundFerm()
{
    QSound *S = new QSound (cheminFermeture);
    S->play();
}

void Sound::playSoundChangVals()
{
    QSound *S = new QSound (cheminChangVals);
    S->play();
}

void Sound::playSoundWarns()
{
    QSound *S = new QSound (cheminWarnings);
    S->play();
}

void Sound::playSoundQuests()
{
    QSound *S = new QSound (cheminQuestions);
    S->play();
}

void Sound::playSoundInfos()
{
    QSound *S = new QSound (cheminInfos);
    S->play();
}

*/

void Sound::play(QString chemin)
{
    if (chemin == "Accueil")
    {
        QSound *S = new QSound(QDir::currentPath() + "/../sounds/login.wav");
        S->play();
    }
    else if (chemin == "bienvenue au departement")
    {
        QSound *S = new QSound(QDir::currentPath() + "/../sounds/bienvenue_dept.wav");
        S->play();
    }
    else if (chemin == "existe deja")
    {
        QSound *S = new QSound(QDir::currentPath() + "/../sounds/prod_existe.wav");
        S->play();
    }
    else if (chemin == "achevée")
    {
        QSound *S = new QSound(QDir::currentPath() + "/../sounds/production_achevee.wav");
        S->play();
    }
    else if (chemin == "ajouté")
    {
        QSound *S = new QSound(QDir::currentPath() + "/../sounds/produit_ajoute.wav");
        S->play();
    }
    else if (chemin == "modifie")
    {
        QSound *S = new QSound(QDir::currentPath() + "/../sounds/succes_modif.wav");
        S->play();
    }
    else
        return;
}
