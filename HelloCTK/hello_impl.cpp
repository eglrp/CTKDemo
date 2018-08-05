#include "hello_impl.h"
#include <ctkPluginContext.h>
#include <QtDebug>
#include <QMenu>
#include <QMessageBox>

HelloImpl::HelloImpl(ctkPluginContext* context) {
	ctkDictionary properties;
	properties.insert(ctkPluginConstants::SERVICE_RANKING, 2);
	properties.insert("name", "HelloImpl");

	context->registerService<HelloService>(this, properties);
}

void HelloImpl::sayHello(QMenu*&m) {
	menu = new QMenu(tr("Plugin Menu"));
	menu->addAction(tr("fun 1"), []() {
		qDebug() << "action fun 1";
		QMessageBox::critical(nullptr, tr("Plugin Menu"), tr("fun 1"), QMessageBox::Ok, QMessageBox::Cancel,QMessageBox::Button::Close);
	});
	menu->addAction(tr("fun 2"), []() {
		qDebug() << "action fun 2";
	});
	menu->addAction(tr("fun 3"), []() {
		qDebug() << "action fun 3";
	});
	m = menu;
	qDebug() <<"Menu:\t"<< m;
	qDebug() << "Hello,CTK!";
}

HelloImpl::~HelloImpl()
{
	if (menu) {
		qDebug() << "delete menu";
		delete menu;
	}
}
