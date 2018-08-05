#include "pluginBImpl.h"
#include <ctkPluginContext.h>
#include <QtDebug>

PluginBImpl::PluginBImpl(ctkPluginContext* context) {
	context->registerService<PluginBService>(this);
}

void PluginBImpl::sayHello() {

}

PluginBImpl::~PluginBImpl()
{

}
