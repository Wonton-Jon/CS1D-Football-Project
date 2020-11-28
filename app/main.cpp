#include "mainwindow.h"
#include "Dijkstra.h"
#include "kruskals.h"
#include <QApplication>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication a(argc, argv);
    MainWindow w;
   // testDijkstra();
	kruskals g(100);
	g.readDb("SoFi Stadium");

	qDebug() << "***************pre solve*****************\n";
	g.solve();
	g.print();
	qDebug() << "***************Print*****************\n";


    w.show();
    return a.exec();
}
