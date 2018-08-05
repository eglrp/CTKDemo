#ifndef HELLO_SERVICE_H
#define HELLO_SERVICE_H

#include <QtPlugin>
#include <QMenu>

class HelloService {
public:
	virtual ~HelloService() {
		//qDebug() << "~HelloService";
	}
	virtual void sayHello(QMenu*&) = 0;
};

#define HelloService_iid "org.commontk.service.demos.HelloService"
Q_DECLARE_INTERFACE(HelloService, HelloService_iid)

#endif // HELLO_SERVICE_H