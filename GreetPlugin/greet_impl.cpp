#include "greet_impl.h"
#include <ctkPluginContext.h>
#include <QtDebug>

GreetImpl::GreetImpl(ctkPluginContext* context) {
	ctkDictionary properties;
	properties.insert(ctkPluginConstants::SERVICE_RANKING, 2);
	properties.insert("name", "GreetImpl");

	context->registerService<HelloService>(this, properties);
	context->registerService<ByeService>(this);
}

void GreetImpl::sayHello() {
	qDebug() << "Greet,CTK!";
}
void GreetImpl::sayBye() {
	qDebug() << "Bye,CTK!";
}