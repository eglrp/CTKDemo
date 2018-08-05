#include "PluginAActivator.h"
#include "pluginAImpl.h"
#include <QDebug>
#include "hello_service.h"
void PluginAActivator::start(ctkPluginContext* context)
{
	s.reset(new PluginAImpl(context));
	//context->registerService<PluginAService>(m_pPlugin);

	// 第一次访问服务
	ctkServiceReference reference = context->getServiceReference<HelloService>();
	if (reference) {
		HelloService* service = qobject_cast<HelloService *>(context->getService(reference));
		if (service != Q_NULLPTR) {
			service->sayHello();
		}

		qDebug() << "The first call: " << service;
		//context->ungetService(reference);
	}

	// 第二次访问服务
	reference = context->getServiceReference<HelloService>();
	if (reference) {
		HelloService* service = qobject_cast<HelloService *>(context->getService(reference));
		if (service != Q_NULLPTR) {
			service->sayHello();
		}

		qDebug() << "The second call: " << service;
		//context->ungetService(reference);
	}
}

void PluginAActivator::stop(ctkPluginContext * context)
{
	qDebug() << "PluginAActivator stop...";
	s.reset(nullptr);
}
