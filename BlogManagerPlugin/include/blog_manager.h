#ifndef BLOG_MANAGER_H
#define BLOG_MANAGER_H
#include <QObject>
#include <QString>
#include "blog_service.h"
class ctkPluginContext;


// 事件发布者
class BlogManager : public QObject, public BlogService {
	Q_OBJECT
		Q_INTERFACES(BlogService)
public:
	BlogManager(ctkPluginContext* context);
	// 发布事件
	void publishBlog(const Blog& blog);
	~BlogManager();
private:
	ctkPluginContext * m_pContext;
};

#endif // BLOG_MANAGER_H