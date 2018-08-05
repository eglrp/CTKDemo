#ifndef MAINWINDOW_H
#define MAINWINDOW_H


//QT
#include <QMainwindow>
#include <QAction>

class MainWindow : public QMainWindow {

	Q_OBJECT
public:
	MainWindow();
private:
	void createMenu();
	void createAction();

private slots:
	void onNewAction(bool checked);
	void onOpenAction(bool checked);
	void onExitAction(bool checked);
private:
	QAction *newAcion;
	QAction *openAction;
	QAction *exitAction;
};

#endif // MAINWINDOW_H
