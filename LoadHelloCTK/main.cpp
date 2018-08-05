#include <QCoreApplication>
#include <QApplication>
#include <QDirIterator>
#include <QtDebug>
#include <QWidget>
//#include <QMainWindow>
//#include <QLabel>
//#include <QVBoxLayout>
//#include <QActionGroup>
//#include <QMenuBar>
#include <ctkPluginFrameworkLauncher.h>
#include <ctkPluginFrameworkFactory.h>
#include <ctkPluginException.h>
#include <ctkPluginFramework.h>
#include <ctkPluginContext.h>
#include "blog_service.h"
//#include "mainwindow.h"

//int main1(int argc, char *argv[]) {
//	QCoreApplication app(argc, argv);
//	//QApplication app(argc, argv);
//	MainWindow topLevel;
//
//	ctkPluginFrameworkFactory frameWorkFactory;
//	QSharedPointer<ctkPluginFramework> framework = frameWorkFactory.getFramework();
//	try {
//		// 初始化并启动插件框架
//		framework->init();
//		framework->start();
//		qDebug() << "CTK Plugin Framework start ...";
//	} catch (const ctkPluginException &e) {
//		qDebug() << "Failed to initialize the plugin framework: " << e.what();
//		return -1;
//	}
//
//	// 获取插件上下文
//	ctkPluginContext* context = framework->getPluginContext();
//
//	// 获取插件所在位置
//	QString path = QCoreApplication::applicationDirPath() + "/plugins";
//	qDebug() << path << endl;
//	// 遍历路径下的所有插件
//	QDirIterator itPlugin(path, QStringList() << "*.dll" << "*.so", QDir::Files);
//	while (itPlugin.hasNext()) {
//		QString strPlugin = itPlugin.next();
//		try {
//			// 安装插件
//			QSharedPointer<ctkPlugin> plugin = context->installPlugin(QUrl::fromLocalFile(strPlugin));
//			
//			qDebug() << "Plugin install ..." << plugin->getPluginId();
//
//			// 获取清单头和值
//			QHash<QString, QString> headers = plugin->getHeaders();
//			qDebug() << "Headers:" << headers << "\r\n";
//
//			// 获取符号名
//			QString symb = plugin->getSymbolicName();
//			qDebug() << "Symbolic Name:" << symb << "\r\n";
//
//			// 获取版本号
//			ctkVersion version = plugin->getVersion();
//			qDebug() << "Version:" << version.toString()
//				<< "Major:" << version.getMajor()
//				<< "Micro:" << version.getMicro()
//				<< "Minor:" << version.getMinor()
//				<< "Qualifier:" << version.getQualifier() << "\r\n";
//
//			// 启动插件
//			plugin->start(ctkPlugin::START_TRANSIENT);
//		} catch (const ctkPluginException &e) {
//			qDebug() << "Failed to install plugin" << e.what();
//			return -1;
//		}
//	}
//
//
//
//	//使用服务
//	qDebug() << "\r\n\r\nuse plugins" << endl << endl;
//	// 获取服务引用
//	/*QList<ctkServiceReference> refs = context->getServiceReferences<HelloService>("(&(name=GreetImpl))");
//	foreach(ctkServiceReference ref, refs) {
//		if (ref) {
//			qDebug() << "Name:" << ref.getProperty("name").toString()
//				<< "Service ranking:" << ref.getProperty(ctkPluginConstants::SERVICE_RANKING).toLongLong()
//				<< "Service id:" << ref.getProperty(ctkPluginConstants::SERVICE_ID).toLongLong();
//			HelloService* service = qobject_cast<HelloService *>(context->getService(ref));
//			if (service != Q_NULLPTR)
//				service->sayHello();
//		}
//	}*/
//	QMenu *tmp = NULL;
//
//	ctkServiceReference ref = context->getServiceReference<HelloService>();
//	if (ref) {
//		HelloService* service = qobject_cast<HelloService *>(context->getService(ref));
//		if (service != Q_NULLPTR) {
//			service->sayHello(tmp);
//			QMenuBar*bar = topLevel.menuBar();
//			for each (const auto & var in bar->actions())
//			{
//				for each (const auto & var3 in var->associatedWidgets())
//				{
//					qDebug() <<"associatedWidgets:\t"<< var3 << endl;
//				}
//				QMenu* menu = var->menu();
//				qDebug() << menu->title() << endl;
//				if ("&Edit" == menu->title()) {
//					menu->addMenu(tmp);
//					for each (const auto & var2 in menu->actions())
//					{
//						qDebug()<<"(associatedWidgets):\t" << var2->associatedWidgets() << endl;
//					}
//				}
//				qDebug() << var << endl;
//			}
//			bar->addMenu(tmp);
//			qDebug() << "tmp:\t" << tmp;
//		}
//	}
//	ctkServiceReference ref2 = context->getServiceReference<HelloService>();
//
//	if (ref == ref2)
//		qDebug() << "true";
//
//	topLevel.show();
//	ref.getPlugin()->stop();
//	
//	return QApplication::exec();
//}
int main2(int argc, char *argv[]) {
	//QCoreApplication app(argc, argv);
	QApplication app(argc, argv);
	QWidget w;

	// 获取插件所在位置
	QString path = QCoreApplication::applicationDirPath() + "/plugins";

	// 在插件的搜索路径列表中添加一条路径
	ctkPluginFrameworkLauncher::addSearchPath(path);

	// 设置并启动 CTK 插件框架
	try {
		qDebug() << ctkPluginFrameworkLauncher::start("org.commontk.eventadmin");
	}
	catch (const ctkRuntimeException&e) {
		qDebug() << e.what() << endl;
	}
	// 获取插件上下文
	ctkPluginContext* context = ctkPluginFrameworkLauncher::getPluginContext();

	// 启动插件 HelloCTK
	try {
		QSharedPointer<ctkPlugin> plugin = context->installPlugin(QUrl::fromLocalFile(path + "/HelloCTK.dll"));
		plugin->start();
		qDebug() << "HelloCTK start ...";
	}
	catch (const ctkPluginException &e) {
		qDebug() << "Failed to start HelloCTK" << e.what();
	}

	// 启动插件 BlogEventHandler
	try {
		QSharedPointer<ctkPlugin> plugin = context->installPlugin(QUrl::fromLocalFile(path + "/BlogHandlerPlugin.dll"));
		plugin->start();
		qDebug() << "BlogEventHandler start ...";
	}
	catch (const ctkPluginException &e) {
		qDebug() << path + "/BlogEventHandler.dll" << endl;
		qDebug() << "Failed to start BlogEventHandler" << e.what();
	}


	// 启动插件 BlogManager
	try {
		QSharedPointer<ctkPlugin> plugin = context->installPlugin(QUrl::fromLocalFile(path + "/BlogManagerPlugin.dll"));
		plugin->start();
		qDebug() << "BlogManager start ...";
	}
	catch (const ctkPluginException &e) {
		qDebug() << path + "/BlogEventHandler.dll" << endl;
		qDebug() << "Failed to start BlogManager" << e.what();
	}

	ctkServiceReference ref = context->getServiceReference<BlogService>();
	if (ref) {
		BlogService* service = qobject_cast<BlogService *>(context->getService(ref));
		if (service) {
			Blog blog;
			blog.title = "CTK Event Admin from LoadHelloCTK";
			blog.content = "This is a simple blogggggggggggggggggggg";
			blog.author = "Waleon";
			service->publishBlog(blog);
		}
	}

	// 停止插件
	w.show();
	ctkPluginFrameworkLauncher::stop();
	
	return app.exec();
}

