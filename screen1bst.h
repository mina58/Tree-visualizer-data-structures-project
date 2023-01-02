#ifndef SCREEN1BST_H
#define SCREEN1BST_H

#include <QDialog>

namespace Ui {
class SCREEN1BST;
}

class SCREEN1BST : public QDialog
{
    Q_OBJECT

public:
    explicit SCREEN1BST(QWidget *parent = nullptr);
    ~SCREEN1BST();

private:
    Ui::SCREEN1BST *ui;
};

#endif // SCREEN1BST_H
