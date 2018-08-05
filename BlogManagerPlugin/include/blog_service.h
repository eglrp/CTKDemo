#ifndef BLOG_SERVICE_H
#define BLOG_SERVICE_H

#include <QtPlugin>
typedef struct Blog_Info {
	QString title;
	QString author;
	QString content;
} Blog;
Q_DECLARE_METATYPE(Blog)
class BlogService {
public:
	virtual ~BlogService() {
		//qDebug() << "~HelloService";
	}
	virtual	void publishBlog(const Blog& blog) = 0;
};

#define BlogService_iid "org.commontk.service.demos.BlogService"
Q_DECLARE_INTERFACE(BlogService, BlogService_iid)

#endif // HELLO_SERVICE_H