#ifndef PLGUIN_IMPL_H
#define PLGUIN_IMPL_H

#include "PluginAService.h"
#include <QObject>

class ctkPluginContext;

class PluginAImpl : public QObject, public PluginAService {
	Q_OBJECT
		Q_INTERFACES(PluginAService)

public:
	PluginAImpl(ctkPluginContext* context);
	void sayHello() Q_DECL_OVERRIDE;
	~PluginAImpl();
};

#endif // HELLO_IMPL_H