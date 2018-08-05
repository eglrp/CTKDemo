#ifndef PLUGINB_ACTIVATOR_H
#define PLUGINB_ACTIVATOR_H
#include <ctkPluginActivator.h>
#include "PluginBService.h"

class PluginBActivator : public QObject, public ctkPluginActivator {
	Q_OBJECT
		Q_INTERFACES(ctkPluginActivator)
		Q_PLUGIN_METADATA(IID "PLUGINB_CTK")

public:
	void start(ctkPluginContext* context);
	void stop(ctkPluginContext* context);

private:
	QScopedPointer<PluginBService> s;
};

#endif // HELLO_ACTIVATOR_H