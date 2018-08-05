#ifndef GREET_IMPL_H
#define GREET_IMPL_H

#include "greet_service.h"
#include <QObject>

class ctkPluginContext;

class GreetImpl : public QObject, public HelloService, public ByeService {
	Q_OBJECT
		Q_INTERFACES(HelloService)
		Q_INTERFACES(ByeService)

public:
	GreetImpl(ctkPluginContext* context);
	void sayHello() Q_DECL_OVERRIDE;
	void sayBye() Q_DECL_OVERRIDE;
};

#endif // GREET_IMPL_H