#-------------------------------------------------
#
# Project created by QtCreator 2014-01-01T20:50:32
#
#-------------------------------------------------

QT       += core gui sql printsupport multimedia axcontainer webkit webkitwidgets network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EDF_ERP
TEMPLATE = app

    sqfiles.sources = C:\Users\Doudaaa\Desktop\EDF FINAL\Code Source - Projet\database\EDR_ERP_DB.sqlite
    DEPLOYMENT += sqfiles



SOURCES += main.cpp \
    valider.cpp \
    sponsor.cpp \
    sites.cpp \
    responsable.cpp \
    reparation.cpp \
    remplirbd.cpp \
    pub.cpp \
    projets.cpp \
    produit.cpp \
    production.cpp \
    prets.cpp \
    paie.cpp \
    messages.cpp \
    messagerie.cpp \
    matierep.cpp \
    manufacturing.cpp \
    login.cpp \
    interface_paie_rh.cpp \
    interface_menu_rh.cpp \
    interface_employe_rh.cpp \
    interface_contrat_rh.cpp \
    interface_assiduite_rh.cpp \
    fsites.cpp \
    freparation.cpp \
    fproduction.cpp \
    fmp.cpp \
    femployes.cpp \
    fcontrol.cpp \
    fajoutprod.cpp \
    employes.cpp \
    control.cpp \
    contrats.cpp \
    connexion.cpp \
    commande.cpp \
    budget.cpp \
    assiduites.cpp \
    affichesponsor.cpp \
    affichepret.cpp \
    afficheactionnaire.cpp \
    actionnaire.cpp \
    intro.cpp \
    srcMail/smtpclient.cpp \
    srcMail/quotedprintable.cpp \
    srcMail/mimetext.cpp \
    srcMail/mimepart.cpp \
    srcMail/mimemultipart.cpp \
    srcMail/mimemessage.cpp \
    srcMail/mimeinlinefile.cpp \
    srcMail/mimehtml.cpp \
    srcMail/mimefile.cpp \
    srcMail/mimecontentformatter.cpp \
    srcMail/mimeattachment.cpp \
    srcMail/emailaddress.cpp \
    mail.cpp \
    sound.cpp

HEADERS  += \
    valider.h \
    sponsor.h \
    sites.h \
    responsable.h \
    reparation.h \
    remplirbd.h \
    pub.h \
    projets.h \
    produit.h \
    production.h \
    prets.h \
    paie.h \
    messages.h \
    messagerie.h \
    matierep.h \
    manufacturing.h \
    login.h \
    interface_paie_rh.h \
    interface_menu_rh.h \
    interface_employe_rh.h \
    interface_contrat_rh.h \
    interface_assiduite_rh.h \
    fsites.h \
    freparation.h \
    fproduction.h \
    fmp.h \
    femployes.h \
    fcontrol.h \
    fajoutprod.h \
    employes.h \
    control.h \
    contrats.h \
    connexion.h \
    commande.h \
    budget.h \
    assiduites.h \
    affichesponsor.h \
    affichepret.h \
    afficheactionnaire.h \
    actionnaire.h \
    intro.h \
    srcMail/smtpclient.h \
    srcMail/quotedprintable.h \
    srcMail/mimetext.h \
    srcMail/mimepart.h \
    srcMail/mimemultipart.h \
    srcMail/mimemessage.h \
    srcMail/mimeinlinefile.h \
    srcMail/mimehtml.h \
    srcMail/mimefile.h \
    srcMail/mimecontentformatter.h \
    srcMail/mimeattachment.h \
    srcMail/emailaddress.h \
    mail.h \
    sound.h

OTHER_FILES += \
    Logo_miniature.png \
    logo_groupe.png \
    logo_erp.png \
    logo_edf_erp.png \
    logo_edf.png \
    inbox.png \
    ajout.png

FORMS += \
    valider.ui \
    remplirbd.ui \
    messages.ui \
    manufacturing.ui \
    login.ui \
    interface_paie_rh.ui \
    interface_menu_rh.ui \
    interface_employe_rh.ui \
    interface_contrat_rh.ui \
    interface_assiduite_rh.ui \
    fsites.ui \
    freparation.ui \
    fproduit.ui \
    fproduction.ui \
    fmp.ui \
    femployes.ui \
    fcontrol.ui \
    fajoutprod.ui \
    affichesponsor.ui \
    affichepret.ui \
    afficheactionnaire.ui \
    intro.ui \
    mail.ui

RESOURCES += \
    rssources.qrc
