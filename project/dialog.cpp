#include "dialog.h"
#include "ui_dialog.h"
#include "employe.h"
#include"profil.h"
#include <QMessageBox>
#include <QDate>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->le_tele->setValidator(new QIntValidator(10000000, 99999999, this));
    ui->tab_employe->setModel(E.afficher());
    ui->tab_profil->setModel(P.afficherP());

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pb_ajouter_clicked()
{
    int id = ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    int cin = ui->le_cin->text().toInt();
    QString date=ui->le_date->text();
    int tele = ui->le_tele->text().toInt();
    float salaire = ui->le_sal->text().toFloat();

 employe E(id,nom,prenom,cin,date,tele,salaire);
 bool test=E.ajouter();
 QMessageBox msgBox;

 if(test)
   {  msgBox.setText("Ajout avec succes.");
     ui->tab_employe->setModel(E.afficher());
 }
 else
     msgBox.setText("Echec d'ajout");
     msgBox.exec();
}

void Dialog::on_delete_2_clicked()
{

    employe E1; E1.setid(ui->id_delete->text().toInt());
    bool test=E1.supprimer(E1.getid());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
    ui->tab_employe->setModel(E.afficher());

    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();
}




void Dialog::on_pb_ajouter_profil_clicked()
{   int id  = ui->le_id2->text().toInt();
    QString user=ui->le_user->text();
    QString pass=ui->le_pass->text();
    QString  mail=ui->le_mail->text();
    QString role=ui->le_role->text();
QDate date=QDate::currentDate();
QString datec=date.toString("dd.MM.yyyy");
 profil P(id,user,pass,mail,role,datec);
 bool test=P.ajouterP();
 QMessageBox msgBox;

 if(test)
   {  msgBox.setText("Ajout avec succes.");
     ui->tab_profil->setModel(P.afficherP());
 }
 else
     msgBox.setText("Echec d'ajout");
     msgBox.exec();

}

void Dialog::on_bt_delete_clicked()
{profil P1; P1.setid(ui->le_delete->text().toInt());
    bool test=P1.supprimerP(P1.getid());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
    ui->tab_profil->setModel(P.afficherP());

    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();

}

void Dialog::on_pb_update_clicked()
{
    int id = ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    int cin = ui->le_cin->text().toInt();
    QString date=ui->le_date->text();
    int tele = ui->le_tele->text().toInt();
    float salaire = ui->le_sal->text().toFloat();

 employe E2(id,nom,prenom,cin,date,tele,salaire);
 bool test=E2.modifier();
 QMessageBox msgBox;

 if(test)
   {  msgBox.setText("modifier avec succes.");
     ui->tab_employe->setModel(E.afficher());
 }
 else
     msgBox.setText("Echec de modification");
     msgBox.exec();
}

void Dialog::on_pb_updateP_clicked()
{
    int id  = ui->le_id2->text().toInt();
        QString user=ui->le_user->text();
        QString pass=ui->le_pass->text();
        QString  mail=ui->le_mail->text();
        QString role=ui->le_role->text();
    QDate date=QDate::currentDate();
    QString datec=date.toString("dd.MM.yyyy");
     profil P2(id,user,pass,mail,role,datec);
     bool test=P2.modifier();
     QMessageBox msgBox;

     if(test)
       {  msgBox.setText("Modification avec succes.");
         ui->tab_profil->setModel(P.afficherP());
     }
     else
         msgBox.setText("Echec de modification");
         msgBox.exec();

}

void Dialog::on_pb_find_clicked()
{int id =-1;
    int cin=-1;
    int tele=-1;
    id=ui->id_find->text().toInt();
     cin=ui->cin_find->text().toInt();
      tele=ui->tele_find->text().toInt();
     QMessageBox msgBox;
     employe E3;
    if(ui->id_find->text().isEmpty() && ui->cin_find->text().isEmpty() && ui->tele_find->text().isEmpty()  ){
         msgBox.setText("line edit est vide");
    }
    else if( ui->cin_find->text().isEmpty() && ui->tele_find->text().isEmpty()  ){


    ui->tab_employe->setModel(E3.recherche_id(id,cin,tele));
}
else if( ui->id_find->text().isEmpty() && ui->tele_find->text().isEmpty() ){
id =-1;
 int tele=-1;
        ui->tab_employe->setModel(E3.recherche_id(id,cin,tele));
    }
    else if( ui->id_find->text().isEmpty() && ui->cin_find->text().isEmpty())
         ui->tab_employe->setModel(E3.recherche_id(id,cin,tele));
else
      msgBox.setText("plus q'un est ligne est rempli");
  msgBox.exec();
}

void Dialog::on_tri_nom_clicked()
{
      ui->tab_employe->setModel(E.trier_n());
}

void Dialog::on_tri_id_clicked()
{
     ui->tab_employe->setModel(E.trier_i());
}

void Dialog::on_tri_prenom_clicked()
{
    ui->tab_employe->setModel(E.trier_p());
}

void Dialog::on_pushButton_clicked()
{
     ui->tab_employe->setModel(E.afficher());
}

/*void Dialog::on_pushButton_3_clicked()
{QVector<QString> x;
    employe E3;
    x=E3.stat();


   ui->lineEdit_12->setText(x[0]);
      ui->lineEdit_13->setText(x[1]);
         ui->lineEdit_14->setText(x[2]);
            ui->lineEdit_15->setText(x[3]);
}
*/
