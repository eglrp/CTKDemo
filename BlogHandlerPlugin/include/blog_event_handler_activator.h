#ifndef BLOG_EVENT_HANDLER_ACTIVATOR_H
#define BLOG_EVENT_HANDLER_ACTIVATOR_H
#include <ctkPluginActivator.h>
class BlogEventHandler;
class BlogEventHandlerActivator : public QObject, public ctkPluginActivator {
	Q_OBJECT
		Q_INTERFACES(ctkPluginActivator)
		Q_PLUGIN_METADATA(IID "BlogHandlerPlugin")

public:
	BlogEventHandlerActivator();
	~BlogEventHandlerActivator();
	void start(ctkPluginContext* context);
	void stop(ctkPluginContext* context);

private:
	QScopedPointer<BlogEventHandler> m_pEventHandler;
};



#endif // BLOG_EVENT_HANDLER_ACTIVATOR_H