#include "paie.h"


Paie::Paie()
{
    IdBulletin=0;
    IdEmploye=0;
    periode_payee="";
    salaire_fixe=0;
    heure_supplementaire=0;
    absence=0;
    prime=0;
    salaire_brut=0;
    cotisations_sociales=0;
    salaire_net=0;
    CSG_deductible=0;
    net_fiscal=0;
    CSG_nondeductible=0;
    CRDS=0;
    salaire_payer=0;
    etat=false;
}
void Paie::ajouter()
{
  
  salaire_brut=salaire_fixe+heure_supplementaire+prime-absence;
  salaire_net=salaire_brut-cotisations_sociales;
  net_fiscal=salaire_net-CSG_deductible;
  salaire_payer=net_fiscal-CSG_nondeductible-CRDS;
  QSqlQuery query;
      if((query.prepare( "INSERT INTO PAIE (IdBulletin,IdEmploye,PeriodePaie,SalaireFixe,Prime,Absence,HeureSupp,SalaireBrut,CotisationSociale,SalaireNet,CSG_Deductible,NetFiscal,CSG_Nondeductible,CRDS,SalairePayee,Etat) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)")))

           {
            query.addBindValue(this->IdBulletin);
            query.addBindValue(this->IdEmploye);
            query.addBindValue(this->periode_payee);
            query.addBindValue(this->salaire_fixe);
            query.addBindValue(this->prime);
            query.addBindValue(this->absence);
            query.addBindValue(this->heure_supplementaire);
            query.addBindValue(this->salaire_brut);
            query.addBindValue(this->cotisations_sociales);
            query.addBindValue(this->salaire_net);
            query.addBindValue(this->CSG_deductible);
            query.addBindValue(this->net_fiscal);
            query.addBindValue(this->CSG_nondeductible);
            query.addBindValue(this->CRDS);
            query.addBindValue(this->salaire_payer);
            query.addBindValue(this->etat);
            query.exec();
          qDebug() << "Ajout reussie";
           }
      else {qDebug() << "Ajout non reussie ???????";}

}
QSqlQueryModel * Paie::afficher()
{
    
    QSqlQuery* qrt=new QSqlQuery();
    QSqlQueryModel *model=new QSqlQueryModel();
    qrt->prepare("select IdBulletin,IdEmploye,PeriodePaie,SalaireFixe,Prime,Absence,HeureSupp,SalaireBrut,CotisationSociale,SalaireNet,CSG_Deductible,NetFiscal,CSG_Nondeductible,CRDS,SalairePayee,Etat from PAIE");
    qrt->exec();
    model->setQuery(*qrt);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IdBulletin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("IdEmploye"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PeriodePaie"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("SalaireFixe"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prime"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Absence"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("HeureSupp"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("SalaireBrut"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("CotisationSociale"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("SalaireNet"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("CSG_Deductible"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("NetFiscal"));
    model->setHeaderData(12, Qt::Horizontal, QObject::tr("CSG_Nondeductible"));
    model->setHeaderData(13, Qt::Horizontal, QObject::tr("CRDS"));
    model->setHeaderData(14, Qt::Horizontal, QObject::tr("SalairePayee"));
    model->setHeaderData(15, Qt::Horizontal, QObject::tr("Etat"));
return model;
}

void Paie::modifier()
{
    
    salaire_brut=salaire_fixe+heure_supplementaire+prime-absence;
    salaire_net=salaire_brut-cotisations_sociales;
    net_fiscal=salaire_net-CSG_deductible;
    salaire_payer=net_fiscal-CSG_nondeductible-CRDS;
    QSqlQuery query;
        if((query.prepare( "UPDATE PAIE SET IdEmploye=?,PeriodePaie=?,SalaireFixe=?,Prime=?,Absence=?,HeureSupp=?,SalaireBrut=?,CotisationSociale=?,SalaireNet=?,CSG_Deductible=?,NetFiscal=?,CSG_Nondeductible=?,CRDS=?,SalairePayee=?,Etat=? WHERE IdBulletin=?")))

             {
              query.addBindValue(this->IdEmploye);
              query.addBindValue(this->periode_payee);
              query.addBindValue(this->salaire_fixe);
              query.addBindValue(this->prime);
              query.addBindValue(this->absence);
              query.addBindValue(this->heure_supplementaire);
              query.addBindValue(this->salaire_brut);
              query.addBindValue(this->cotisations_sociales);
              query.addBindValue(this->salaire_net);
              query.addBindValue(this->CSG_deductible);
              query.addBindValue(this->net_fiscal);
              query.addBindValue(this->CSG_nondeductible);
              query.addBindValue(this->CRDS);
              query.addBindValue(this->salaire_payer);
              query.addBindValue(this->etat);
              query.addBindValue(this->IdBulletin);
              query.exec();
            qDebug() << "modifier";
             }
        else {qDebug() << "Non modifier ???????";}
}

void Paie::supprimer()
{
    
    QSqlQuery query;
        if((query.prepare( "DELETE FROM PAIE WHERE IdBulletin=?")))
        {
           query.addBindValue(this->IdBulletin);
            query.exec();
           qDebug() << "Supprimer";
        }
        else {qDebug() << "non supprimer ???????";}
}

bool Paie::verifier_id()
{
    
    QSqlQuery query;

         if((query.prepare("SELECT IdBulletin,IdEmploye,PeriodePaie,SalaireFixe,Prime,Absence,HeureSupp,SalaireBrut,CotisationSociale,SalaireNet,CSG_Deductible,NetFiscal,CSG_Nondeductible,CRDS,SalairePayee,Etat FROM PAIE WHERE IdBulletin=?")))
              {
             query.addBindValue(this->IdBulletin);
              query.exec();
              if(query.next())
              {
                  setidEmploye(query.value(1).toInt());
                  setperiode(query.value(2).toString());
                  setsalaire_fixe(query.value(3).toDouble());
                  setprime(query.value(4).toDouble());
                  setabsence(query.value(5).toDouble());
                  setheure_supp(query.value(6).toDouble());
                  setsalaire_brut(query.value(7).toDouble());
                  setcotisation(query.value(8).toDouble());
                  setsalaire_net(query.value(9).toDouble());
                  setCSG_deductible(query.value(10).toDouble());
                  setnet_fiscal(query.value(11).toDouble());
                  setCSG_nondeductible(query.value(12).toDouble());
                  setCRDS(query.value(13).toDouble());
                  setsalaire_payer(query.value(14).toDouble());
                  setetat(query.value(15).toBool());
                  return true;
              }else{return false;}

              }
return false;
}
void Paie::export_pdf()
{
    QString chemin = QString::number(this->IdBulletin)+".pdf";
    QString fileName= QDir::currentPath() + "/../PDF/"+chemin;
         if (!fileName.isEmpty())
         {
             if (QFileInfo(fileName).suffix().isEmpty())
                              fileName.append(".pdf");
                          QPrinter printer(QPrinter::HighResolution);
                           printer.setOutputFormat(QPrinter::PdfFormat);
                           printer.setPageSize(QPrinter::A4);
                           printer.setOutputFileName(fileName);

                           printer.setPageMargins(8,3,3,5,QPrinter::Millimeter);
                           QPainter painter(&printer);
                           painter.setRenderHint(QPainter::Antialiasing);



                            painter.drawImage(500,500,QImage(QDir::currentPath() + "/../graphs/logo_edf.png"));
                             painter.setFont(QFont("Arial", 10));
                                painter.drawText(6500,1000,"Departement Ressources Humaines");
                                painter.setPen(Qt::darkBlue);
                                painter.setFont(QFont("Arial", 25));
                                QString idbulletin = QString::number(getidBulletin());
                                painter.drawText(3000,3000,"Bulletin de paie N° "+idbulletin);
                                 QRectF rectangle(3000.0, 3500.0, 3500.0, 2200.0);
                                  painter.drawRect(rectangle);
                                  painter.setPen(Qt::black);
                                  painter.setFont(QFont("Arial", 10));
                                  painter.drawText(3200,3900,"Periode = "+getperiode());
                                  QString idemploye = QString::number(getidEmploye());
                                  painter.drawText(3200,4200,"IdEmploye = "+idemploye);
                                  QSqlQuery query;
                                  if((query.prepare("SELECT Nom,Prenom,Adresse,Grade from employes where IdEmploye=?")))
                                       {
                                      query.addBindValue(this->IdEmploye);
                                       query.exec();
                                       if(query.next())
                                       {
                                           painter.drawText(3200,4500,"Nom = "+query.value(0).toString());
                                           painter.drawText(3200,4800,"Prenom = "+query.value(1).toString());
                                           painter.drawText(3200,5100,"Adresse = "+query.value(2).toString());
                                           painter.drawText(3200,5400,"Grade = "+query.value(3).toString());
                                       }
                                  }
                                  painter.setPen(Qt::darkBlue);
                                  QRectF rectangle2(500.0, 6500.0, 8100.0, 6400.0);
                                  painter.drawRect(rectangle2);
                                  painter.setPen(Qt::black);
                                  QString salaire_fixe = QString::number(getsalaire_fixe());
                                  painter.drawText(700,7000,"Salaire fixe : "+salaire_fixe+" €");
                                  QString hs = QString::number(getheure_supp());
                                  painter.drawText(700,7500,"Heures supplementaires : "+hs+" €");
                                  QString ab = QString::number(getabsence());
                                  painter.drawText(700,8000,"Absence non justifiee : "+ab+" €");
                                  QString prime = QString::number(getprime());
                                  painter.drawText(700,8500,"Prime : "+prime+" €");
                                  painter.setPen(Qt::red);
                                  painter.drawText(2400,8750,"Salaire brut = Salaire fixe+Heures supplementaires+Prime-Absence non justifiee");
                                  painter.setPen(Qt::black);
                                  QString salaire_brut = QString::number(getsalaire_brut());
                                  painter.drawText(700,9000,"Salaire brut : "+salaire_brut+" €");
                                  QString cs = QString::number(getcotisations());
                                  painter.drawText(700,9500,"Cotisations sociales : "+cs+" €");
                                  QString salaire_net = QString::number(getsalaire_net());
                                  painter.setPen(Qt::red);
                                  painter.drawText(2700,9750,"Salaire net = Salaire brut-Cotisations sociales");
                                  painter.setPen(Qt::black);
                                  painter.drawText(700,10000,"Salaire net : "+salaire_net+" €");
                                  QString csg = QString::number(getCSG_deductible());
                                  painter.drawText(700,10500,"CSG deductible : "+csg+" €");
                                  QString nf = QString::number(getnet_fiscal());
                                  painter.setPen(Qt::red);
                                  painter.drawText(2700,10750,"Net fiscal = Salaire net-CSG deductible");
                                  painter.setPen(Qt::black);
                                  painter.drawText(700,11000,"Net fiscal : "+nf+" €");
                                  QString csgn = QString::number(getCSG_nondeductible());
                                  painter.drawText(700,11500,"CSG non deductible : "+csgn+" €");
                                  QString crds = QString::number(getCRDS());
                                  painter.drawText(700,12000,"CRDS : "+crds+" €");
                                  painter.setPen(Qt::red);
                                  painter.drawText(2700,12250,"Salaire payee = Net fiscal-CSG non deductible-CRDS");
                                  painter.setPen(Qt::black);
                                  QString salaire_payer = QString::number(getsalaire_payer());
                                  painter.drawText(700,12500,"Salaire payee : "+salaire_payer+" €");
                                  painter.end();
         }
}

////////////////////////////get & set///////////////////////////////////////////////////
int Paie::getidBulletin()
{
    return IdBulletin;
}

void Paie::setidBulletin(int IdBulletin)
{
    this->IdBulletin=IdBulletin;
}
int Paie::getidEmploye()
{
    return IdEmploye;
}

void Paie::setidEmploye(int IdEmploye)
{
    this->IdEmploye=IdEmploye;
}

QString Paie::getperiode()
{
   return periode_payee;
}

void Paie::setperiode(QString periode_payee)
{
    this->periode_payee=periode_payee;
}

double Paie::getsalaire_fixe()
{
    return salaire_fixe;
}

void Paie:: setsalaire_fixe(double salaire_fixe)
{
  this->salaire_fixe=salaire_fixe;
}

double Paie::getheure_supp()
{
    return heure_supplementaire;
}

void Paie:: setheure_supp(double heure_supplementaire)
{
  this->heure_supplementaire=heure_supplementaire;
}

double Paie::getabsence()
{
    return absence;
}

void Paie:: setabsence(double absence)
{
  this->absence=absence;
}

double Paie::getprime()
{
    return prime;
}

void Paie:: setprime(double prime)
{
  this->prime=prime;
}

double Paie::getsalaire_brut()
{
    return salaire_brut;
}

void Paie:: setsalaire_brut(double salaire_brut)
{
  this->salaire_brut=salaire_brut;
}

double Paie::getcotisations()
{
    return cotisations_sociales;
}

void Paie:: setcotisation(double cotisations_sociales)
{
  this->cotisations_sociales=cotisations_sociales;
}

double Paie::getsalaire_net()
{
    return salaire_net;
}

void Paie:: setsalaire_net(double salaire_net)
{
  this->salaire_net=salaire_net;
}

double Paie::getCSG_deductible()
{
    return CSG_deductible;
}

void Paie:: setCSG_deductible(double CSG_deductible)
{
  this->CSG_deductible=CSG_deductible;
}

double Paie::getCRDS()
{
    return CRDS;
}

void Paie:: setCRDS(double CRDS)
{
  this->CRDS=CRDS;
}

double Paie::getsalaire_payer()
{
    return salaire_payer;
}

void Paie:: setsalaire_payer(double salaire_payer)
{
  this->salaire_payer=salaire_payer;
}
double Paie::getCSG_nondeductible()
{
    return CSG_nondeductible;
}

void Paie:: setCSG_nondeductible(double CSG_nondeductible)
{
  this->CSG_nondeductible=CSG_nondeductible;
}

double Paie::getnet_fiscal()
{
    return net_fiscal;
}

void Paie:: setnet_fiscal(double net_fiscal)
{
  this->net_fiscal=net_fiscal;
}
bool Paie::getetat()
{
    return etat;
}

void Paie:: setetat(bool etat)
{
  this->etat=etat;
}
///////////////////////////////////////////////////////////////////////////////////////
bool Paie::validerPaiment()
{
    
    QSqlQuery *qrtUpdate = new QSqlQuery();

    if(!(qrtUpdate->prepare("UPDATE Paie SET Etat = :s WHERE IdBulletin = :i"))) return false;
    qrtUpdate->bindValue(":s", true);
    qrtUpdate->bindValue(":i", IdBulletin);
    qrtUpdate->exec();

    /************UPDATE Montant Depenses********/
    QSqlQuery *qrtDep = new QSqlQuery ();
    if(!(qrtDep->prepare("update Budgets set MontantDepenses = MontantDepenses + (select SalairePayee from Paie where IdBulletin = :id)"))) return false;
    qrtDep->bindValue(":id", IdBulletin);
    qrtDep->exec();


    return true;

}

QSqlQueryModel * Paie::afficherPaieNV()
{
    

    QSqlQuery* qrt=new QSqlQuery();
    QSqlQueryModel *model=new QSqlQueryModel;

    qrt->prepare("select IdBulletin, IdEmploye, SalairePayee, Etat from Paie where Etat = :s");
    qrt->bindValue(":s", false);
    qrt->exec();


    model->setQuery(*qrt);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id Bulletin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("IdEmploye"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Salaire"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat"));

return model;

}
