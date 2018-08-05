// hello_service.h
#ifndef HELLO_SERVICE_H
#define HELLO_SERVICE_H
#include <QDebug>
#include <QtPlugin>

class HelloService
{
public:
	virtual ~HelloService() {
	
		qDebug() << "release HelloService";
	}
	virtual void sayHello() = 0;
};

#define HelloService_iid "org.commontk.service.demos.HelloService"
Q_DECLARE_INTERFACE(HelloService, HelloService_iid)

#endif // HELLO_SERVICE_H