#ifndef PLUGINA_ACTIVATOR_H
#define PLUGINA_ACTIVATOR_H
#include <ctkPluginActivator.h>
#include "PluginAService.h"

class PluginAActivator : public QObject, public ctkPluginActivator {
	Q_OBJECT
		Q_INTERFACES(ctkPluginActivator)
		Q_PLUGIN_METADATA(IID "PLUGINA_CTK")

public:
	void start(ctkPluginContext* context);
	void stop(ctkPluginContext* context);

private:
	QScopedPointer<PluginAService> s;
};

#endif // HELLO_ACTIVATOR_H