#ifndef SCREENRBT_H
#define SCREENRBT_H

#include <QDialog>
#include "RBT.h"
#include "qgraphicsscene.h"

namespace Ui {
class screenrbt;
}

class screenrbt : public QDialog
{
    Q_OBJECT

public:
    explicit screenrbt(QWidget *parent = nullptr);
    ~screenrbt();

private slots:
    void on_Insert_BST_rbt_clicked();

    void on_Clear_BST_rbt_clicked();

    void on_Delete_BST_rbt_clicked();

private:
    Ui::screenrbt *ui;
    RBT john;
};

#endif // SCREENRBT_H
