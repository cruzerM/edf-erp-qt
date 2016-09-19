#include "mail.h"
#include "ui_mail.h"

Mail::Mail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mail)
{
    ui->setupUi(this);
}

Mail::~Mail()
{
    delete ui;
}


void Mail::errorMessage(const QString &message)
{
    QErrorMessage err (this);

    err.showMessage(message);

    err.exec();
}

void Mail::on_ButtonAttach_clicked()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::ExistingFiles);


    if (dialog.exec())
        ui->listattach->addItems(dialog.selectedFiles());
}
EmailAddress* Mail::stringToEmail(const QString &str)
{
    return new EmailAddress(str);
}
void Mail::on_ButtonEnvoie_clicked()
{

    QString senderAdress = ui->ValExp->text()+ ui->comboMail->currentText(), host = "";
    int port = 0;
    QString domaine = ui->comboMail->currentText();
    QString password = ui->Valpwd->text();
    if (domaine == "@gmail.com" || domaine == "@esprit.tn")
    {
        host = "smtp.gmail.com";
        port = 465;
    }
    if (domaine == "@yahoo.com")
    {
        host = "smtp.mail.yahoo.com";
        port = 465;
    }
    if (domaine == "@yahoo.fr")
    {
        host = "smtp.mail.yahoo.fr";
        port = 465;
    }

    if (domaine == "@outlook.com")
    {
        host = "smtp.live.com";
        port = 587;
    }

    EmailAddress *sender = stringToEmail(senderAdress);

    QStringList rcptStringList = ui->Valdest->text().split(';');

    QString sujet = ui->Valsujet->text();
    QString html = ui->ValMsg->toHtml();

    SmtpClient smtp (host, port, SmtpClient::SslConnection);

    MimeMessage message;

    message.setSender(sender);
    message.setSubject(sujet);

    for (int i = 0; i < rcptStringList.size(); ++i)
         message.addRecipient(stringToEmail(rcptStringList.at(i)));

    MimeHtml content;
    content.setHtml(html);

    message.addPart(&content);

    for (int i = 0; i < ui->listattach->count(); ++i)
    {
        message.addPart(new MimeAttachment(new QFile(ui->listattach->item(i)->text())));
    }

    if (!smtp.connectToHost())
    {
        errorMessage("Connection Failed");
        return;
    }

    if (!smtp.login(senderAdress, password))
    {
        errorMessage("Authentification Failed");
        return;
    }

    if (!smtp.sendMail(message))
    {
        errorMessage("Mail sending failed");
        return;
    }
    else
    {
        QMessageBox okMessage (this);
        okMessage.setText("The email was succesfully sended.");
        okMessage.exec();
    }

    smtp.quit();

}

void Mail::on_ButtonAnnuler_clicked()
{
    this->close();
}
