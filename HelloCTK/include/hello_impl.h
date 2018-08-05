#ifndef HELLO_IMPL_H
#define HELLO_IMPL_H

#include "hello_service.h"
#include <QObject>

class ctkPluginContext;

class HelloImpl : public QObject, public HelloService {
	Q_OBJECT
		Q_INTERFACES(HelloService)

public:
	HelloImpl(ctkPluginContext* context);
	void sayHello(QMenu*&) Q_DECL_OVERRIDE;
	~HelloImpl();
private:
	QMenu * menu = nullptr;
};

#endif // HELLO_IMPL_H