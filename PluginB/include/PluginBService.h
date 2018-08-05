#ifndef PLUGINB_H
#define PLUGINB_H

#include <QtPlugin>
#include <QDebug>
class PluginBService {
public:
	virtual ~PluginBService() {
		qDebug() << "release PluginBService";
	}
	virtual void sayHello() = 0;
};

#define PluginBService_iid "org.commontk.service.demos.PluginBService"
Q_DECLARE_INTERFACE(PluginBService, PluginBService_iid)

#endif // HELLO_SERVICE_H