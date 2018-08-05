#include "greet_activator.h"
#include "greet_impl.h"

void GreetActivator::start(ctkPluginContext* context)
{
	m_pImpl.reset(new GreetImpl(context));

}

void GreetActivator::stop(ctkPluginContext* context) {
	Q_UNUSED(context)
}
