#ifndef BLOG_EVENT_HANDLER_H
#define BLOG_EVENT_HANDLER_H
#include <service/event/ctkEventHandler.h>

class ctkPluginContext;
// 事件处理程序（或订阅者）
class BlogEventHandler : public QObject, public ctkEventHandler {
	Q_OBJECT
		Q_INTERFACES(ctkEventHandler)

public:
	BlogEventHandler(ctkPluginContext* context);

	// 处理事件
	void handleEvent(const ctkEvent& event) Q_DECL_OVERRIDE;
};


#endif // BLOG_EVENT_HANDLER_H
