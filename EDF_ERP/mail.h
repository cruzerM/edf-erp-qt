#ifndef MAIL_H
#define MAIL_H

#include <QDialog>
#include <QWidget>
#include <QString>
#include <QFileDialog>
#include <QErrorMessage>
#include <QMessageBox>
#include <iostream>
//////////////////////////////

#include "./srcMail/smtpclient.h"
#include "./srcMail/mimepart.h"
#include "./srcMail/mimehtml.h"
#include "./srcMail/mimeattachment.h"
#include "./srcMail/mimemessage.h"
#include "./srcMail/mimetext.h"
#include "./srcMail/mimeinlinefile.h"
#include "./srcMail/mimefile.h"

///////////////////////////////
namespace Ui {
class Mail;
}

class Mail : public QDialog
{
    Q_OBJECT

public:
    explicit Mail(QWidget *parent = 0);
    ~Mail();
    static EmailAddress * stringToEmail(const QString & str);

private slots:
    void on_ButtonAttach_clicked();

    void on_ButtonEnvoie_clicked();

    void on_ButtonAnnuler_clicked();

private:
    Ui::Mail *ui;
    void errorMessage(const QString & message);
};

#endif // MAIL_H
