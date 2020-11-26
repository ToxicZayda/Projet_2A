#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reclamation.h"
#include <QSqlQuery>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
ui->le_id->setValidator(new QIntValidator(100, 999, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    QString id=ui->le_id->text();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
 Reclamation R(id,nom,prenom);
 bool test=R.ajouter();
 QMessageBox msgBox;

 if(test)
 {  msgBox.setText("Ajout avec succes.");
     ui->le_id->setText("");
     ui->le_nom->setText("");
     ui->le_prenom->setText("");
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
        QString id = ui->le_id_modif->text();
        if(id.length() != 0)
        {
            if(ui->le_prenom_modif->text().length() == 0 && ui->le_nom_modif->text().length() == 0 )
                query.prepare(" SELECT* from RECLAMATIONS where ID_RECLAMATION= '" + id + "'");
            else{
                msgBox.setText("Veuillez ne remplir qu'un seul champ pour la recherche");
                msgBox.exec();
                error=true;
            }
        }
        else
        {
            id = ui->le_nom_modif->text();
            if(id.length() != 0)
            {
                if(ui->le_prenom_modif->text().length() == 0 )
                    query.prepare(" SELECT* from RECLAMATIONS where ID_FOURNISSEUR= '" + id + "'");
                else{
                    msgBox.setText("Veuillez ne remplir qu'un seul champ pour la recherche");
                    msgBox.exec();
                    error=true;
                }
            }
            else
            {
                id = ui->le_prenom_modif->text();
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
            ui->le_id_modif->setText(query.value(0).toString());
            ui->le_nom_modif->setText(query.value(1).toString());
            ui->le_prenom_modif->setText(query.value(2).toString());
            if(ui->le_prenom_modif->text().length() != 0 )
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
    QString idr = ui->le_id_modif->text();
    QString idf = ui->le_nom_modif->text();
    QString idc = ui->le_prenom_modif->text();
    Reclamation R(idr, idf, idc);
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
