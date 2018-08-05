// service_factory.h
#ifndef SERVICE_FACTORY_H
#define SERVICE_FACTORY_H

#include <ctkServiceFactory.h>
#include <ctkPluginConstants.h>
#include <ctkVersion.h>
#include "hello_impl.h"

class ServiceFactory : public QObject, public ctkServiceFactory
{
	Q_OBJECT
		Q_INTERFACES(ctkServiceFactory)

public:
	ServiceFactory() : m_counter(0) {}

	// �����������
	QObject* getService(QSharedPointer<ctkPlugin> plugin, ctkServiceRegistration registration) Q_DECL_OVERRIDE {
		Q_UNUSED(registration)

			qDebug() << "Create object of HelloService for: " << plugin->getSymbolicName();
		m_counter++;
		qDebug() << "Number of plugins using service: " << m_counter;

		QHash<QString, QString> headers = plugin->getHeaders();
		ctkVersion version = ctkVersion::parseVersion(headers.value(ctkPluginConstants::PLUGIN_VERSION));
		QString name = headers.value(ctkPluginConstants::PLUGIN_NAME);
		
		QObject* hello = getHello(version);
		return hello;
	}

	// �ͷŷ������
	void ungetService(QSharedPointer<ctkPlugin> plugin, ctkServiceRegistration registration, QObject* service) Q_DECL_OVERRIDE {
		Q_UNUSED(plugin)
			Q_UNUSED(registration)
			Q_UNUSED(service)
			qDebug() << "Release object of HelloService for: " << plugin->getSymbolicName()<< service;
		delete service;
		m_counter--;
		qDebug() << "Number of plugins using service: " << m_counter;
	
	}

private:
	// ���ݲ�ͬ�İ汾����ȡ��ͬ�ķ���
	QObject * getHello(ctkVersion version) {
		if (version.toString().contains("alpha")) {
			QObject * pp = new HelloWorldImpl();
			qDebug() << "new HelloWorldImpl:\t" << pp;
			return pp;
		}
		else {
			QObject * pp = new HelloCTKImpl();
			qDebug() << "new HelloCTKImpl:\t" << pp;
			return pp;
		}
	}

private:
	int m_counter;  // ������
};

#endif // SERVICE_FACTORY_H