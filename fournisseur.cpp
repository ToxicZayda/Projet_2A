#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fournisseur.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Fournisseur::Fournisseur()
{
IdFournisseur=""; Nom="",Region="",Categorie="";
Tel=0;
}

Fournisseur::Fournisseur(QString IdFournisseur,QString Nom,int Tel,QString Region,QString Categorie)
{this->IdFournisseur=IdFournisseur; this->Nom=Nom; this->Tel=Tel;this->Region=Region;this->Categorie=Categorie;}

QString Fournisseur::getIdFournisseur(){return  IdFournisseur;}
void Fournisseur::setIdFournisseur(QString IdFournisseur){this->IdFournisseur=IdFournisseur;}

bool Fournisseur::ajouter()
{
    QSqlQuery query;
         query.prepare("INSERT INTO FOURNISSEURS (ID_FOURNISSEUR, NAME, TEL,REGION, CATEGORIE) "
                       "VALUES (:id, :name, :tel, :region, :categorie)");
         query.bindValue(":id",IdFournisseur);
         query.bindValue(":name", Nom);
         query.bindValue(":tel", Tel);
         query.bindValue(":region", Region);
         query.bindValue(":categorie", Categorie);
        return query.exec();

}

bool Fournisseur::supprimer(QString id)
{
    QSqlQuery query;
         query.prepare(" Delete from FOURNISSEURS where ID_FOURNISSEUR=:id");
         query.bindValue(0, id);
        return query.exec();
}

bool Fournisseur::modifier(QString id)
{
    QSqlQuery query;
         query.prepare(" update FOURNISSEURS set ID_FOURNISSEUR='"+IdFournisseur+"',NAME='"+Nom+"',TEL='"+Tel+"',REGION='"+Region+"',CATEGORIE='"+Categorie+"' where ID_FOURNISSEUR='"+id+"'");
         return query.exec();
}

QSqlQueryModel* Fournisseur::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();

   model->setQuery("SELECT* FROM FOURNISSEURS");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FOURNISSEUR"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("NAME"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("TEL"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("REGION"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("CATEGORIE"));

  return  model;
}
