#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reclamation.h"
#include "fournisseur.h"
#include <QSqlQuery>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
ui->idr->setValidator(new QIntValidator(100, 999, this));
Reclamation R;
Fournisseur F;
ui->tab_reclamation->setModel(R.afficher());
ui->tab_fournisseur->setModel(F.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    QString id=ui->idr->text();
    QString nom=ui->idf->text();
    QString prenom=ui->idc->text();
    QString desc=ui->desc->text();
 Reclamation R(id,nom,prenom,desc);
 bool test=R.ajouter();
 QMessageBox msgBox;

 if(test)
 {  msgBox.setText("Ajout avec succes.");
     ui->idr->setText("");
     ui->idf->setText("");
     ui->idc->setText("");
     ui->desc->setText("");
     ui->tab_reclamation->setModel(R.afficher());
 }
 else {
     msgBox.setText("Echec d'ajout");}
     msgBox.exec();
}

void MainWindow::on_pb_supprimer_clicked()
{
    Reclamation R1; R1.setIdReclamation(ui->le_id_supp->text());
    bool test=R1.supprimer(R1.getIdReclamation());
    QMessageBox msgBox;
    if(test)
    {
        msgBox.setText("Suppression avec succes.");
        ui->le_id_supp->setText("");
        ui->tab_reclamation->setModel(R.afficher());
    }
    else
    {
        msgBox.setText("Echec de suppression");}
        msgBox.exec();
}

void MainWindow::on_pb_rechercher_clicked()
{
    QMessageBox msgBox;
    bool error=false;
        QSqlQuery query;
        QString id = ui->idr_modif->text();
        if(id.length() != 0)
        {
            if(ui->idc_modif->text().length() == 0 && ui->idf_modif->text().length() == 0 )
                query.prepare(" SELECT* from RECLAMATIONS where ID_RECLAMATION= '" + id + "'");
            else{
                msgBox.setText("Veuillez ne remplir qu'un seul champ pour la recherche");
                msgBox.exec();
                error=true;
            }
        }
        else
        {
            id = ui->idf_modif->text();
            if(id.length() != 0)
            {
                if(ui->idc_modif->text().length() == 0 )
                    query.prepare(" SELECT* from RECLAMATIONS where ID_FOURNISSEUR= '" + id + "'");
                else{
                    msgBox.setText("Veuillez ne remplir qu'un seul champ pour la recherche");
                    msgBox.exec();
                    error=true;
                }
            }
            else
            {
                id = ui->idc_modif->text();
                if(id.length() != 0)
                {
                    query.prepare(" SELECT* from RECLAMATIONS where ID_CLIENT= '" + id + "'");
                }
            }
        }
        bool test = query.exec();
        if(test)
        {
            query.next();
            ui->idr_modif->setText(query.value(0).toString());
            ui->idf_modif->setText(query.value(1).toString());
            ui->idc_modif->setText(query.value(2).toString());
            if(ui->idc_modif->text().length() != 0 )
                ui->pb_modifier->setEnabled(true);
            ui->tab_reclamation->setModel(R.afficher());
        }
        else
        {
            if(!error){
            msgBox.setText("Echec de la recherche");
            msgBox.exec();}
        }
}


void MainWindow::on_pb_modifier_clicked()
{
    QString idr = ui->idr_modif->text();
    QString idf = ui->idf_modif->text();
    QString idc = ui->idc_modif->text();
    Reclamation R(idr, idf, idc,"");
    bool test = R.modifier(idr);
    QMessageBox msgBox;

    if(test)
    {
        msgBox.setText("Modification avec succes.");
        ui->pb_modifier->setEnabled(false);
        ui->tab_reclamation->setModel(R.afficher());
    }
    else
    {
        msgBox.setText("Echec de modification");
    }
    msgBox.exec();
}

void MainWindow::on_pb_ajouter_f_clicked()
{
    QString id=ui->id_founisseur->text();
    QString nom=ui->nom_founisseur->text();
    int tel=ui->tel_founisseur->text().toInt();
    QString region=ui->region_founisseur->text();
    QString categorie=ui->categorie_fournisseur->text();
 Fournisseur F(id,nom,tel,region,categorie);
 bool test=F.ajouter();
 QMessageBox msgBox;

 if(test)
 {  msgBox.setText("Ajout avec succes.");
     ui->id_founisseur->setText("");
     ui->nom_founisseur->setText("");
     ui->tel_founisseur->setText("");
     ui->categorie_fournisseur->setText("");
     ui->region_founisseur->setText("");
     ui->tab_fournisseur->setModel(F.afficher());
 }
 else {
     msgBox.setText("Echec d'ajout");}
     msgBox.exec();
}


void MainWindow::on_pb_supprimer_fournisseur_clicked()
{
    Fournisseur F1;
    F1.setIdFournisseur(ui->id_fournisseur_supp->text());
    bool test=F1.supprimer(F1.getIdFournisseur());
    QMessageBox msgBox;
    if(test)
    {
        msgBox.setText("Suppression avec succes.");
        ui->id_fournisseur_supp->setText("");
        ui->tab_fournisseur->setModel(F1.afficher());
    }
    else
    {
        msgBox.setText("Echec de suppression");}
        msgBox.exec();
}

void MainWindow::on_pb_rechercher_f_clicked()
{
    Fournisseur F;
    QMessageBox msgBox;
        QSqlQuery query;
        QString id = ui->id_founisseur_modif->text();
        if(id.length() != 0)
        {
                query.prepare(" SELECT* from FOURNISSEURS where ID_FOURNISSEUR= '" + id + "'");
        }
        bool test = query.exec();
        if(test)
        {
            query.next();
            ui->id_founisseur_modif->setText(query.value(0).toString());
            ui->nom_founisseur_modif->setText(query.value(1).toString());
            ui->tel_fournisseur_modif->setText(query.value(2).toString());
            ui->region_founisseur_modif->setText(query.value(3).toString());
            ui->categorie_fournisseur_modif->setText(query.value(4).toString());
            if(ui->nom_founisseur_modif->text().length() != 0 )
                ui->pb_modifier_f->setEnabled(true);
            ui->tab_fournisseur->setModel(F.afficher());
        }
        else
        {
            msgBox.setText("Echec de la recherche");
            msgBox.exec();
        }
}

void MainWindow::on_pb_modifier_f_clicked()
{
    QString idf = ui->id_founisseur_modif->text();
    QString nom = ui->nom_founisseur_modif->text();
    int tel = ui->tel_fournisseur_modif->text().toInt();
    QString region = ui->region_founisseur_modif->text();
    QString categorie = ui->categorie_fournisseur_modif->text();
    Fournisseur F(idf, nom,tel, region,categorie);
    bool test = F.modifier(idf);
    QMessageBox msgBox;

    if(test)
    {
        msgBox.setText("Modification avec succes.");
        ui->pb_modifier_f->setEnabled(false);
        ui->tab_fournisseur->setModel(F.afficher());
    }
    else
    {
        msgBox.setText("Echec de modification");
    }
    msgBox.exec();
}

void MainWindow::on_pb_reset_clicked()
{
    ui->id_founisseur_modif->setText("");
    ui->nom_founisseur_modif->setText("");
    ui->tel_fournisseur_modif->setText("");
    ui->region_founisseur_modif->setText("");
    ui->categorie_fournisseur_modif->setText("");
    ui->pb_modifier_f->setEnabled(false);
}
