//std
#include <iostream>

//QT
#include <QApplication>
#include <QWidget>


//
#include "mainwindow.h"


int main(int argc, char *argv[]) {
	QApplication app(argc, argv);


	MainWindow m;
	m.show();

	QApplication::exec();
}
