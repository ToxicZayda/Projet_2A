#ifndef RECLAMATION_H
#define RECLAMATION_H

#include <QString>
#include <QSqlQueryModel>
class Reclamation
{
public:
    Reclamation();
    Reclamation(QString,QString,QString);
    QString getIdReclamation();
    QString getIdFournisseur();
    QString getIdClient();
    void setIdReclamation(QString);
    void setIdFournisseur(QString);
    void setIdClient(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString);
private:
    QString IdFournisseur, IdClient,idReclamation;
};


#endif // RECLAMATION_H
