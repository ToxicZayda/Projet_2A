#include "employe.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include<vector>
employe::employe()
{
}
employe::employe(int id,QString nom,QString prenom,int cin,QString date,int tele,float salaire)
{

    this->id=id; this->nom=nom; this->prenom=prenom;this->cin=cin;this->date=date;this->tele=tele;
    this->salaire=salaire;
}
    int employe::getid(){return id;}
    QString employe::getnom(){return  nom;}
    QString employe::getprenom(){return prenom;}
    int employe::getcin(){return cin;}
    QString employe::getdate(){return date;}
    int employe::gettele(){return tele;}
    float employe::getsalaire(){return salaire;}
    void employe::setid(int id){this->id=id;}
    void employe::setnom(QString nom){this->nom=nom;}
    void employe::setprenom(QString prenom){this->prenom=prenom;}
    void employe::setcin(int cin){this->cin=cin;}
    void employe::setdate(QString date){this->date=date;}
void employe::settele(int tele){this->tele=tele;}
void employe::setsalaire(float salaire){this->salaire=salaire;}
    bool employe::ajouter()
    {

        QSqlQuery query;
      QString id_string= QString::number(id);
      QString cin_string= QString::number(cin);
      QString tele_string= QString::number(tele);
      QString sal_string= QString::number(salaire);
QString date_string= QString::number(salaire);
             query.prepare("INSERT INTO employe (id, nom, prenom, cin, date_naissance,telephone,salaire) "
                           "VALUES (:id, :nom, :prenom,:cin, :date_naissance,:telephone,:salaire)");
             query.bindValue(":id",id_string);
             query.bindValue(":nom", nom);
             query.bindValue(":prenom", prenom);
             query.bindValue(":cin",cin_string);
             query.bindValue(":date_naissance",date);
             query.bindValue(":telephone",tele_string);
             query.bindValue(":salaire",sal_string);
            return query.exec();






    }
    bool employe::supprimer(int id)
    {
        QSqlQuery query;
             query.prepare(" Delete from employe where id=:id");
             query.bindValue(0, id);

            return query.exec();


    }
    QSqlQueryModel* employe::afficher()
    {
      QSqlQueryModel* model=new QSqlQueryModel();

       model->setQuery("SELECT* FROM employe");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_naissance"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("telephone"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("salaire"));


      return  model;




}

    bool employe::modifier()
    {

      QSqlQuery query;
      QString id_string= QString::number(id);
      QString cin_string= QString::number(cin);
      QString tele_string= QString::number(tele);
      QString sal_string= QString::number(salaire);

             query.prepare(" UPDATE employe SET  nom=:nom, prenom=:prenom, cin=:cin, date_naissance=:date_naissance,telephone=:telephone,salaire=:salaire  WHERE id=:id ");
              query.bindValue(":id", id_string);


             query.bindValue(":nom", nom);
             query.bindValue(":prenom", prenom);
             query.bindValue(":cin",cin_string);
             query.bindValue(":date_naissance",date);
             query.bindValue(":telephone",tele_string);
             query.bindValue(":salaire",sal_string);
            return query.exec();

    }
    QSqlQueryModel* employe::recherche_id(int id,int cin,int tele)
    {
      QSqlQueryModel* model=new QSqlQueryModel();
QSqlQuery query;
  QString id_string= QString::number(id);
  QString cin_string= QString::number(cin);
  QString tele_string= QString::number(tele);

       model->setQuery("SELECT * FROM employe WHERE id='"+id_string+ "'or cin ='"+cin_string+"'or telephone='"+tele_string+ "'");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_naissance"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("telephone"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("salaire"));

query.exec();
      return  model;




}
 QSqlQueryModel* employe::trier_n()
 {


     QSqlQueryModel* model=new QSqlQueryModel();


      model->setQuery("SELECT * FROM employe ORDER BY nom ");


      model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_naissance"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("telephone"));
      model->setHeaderData(6, Qt::Horizontal, QObject::tr("salaire"));


     return  model;



 }
 QSqlQueryModel* employe::trier_i()
 {


     QSqlQueryModel* model=new QSqlQueryModel();


      model->setQuery("SELECT * FROM employe ORDER BY id ");


      model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_naissance"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("telephone"));
      model->setHeaderData(6, Qt::Horizontal, QObject::tr("salaire"));


     return  model;



 }
 QSqlQueryModel* employe::trier_p()
 {


     QSqlQueryModel* model=new QSqlQueryModel();


      model->setQuery("SELECT * FROM employe ORDER BY prenom ");


      model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_naissance"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("telephone"));
      model->setHeaderData(6, Qt::Horizontal, QObject::tr("salaire"));


     return  model;



 }
QVector<QString> employe::stat()
{
    QSqlQuery q1,q2,q3,q4,q5;
double rows,s1,s2,s3,s4;
rows=0;s2=0;s3=0;s4=0;s1=0;

   q1.prepare("SELECT count (*)  from employe  " );

                   q1.exec();
                    if (q1.next()) {
                    rows= q1.value(0).toInt();}
      q2.prepare("SELECT count (*)  from employe where salaire  between 0 and 500 " );

                                    q2.exec();
                                     if (q2.next()) {
                                    s1= q2.value(0).toInt();}
  q3.prepare("SELECT count (*)  from employe where salaire between 500 and 1000 " );

                                          q3.exec();
                                             if (q3.next()) {
                                            s2= q3.value(0).toInt();}
   q4.prepare("SELECT count (*)  from employe where salaire between 1000 and 2000 " );

                                                                                     q4.exec();
                                                                                        if (q4.next()) {
                                                                                       s3= q4.value(0).toInt();}
   q5.prepare("SELECT count (*)  from employe where salaire > 2000  " );

                                       q5.exec();
                             if (q5.next()) {
                           s4= q5.value(0).toInt();}

QVector<QString>stats;
QString a1 = QString::number((s1/rows)*100);
QString a2 = QString::number((s2/rows)*100);
QString a3 = QString::number((s3/rows)*100);
QString a4 = QString::number((s4/rows)*100);
a1+="%";
a2+="%";
a3+="%";
a4+="%";
stats.push_back(a1);
stats.push_back(a2);
stats.push_back(a3);
stats.push_back(a4);

return stats;
}
