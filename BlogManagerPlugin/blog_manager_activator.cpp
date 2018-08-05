#include "blog_manager_activator.h"
#include "blog_manager.h"

BlogManagerActivator::BlogManagerActivator() {
}

BlogManagerActivator::~BlogManagerActivator() {
}
void BlogManagerActivator::start(ctkPluginContext* context) {
	m_pBlogManager.reset(new BlogManager(context));

	//Blog blog;
	//blog.title = "CTK Event Admin";
	//blog.content = "This is a simple blog";
	//blog.author = "Waleon";

	//m_pBlogManager->publishBlog(blog);
}

void BlogManagerActivator::stop(ctkPluginContext * context) {
	Q_UNUSED(context)
}
