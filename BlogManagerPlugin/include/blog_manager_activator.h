#ifndef BLOG_MANAGER_ACTIVATOR_H
#define BLOG_MANAGER_ACTIVATOR_H

#include <ctkPluginActivator.h>
class BlogManager;

class BlogManagerActivator : public QObject, public ctkPluginActivator {
	Q_OBJECT
		Q_INTERFACES(ctkPluginActivator)
		Q_PLUGIN_METADATA(IID "BlogManagerPlugin")

public:
	BlogManagerActivator();
	~BlogManagerActivator();
	void start(ctkPluginContext* context);
	void stop(ctkPluginContext* context);

private:
	QScopedPointer<BlogManager> m_pBlogManager;
};



#endif // BLOG_MANAGER_ACTIVATOR_H