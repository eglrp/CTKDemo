#ifndef PLUGINA_H
#define PLUGINA_H

#include <QtPlugin>
#include <QDebug>

class PluginAService {
public:
	virtual ~PluginAService() {
		qDebug() << "release PluginAService";
	}
	virtual void sayHello() = 0;
};

#define PluginAService_iid "org.commontk.service.demos.PluginAService"
Q_DECLARE_INTERFACE(PluginAService, PluginAService_iid)

#endif // HELLO_SERVICE_H