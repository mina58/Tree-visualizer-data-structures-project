#ifndef SCREENAVL_H
#define SCREENAVL_H

#include "AVL.h"
#include "qgraphicsscene.h"
#include <QDialog>

namespace Ui {
class screenAVL;
}

class screenAVL : public QDialog
{
    Q_OBJECT

public:
    explicit screenAVL(QWidget *parent = nullptr);
    ~screenAVL();

private slots:
    void on_Insert_Avl_clicked();

    void on_Delete_AVl_clicked();

    void on_Clear_Avl_clicked();

private:
    Ui::screenAVL *ui;
    AVL salma;
};

#endif // SCREENAVL_H
