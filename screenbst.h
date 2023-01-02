#ifndef SCREENBST_H
#define SCREENBST_H

#include <QDialog>
#include "BST.h"
#include "qgraphicsscene.h"

namespace Ui {
class screenBST;
}

class screenBST : public QDialog
{
    Q_OBJECT

public:
    explicit screenBST(QWidget *parent = nullptr);
    ~screenBST();

private slots:

    void on_Insert_BST_clicked();

    void on_Delete_BST_clicked();

    void on_Clear_BST_clicked();

private:
    Ui::screenBST *ui;
    BST mina;
};

#endif // SCREENBST_H
