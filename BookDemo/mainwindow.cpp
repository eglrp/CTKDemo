//QT
#include <QDebug>
#include <QMenuBar>
#include <QMenu>


//
#include "mainwindow.h"


MainWindow::MainWindow() {
	qDebug() << "mainwindow";
	this->createAction();
	this->createMenu();
	this->setMinimumSize(600, 450);
	this->resize(600, 450);
}

void MainWindow::createMenu(){
	QMenuBar *menuBar = this->menuBar();

	QMenu *menu = menuBar->addMenu(tr("file"));
	menu->addAction(newAcion);
	menu->addAction(openAction);
	menu->addSeparator();
	menu->addAction(exitAction);


	//QAction * action = menu->addAction(tr("file"));
}

void MainWindow::createAction(){
	newAcion = new QAction(tr("New..."));
	this->connect(newAcion, &QAction::triggered, this, &MainWindow::onNewAction);

	openAction = new QAction(tr("Open..."));
	this->connect(openAction, &QAction::triggered, this, &MainWindow::onOpenAction);

	exitAction = new QAction(tr("Exit..."));
	this->connect(exitAction, &QAction::triggered, this, &MainWindow::onExitAction);

}

void MainWindow::onOpenAction(bool checked) {
	qDebug() << "onOpenAction: " << checked;
}

void MainWindow::onExitAction(bool checked) {
	qDebug() << "onExitAction: " << checked;
	this->close();
}

void MainWindow::onNewAction(bool checked) {
	qDebug() << "onNewAction: " << checked;

}