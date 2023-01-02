#include "screenavl.h"
#include "ui_screenavl.h"
#include "QGraphicsView"
#include "QGraphicsScene"
#include "QGraphicsEllipseItem"
#include "QGraphicsRectItem"
#include "QPushButton"
#include <QMessageBox>
#include <Qdebug>
#include "QLineEdit"
#include "QComboBox"
#include "AVL.h"



void drawTree(QGraphicsScene& scene,AVL::AVLNode* root, qreal x, qreal y, qreal hstep)
{
    if (!root) return;

    // Draw the node
    qreal radius = 20;
    QGraphicsEllipseItem* node = new QGraphicsEllipseItem(x - radius, y - radius, 2 * radius, 2 * radius);
    node->setBrush(QBrush(Qt::white));
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

screenAVL::screenAVL(QWidget *parent) :
    QDialog(parent), ui(new Ui::screenAVL) {
    ui->setupUi(this);
}

screenAVL::~screenAVL() {
    delete ui;
}

void screenAVL::on_Insert_Avl_clicked() {
    QLineEdit*lnn=new QLineEdit;
       if(!lnn) {
           qDebug () << " Field is empty ";

       } else {
            qDebug () << " Number inserted : " << ui->lineEdit->text().toInt();
            int num = ui->lineEdit->text().toInt();
            salma.insert(num);

            QGraphicsScene * scene = new QGraphicsScene (this);
            drawTree(*scene, salma.root, 400, 20, 200);
            ui->graphicsView->setScene(scene);
       }
}

void screenAVL::on_Delete_AVl_clicked() {
    QLineEdit*lnn=new QLineEdit;
       if(!lnn) {
           qDebug () << " Field is empty ";

       } else {
            qDebug () << " Number Delete : " << ui->lineEdit_2->text().toInt();
            int num = ui->lineEdit_2->text().toInt();
            salma.remove(num);

            QGraphicsScene * scene = new QGraphicsScene (this);
            drawTree(*scene, salma.root, 400, 20, 200);
            ui->graphicsView->setScene(scene);
       }
}

void screenAVL::on_Clear_Avl_clicked() {
         salma.clear();
         QGraphicsScene * scene = new QGraphicsScene (this);
         drawTree(*scene, salma.root, 400, 20, 200);
         ui->graphicsView->setScene(scene);
}


