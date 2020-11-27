#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reclamation.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Reclamation::Reclamation()
{
IdReclamation=""; IdFournisseur=""; IdClient="";
}

Reclamation::Reclamation(QString IdReclamation,QString IdFournisseur,QString IdClient,QString Desc)
{this->IdReclamation=IdReclamation; this->IdFournisseur=IdFournisseur; this->IdClient=IdClient;this->Desc=Desc;}
QString Reclamation::getIdReclamation(){return IdReclamation;}
QString Reclamation::getIdFournisseur(){return  IdFournisseur;}
QString Reclamation::getIdClient(){return IdClient;}
void Reclamation::setIdReclamation(QString IdReclamation){this->IdReclamation=IdReclamation;}
void Reclamation::setIdFournisseur(QString IdFournisseur){this->IdFournisseur=IdFournisseur;}
void Reclamation::setIdClient(QString IdClient){this->IdClient=IdClient;}
bool Reclamation::ajouter()
{

    QSqlQuery query;
         query.prepare("INSERT INTO RECLAMATIONS (ID_RECLAMATION, ID_FOURNISSEUR, ID_CLIENT,DESCRIPTION) "
                       "VALUES (:id, :forename, :surname, :desc)");
         query.bindValue(":id",IdReclamation);
         query.bindValue(":forename", IdFournisseur);
         query.bindValue(":surname", IdClient);
         query.bindValue(":desc", Desc);
        return query.exec();

}
bool Reclamation::supprimer(QString id)
{
    QSqlQuery query;
         query.prepare(" Delete from RECLAMATIONS where ID_RECLAMATION=:id");
         query.bindValue(0, id);
        return query.exec();
}

bool Reclamation::modifier(QString id)
{
    QSqlQuery query;
         query.prepare(" update RECLAMATIONS set ID_RECLAMATION='"+IdReclamation+"',ID_FOURNISSEUR='"+IdFournisseur+"',ID_CLIENT='"+IdClient+"'where ID_RECLAMATION='"+id+"'");
         return query.exec();
}

QSqlQueryModel* Reclamation::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();

   model->setQuery("SELECT* FROM RECLAMATIONS");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_RECLAMATION"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_FOURNISSEUR"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID_CLIENT"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESCRIPTION"));

  return  model;
}

