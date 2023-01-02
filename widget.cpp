#include "widget.h"
#include "./ui_widget.h"
#include "screenbst.h"
#include "screenavl.h"
#include "screenrbt.h"
#include "QComboBox"
#include "QApplication"
#include "QComboBox"
#include "QDebug"
#include "QGraphicsView"
#include "QGraphicsScene"
#include "QGraphicsEllipseItem"
#include "QGraphicsRectItem"
#include "QPushButton"
#include <QMessageBox>
#include "QPalette"
Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget){
    ui->setupUi(this);
    //setStyleSheet("QComboBox{background-color: #aa4b6b ; color: White;}");
}

Widget::~Widget(){
    delete ui;
}


void Widget::on_Next_clicked()
{
    QString s = ui->choose->currentText();

    if(s=="BST"){
        screenBST bbb;
        bbb.setModal(free);
        bbb.setWindowTitle("Tree visualization BST");
        bbb.exec();
        qDebug () << " BST Screen  ";

    }
    if(s=="AVL"){

        screenAVL aaa;
        aaa.setModal(free);
        aaa.setWindowTitle("Tree visualization AVL");
        aaa.exec();
        qDebug () << " AVL Screen ";

    }
    if(s=="RBT"){
        screenrbt rrr;
        rrr.setModal(free);
        rrr.setWindowTitle("Tree visualization RBT");
        rrr.exec();
        qDebug () << " RBT Screen ";
    }
}





