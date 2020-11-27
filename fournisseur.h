#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H


#include <QString>
#include <QSqlQueryModel>
class Fournisseur
{
public:
    Fournisseur();
    Fournisseur(QString,QString,int,QString,QString);
    QString getIdFournisseur();
    void setIdFournisseur(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString);
    bool modifier(QString);
private:
    QString IdFournisseur, Nom,Region,Categorie;
    int Tel;
};


#endif // FOURNISSEUR_H
