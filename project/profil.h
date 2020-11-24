#ifndef PROFIL_H
#define PROFIL_H

#include <QString>
#include <QSqlQueryModel>

class profil
{public:
    profil();
   profil(int,QString,QString,QString,QString,QString);
    int getid();
    QString getuser();
    QString getpass();
     QString getmail();
    QString getdateC();
    QString getrole();

    void setid(int);
    void setuser(QString);
    void setpass(QString);
    void setmail(QString);
    void setrole(QString);
    void setdateC(QString);
    bool ajouterP();
    bool modifier();
    QSqlQueryModel* afficherP();
    bool supprimerP(int);
private:
int id;
QString user,pass,datec,role,mail;


};

#endif // PROFIL_H
