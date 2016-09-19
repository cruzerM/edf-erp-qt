#include "messages.h"
#include "ui_messages.h"

Messages::Messages(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Messages)

{
    ui->setupUi(this);
    ui->combo_dest->setModel(M->refreshComboDest());

}
Messages::Messages (QWidget *parent, QString ch) :
    QDialog(parent),
    ui(new Ui::Messages)
{
    ui->setupUi(this);

    ui->combo_dest->setModel(M->refreshComboDest());
    ui->label_source->setText(ch);

    /*
     *Reception
     */

    temps_reel();
}

Messages::~Messages()
{
    delete ui;
}

void Messages::on_but_env_clicked()
{
    M = new Messagerie();
    M->setDestinataire(ui->combo_dest->currentText());
    M->setExpediteur(ui->label_source->text());
    M->setMessage(ui->text_message->toPlainText());

    if (M->envoyerMessage())
    {
        QMessageBox::information(this, "Notice", "Message Envoyé avec Succés!");
        temps_reel();        
    }

}

void Messages::on_but_lu_clicked()
{
    if(M->lireMessage(ui->dest_name->text(), ui->message_reception->text()))
    {
        refresh_messages();
        ui->dest_name->setText("");
        ui->heure_text->setText("");
        ui->message_reception->setText("");

    }
}

bool Messages::refresh_messages()
{
     ui->dest_name->setText(M->recevoirMessage(ui->label_source->text()).value("Expediteur").toString());
     ui->message_reception->setText(M->recevoirMessage(ui->label_source->text()).value("Msg").toString());
     ui->heure_text->setText(M->recevoirMessage(ui->label_source->text()).value("Date").toString());
     return true;
}



void Messages::temps_reel()
{
    QTimer* mTimer;
    mTimer = new QTimer(this);
    mTimer->start(750);
    mTimer->setSingleShot(false);

    if (refresh_messages())
    {
        connect(mTimer, SIGNAL(timeout()), SLOT(refresh_messages()));
    }
}

void Messages::on_but_quitter_clicked()
{
    close();
}
