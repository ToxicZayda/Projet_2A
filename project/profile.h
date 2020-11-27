#ifndef PROFILE_H
#define PROFILE_H


class profile
{
public:
    profile();
    profile(int,QString,QString,int,QString,int,float);
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
    QSqlQueryModel* afficher();
    bool supprimer(int);
private:
int id,cin,tele;
QString nom,prenom,date;
float salaire;
};

#endif // PROFILE_H
