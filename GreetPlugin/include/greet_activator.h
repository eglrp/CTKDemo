#ifndef HELLO_ACTIVATOR_H
#define HELLO_ACTIVATOR_H

#include <ctkPluginActivator.h>
class GreetImpl;
class GreetActivator : public QObject, public ctkPluginActivator {
	Q_OBJECT
		Q_INTERFACES(ctkPluginActivator)
		Q_PLUGIN_METADATA(IID "GreetPlugin")

public:
	void start(ctkPluginContext* context);
	void stop(ctkPluginContext* context);

private:
	QScopedPointer<GreetImpl> m_pImpl;
};



#endif // HELLO_ACTIVATOR_H