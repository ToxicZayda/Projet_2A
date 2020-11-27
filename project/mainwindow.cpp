#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"dialog.h"
#include<QMessageBox>
#include <QSqlQuery>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_connecter_clicked()
{QSqlQuery query;
    QString select ="SELECT  id from profil where username=? and password=?";

    query.prepare(select);
    query.addBindValue(ui->lineEdit_username->text());
     query.addBindValue(ui->lineEdit_password->text());
       query.exec();

     if (query.next()){
       dialog = new Dialog(this);
             dialog->show();
}
     else
         ui->label_3->setText("mot de passe incorrecte");

}
