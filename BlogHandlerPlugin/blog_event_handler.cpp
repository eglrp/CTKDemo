#include "blog_event_handler.h"
#include "service\event\ctkEventConstants.h"
#include <ctkPluginContext.h>



BlogEventHandler::BlogEventHandler(ctkPluginContext* context) {
	ctkDictionary props;
	props[ctkEventConstants::EVENT_TOPIC] = "org/commontk/bloggenerator/published";
	props[ctkEventConstants::EVENT_FILTER] = "(author=Waleon)";
	context->registerService<ctkEventHandler>(this, props);
}


void BlogEventHandler::handleEvent(const ctkEvent& event)  {
	QString title = event.getProperty("title").toString();
	QString content = event.getProperty("content").toString();
	QString author = event.getProperty("author").toString();
	qDebug() << "EventHandler received the message, topic:" << event.getTopic()
		<< "properties:" << "title:" << title << "content:" << content << "author:" << author;
}