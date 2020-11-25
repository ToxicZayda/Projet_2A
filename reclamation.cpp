#include "reclamation.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Reclamation::Reclamation()
{
idReclamation=""; IdFournisseur=" "; IdClient="";
}

Reclamation::Reclamation(QString idReclamation,QString IdFournisseur,QString IdClient)
{this->idReclamation=idReclamation; this->IdFournisseur=IdFournisseur; this->IdClient=IdClient;}
QString Reclamation::getIdReclamation(){return idReclamation;}
QString Reclamation::getIdFournisseur(){return  IdFournisseur;}
QString Reclamation::getIdClient(){return IdClient;}
void Reclamation::setIdReclamation(QString idReclamation){this->idReclamation=idReclamation;}
void Reclamation::setIdFournisseur(QString IdFournisseur){this->IdFournisseur=IdFournisseur;}
void Reclamation::setIdClient(QString IdClient){this->IdClient=IdClient;}
bool Reclamation::ajouter()
{

    QSqlQuery query;
         query.prepare("INSERT INTO RECLAMATIONS (ID_RECLAMATION, ID_FOURNISSEUR, ID_CLIENT) "
                       "VALUES (:id, :forename, :surname)");
         query.bindValue(":id",idReclamation);
         query.bindValue(":forename", IdFournisseur);
         query.bindValue(":surname", IdClient);
        return query.exec();

}
bool Reclamation::supprimer(QString id)
{
    QSqlQuery query;
         query.prepare(" Delete from RECLAMATIONS where ID_RECLAMATION=:id");
         query.bindValue(0, id);

        return query.exec();


}
QSqlQueryModel* Reclamation::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery("SELECT* FROM RECLAMATIONS");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_RECLAMATION"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_FOURNISSEUR"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID_CLIENT"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_RECLAMATION"));



  return  model;
}
