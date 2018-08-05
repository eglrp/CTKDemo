#ifndef PLGUIN_IMPL_H
#define PLGUIN_IMPL_H

#include "PluginBService.h"
#include <QObject>

class ctkPluginContext;

class PluginBImpl : public QObject, public PluginBService {
	Q_OBJECT
		Q_INTERFACES(PluginBService)

public:
	PluginBImpl(ctkPluginContext* context);
	void sayHello() Q_DECL_OVERRIDE;
	~PluginBImpl();
};

#endif // HELLO_IMPL_H