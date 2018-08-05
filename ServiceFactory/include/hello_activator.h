// hello_activator.h
#ifndef HELLO_ACTIVATOR_H
#define HELLO_ACTIVATOR_H

#include <ctkPluginActivator.h>
#include <ctkPluginContext.h>
#include <QDebug>
#include "hello_service.h"
#include "service_factory.h"

class HelloActivator : public QObject, public ctkPluginActivator
{
	Q_OBJECT
		Q_INTERFACES(ctkPluginActivator)
		Q_PLUGIN_METADATA(IID "HELLO")

public:
	// 注册服务工厂
	void start(ctkPluginContext* context) {
		factory = new ServiceFactory();
		context->registerService<HelloService>(factory);
	}

	void stop(ctkPluginContext* context) {
		Q_UNUSED(context)
		qDebug() << "HelloActivator stop...";
		if (factory)
			delete factory;
	}
private:
	ServiceFactory * factory;
};

#endif // HELLO_ACTIVATOR_H