#include "screenrbt.h"
#include "ui_screenrbt.h"
#include <QApplication>
#include "QComboBox"
#include "QDebug"
#include "QGraphicsView"
#include "QGraphicsScene"
#include "QGraphicsEllipseItem"
#include "QGraphicsRectItem"
#include "QPushButton"
#include <QMessageBox>
#include "RBT.h"
#include "QLineEdit"



void drawTree(QGraphicsScene& scene,RBT::Node* root, qreal x, qreal y, qreal hstep)
{
    if (!root) return;

    // Draw the node
    qreal radius = 20;
    QGraphicsEllipseItem* node = new QGraphicsEllipseItem(x - radius, y - radius, 2 * radius, 2 * radius);
    node->setBrush(QBrush(Qt::white));
    if (root->color==0)
        node->setBrush(QBrush(Qt::red));
    else{node->setBrush(QBrush(Qt::gray));}
    node->topLevelWidget();
    scene.addItem(node);

    // Draw the value
    QGraphicsSimpleTextItem* text = new QGraphicsSimpleTextItem(QString::number(root->data));
    text->setPos(x - text->boundingRect().width() / 2, y - text->boundingRect().height() / 2);
    scene.addItem(text);

    // Calculate the positions of the children
    qreal ystep = 50;
    qreal x1 = x - hstep;
    qreal y1 = y + ystep;
    qreal x2 = x + hstep;
    qreal y2 = y + ystep;

    // Draw the left child
    drawTree(scene, root->left, x1, y1, hstep / 2);

    // Draw the right child
    drawTree(scene, root->right, x2, y2, hstep / 2);

    // Draw the lines connecting the parent and the children
    if (root->left) {
        QGraphicsLineItem* line = new QGraphicsLineItem(x, y + radius, x1, y1 - radius);
        scene.addItem(line);
    }
    if (root->right) {
        QGraphicsLineItem* line = new QGraphicsLineItem(x, y + radius, x2, y2 - radius);
        scene.addItem(line);
    }
}

screenrbt::screenrbt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::screenrbt)
{
    ui->setupUi(this);

}

screenrbt::~screenrbt()
{
    delete ui;
}

void screenrbt::on_Insert_BST_rbt_clicked()
{   QLineEdit*lnnn=new QLineEdit;
    if(!lnnn) {
        qDebug () << " Field is empty ";

    } else {
         qDebug () << " Number Deleted : " << ui->LEinsertRBt->text().toInt();
         int num = ui->LEinsertRBt->text().toInt();
         john.insertValue(num);

         QGraphicsScene * scene = new QGraphicsScene (this);
         drawTree(*scene, john.root, 400, 20, 200);

         ui->graphicsViewBST->setScene(scene);
    }


}

void screenrbt::on_Clear_BST_rbt_clicked()
{  john.clear();
    QGraphicsScene * scene = new QGraphicsScene (this);
    drawTree(*scene, john.root, 400, 20, 200);
    ui->graphicsViewBST->setScene(scene);

}

void screenrbt::on_Delete_BST_rbt_clicked()
{
    QLineEdit*lnnn=new QLineEdit;
         if(!lnnn) {
             qDebug () << " Field is empty ";

         } else {
              qDebug () << " Number inserted : " << ui->LEdeleRBT->text().toInt();
              int num = ui->LEdeleRBT->text().toInt();
              john.deleteValue(num);

              QGraphicsScene * scene = new QGraphicsScene (this);
              drawTree(*scene, john.root, 400, 20, 200);
              ui->graphicsViewBST->setScene(scene);
         }
}

