#include "pluginAImpl.h"
#include <ctkPluginContext.h>
#include <QtDebug>

PluginAImpl::PluginAImpl(ctkPluginContext* context) {
	context->registerService<PluginAService>(this);
}

void PluginAImpl::sayHello() {

}

PluginAImpl::~PluginAImpl()
{
	
}
