#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQueryModel>
#include <QDate>
#include<vector>
class employe
{
public:
    employe();
    employe(int,QString,QString,int,QString,int,float);
    int getid();
    QString getnom();
    QString getprenom();
    int getcin();
    QString getdate();
    int gettele();
    float getsalaire();
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void setcin(int);
    void setdate(QString);
    void settele(int);
    void setsalaire(float);
    bool ajouter();
    bool modifier();
    QSqlQueryModel* trier_n();
     QSqlQueryModel* trier_i();
       QSqlQueryModel* trier_p();
   QSqlQueryModel* recherche_id(int,int,int);
    QSqlQueryModel* afficher();
    bool supprimer(int);
  QVector<QString> stat();
private:
int id,cin,tele;
QString nom,prenom,date;

float salaire;}
;
#endif // EMPLOYE_H
