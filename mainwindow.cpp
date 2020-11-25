#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reclamation.h"
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
     ui->tab_etudiant->setModel(R.afficher());
 }
 else
     msgBox.setText("Echec d'ajout");
     msgBox.exec();
}

void MainWindow::on_pb_supprimer_clicked()
{
    Reclamation R1; R1.setIdReclamation(ui->le_id_supp->text());
    bool test=R1.supprimer(R1.getIdReclamation());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
    ui->tab_etudiant->setModel(R.afficher());

    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();

}
