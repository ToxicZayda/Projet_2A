#ifndef DIALOG_H
#define DIALOG_H
#include "employe.h"
#include "profil.h"

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pb_ajouter_clicked();

    void on_delete_2_clicked();



    void on_pb_ajouter_profil_clicked();

    void on_bt_delete_clicked();

    void on_pb_update_clicked();

    void on_pb_updateP_clicked();

    void on_pb_find_clicked();



    void on_tri_nom_clicked();

    void on_tri_id_clicked();

    void on_tri_prenom_clicked();

    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
private:
    Ui::Dialog *ui;
    employe E;
    profil P;
};

#endif // DIALOG_H
