#include "screen1bst.h"
#include "ui_screen1bst.h"

SCREEN1BST::SCREEN1BST(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SCREEN1BST)
{
    ui->setupUi(this);
}

SCREEN1BST::~SCREEN1BST()
{
    delete ui;
}
