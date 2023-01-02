#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyleSheet("QPushButton{background-color: #6b6b83 ; color: White;}");

    Widget w;
    w.setWindowTitle("Tree visualization");
    w.show();
    return a.exec();
}
