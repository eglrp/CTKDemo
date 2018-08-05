#include "hello_activator.h"
#include "hello_impl.h"
#include <QDebug>
void HelloActivator::start(ctkPluginContext* context) {
	qDebug() << "HelloActivator start..." << endl;
	s.reset(new HelloImpl(context));
}

void HelloActivator::stop(ctkPluginContext* context) {
	Q_UNUSED(context)
	qDebug() << "HelloActivator stop..." << endl;
	s.reset(nullptr);
}