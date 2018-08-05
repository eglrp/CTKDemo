#include "blog_event_handler_activator.h"
#include "blog_event_handler.h"


BlogEventHandlerActivator::BlogEventHandlerActivator() {
}

BlogEventHandlerActivator::~BlogEventHandlerActivator() {
}
void BlogEventHandlerActivator::start(ctkPluginContext* context) {
	m_pEventHandler.reset(new BlogEventHandler(context));
}

void BlogEventHandlerActivator::stop(ctkPluginContext * context) {
	Q_UNUSED(context)
}
