#include "PluginBActivator.h"
#include "PluginBImpl.h"
#include "hello_service.h"
#include <QDebug>
void PluginBActivator::start(ctkPluginContext* context)
{
	s.reset(new PluginBImpl(context));

	// ·ÃÎÊ·þÎñ
	ctkServiceReference reference = context->getServiceReference<HelloService>();
	if (reference) {
		HelloService* service = qobject_cast<HelloService *>(context->getService(reference));
		if (service != Q_NULLPTR) {
			service->sayHello();
		}
	}
}

void PluginBActivator::stop(ctkPluginContext * context)
{
	qDebug() << "PluginBActivator stop...";
	s.reset(nullptr);
}