int main3(int argc, char *argv[])
{
	//QCoreApplication app(argc, argv);
	QApplication app(argc, argv);
	QWidget w;
	ctkPluginFrameworkFactory frameWorkFactory;
	QSharedPointer<ctkPluginFramework> framework = frameWorkFactory.getFramework();
	try {
		// 初始化并启动插件框架
		framework->init();
		framework->start();
		qDebug() << "CTK Plugin Framework start ...";
	}
	catch (const ctkPluginException &e) {
		qDebug() << "Failed to initialize the plugin framework: " << e.what();
		return -1;
	}

	// 获取插件上下文
	ctkPluginContext* context = framework->getPluginContext();

	// 获取插件所在位置
	QString path = QCoreApplication::applicationDirPath() + "/plugins";

	// 遍历路径下的所有插件
	QDirIterator itPlugin(path, QStringList() << "*.dll" << "*.so", QDir::Files);
	while (itPlugin.hasNext()) {
		QString strPlugin = itPlugin.next();
		try {
			// 安装插件
			QSharedPointer<ctkPlugin> plugin = context->installPlugin(QUrl::fromLocalFile(strPlugin));
			// 启动插件
			plugin->start(ctkPlugin::START_TRANSIENT);
			qDebug() << "Plugin start ...";
		}
		catch (const ctkPluginException &e) {
			qDebug() << "Failed to install plugin" << e.what();
			return -1;
		}
	}
	ctkServiceReference ref = context->getServiceReference<BlogService>();
	if (ref) {
		BlogService* service = qobject_cast<BlogService *>(context->getService(ref));
		if (service) {
			Blog blog;
			blog.title = "CTK Event Admin from LoadHelloCTK";
			blog.content = "This is a simple blog";
			blog.author = "Waleon";

			service->publishBlog(blog);
		}
	}
	w.show();
	//framework->waitForStop(2000);
	return app.exec();
}

// main.cpp
int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);
	ctkPluginFrameworkFactory frameWorkFactory;
	QSharedPointer<ctkPluginFramework> framework = frameWorkFactory.getFramework();
	try {
		// 初始化并启动插件框架
		framework->init();
		framework->start();
		qDebug() << "CTK Plugin Framework start ...";
	}
	catch (const ctkPluginException &e) {
		qDebug() << "Failed to initialize the plugin framework: " << e.what();
		return -1;
	}

		// 获取插件上下文
		ctkPluginContext* context = framework->getPluginContext();

	// 获取插件所在位置
	QString path = QCoreApplication::applicationDirPath() + "/plugins";

	// 启动插件 Hello
	try {
		QSharedPointer<ctkPlugin> plugin = context->installPlugin(QUrl::fromLocalFile(path + "/ServiceFactory.dll"));
		plugin->start();
		qDebug() << "Hello plugin start ...";
	}
	catch (const ctkPluginException &e) {
		qDebug() << "Failed to start Hello" << e.what();
	}

	// 启动插件 A
	try {
		QSharedPointer<ctkPlugin> plugin = context->installPlugin(QUrl::fromLocalFile(path + "/PluginA.dll"));
		plugin->start();
		qDebug() << "PluginA start ...";
	}
	catch (const ctkPluginException &e) {
		qDebug() << "Failed to start PluginA" << e.what();
	}

	// 启动插件 B
	try {
		QSharedPointer<ctkPlugin> plugin = context->installPlugin(QUrl::fromLocalFile(path + "/PluginB.dll"));
		plugin->start();
		qDebug() << "PluginB start ...";
	}
	catch (const ctkPluginException &e) {
		qDebug() << "Failed to start PluginB" << e.what();
	}

	framework->stop();
	system("pause");
	return 0;
}
