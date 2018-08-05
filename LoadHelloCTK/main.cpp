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
//		// ��ʼ��������������
//		framework->init();
//		framework->start();
//		qDebug() << "CTK Plugin Framework start ...";
//	} catch (const ctkPluginException &e) {
//		qDebug() << "Failed to initialize the plugin framework: " << e.what();
//		return -1;
//	}
//
//	// ��ȡ���������
//	ctkPluginContext* context = framework->getPluginContext();
//
//	// ��ȡ�������λ��
//	QString path = QCoreApplication::applicationDirPath() + "/plugins";
//	qDebug() << path << endl;
//	// ����·���µ����в��
//	QDirIterator itPlugin(path, QStringList() << "*.dll" << "*.so", QDir::Files);
//	while (itPlugin.hasNext()) {
//		QString strPlugin = itPlugin.next();
//		try {
//			// ��װ���
//			QSharedPointer<ctkPlugin> plugin = context->installPlugin(QUrl::fromLocalFile(strPlugin));
//			
//			qDebug() << "Plugin install ..." << plugin->getPluginId();
//
//			// ��ȡ�嵥ͷ��ֵ
//			QHash<QString, QString> headers = plugin->getHeaders();
//			qDebug() << "Headers:" << headers << "\r\n";
//
//			// ��ȡ������
//			QString symb = plugin->getSymbolicName();
//			qDebug() << "Symbolic Name:" << symb << "\r\n";
//
//			// ��ȡ�汾��
//			ctkVersion version = plugin->getVersion();
//			qDebug() << "Version:" << version.toString()
//				<< "Major:" << version.getMajor()
//				<< "Micro:" << version.getMicro()
//				<< "Minor:" << version.getMinor()
//				<< "Qualifier:" << version.getQualifier() << "\r\n";
//
//			// �������
//			plugin->start(ctkPlugin::START_TRANSIENT);
//		} catch (const ctkPluginException &e) {
//			qDebug() << "Failed to install plugin" << e.what();
//			return -1;
//		}
//	}
//
//
//
//	//ʹ�÷���
//	qDebug() << "\r\n\r\nuse plugins" << endl << endl;
//	// ��ȡ��������
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

	// ��ȡ�������λ��
	QString path = QCoreApplication::applicationDirPath() + "/plugins";

	// �ڲ��������·���б������һ��·��
	ctkPluginFrameworkLauncher::addSearchPath(path);

	// ���ò����� CTK ������
	try {
		qDebug() << ctkPluginFrameworkLauncher::start("org.commontk.eventadmin");
	}
	catch (const ctkRuntimeException&e) {
		qDebug() << e.what() << endl;
	}
	// ��ȡ���������
	ctkPluginContext* context = ctkPluginFrameworkLauncher::getPluginContext();

	// ������� HelloCTK
	try {
		QSharedPointer<ctkPlugin> plugin = context->installPlugin(QUrl::fromLocalFile(path + "/HelloCTK.dll"));
		plugin->start();
		qDebug() << "HelloCTK start ...";
	}
	catch (const ctkPluginException &e) {
		qDebug() << "Failed to start HelloCTK" << e.what();
	}

	// ������� BlogEventHandler
	try {
		QSharedPointer<ctkPlugin> plugin = context->installPlugin(QUrl::fromLocalFile(path + "/BlogHandlerPlugin.dll"));
		plugin->start();
		qDebug() << "BlogEventHandler start ...";
	}
	catch (const ctkPluginException &e) {
		qDebug() << path + "/BlogEventHandler.dll" << endl;
		qDebug() << "Failed to start BlogEventHandler" << e.what();
	}


	// ������� BlogManager
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

	// ֹͣ���
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
		// ��ʼ��������������
		framework->init();
		framework->start();
		qDebug() << "CTK Plugin Framework start ...";
	}
	catch (const ctkPluginException &e) {
		qDebug() << "Failed to initialize the plugin framework: " << e.what();
		return -1;
	}

	// ��ȡ���������
	ctkPluginContext* context = framework->getPluginContext();

	// ��ȡ�������λ��
	QString path = QCoreApplication::applicationDirPath() + "/plugins";

	// ����·���µ����в��
	QDirIterator itPlugin(path, QStringList() << "*.dll" << "*.so", QDir::Files);
	while (itPlugin.hasNext()) {
		QString strPlugin = itPlugin.next();
		try {
			// ��װ���
			QSharedPointer<ctkPlugin> plugin = context->installPlugin(QUrl::fromLocalFile(strPlugin));
			// �������
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
		// ��ʼ��������������
		framework->init();
		framework->start();
		qDebug() << "CTK Plugin Framework start ...";
	}
	catch (const ctkPluginException &e) {
		qDebug() << "Failed to initialize the plugin framework: " << e.what();
		return -1;
	}

		// ��ȡ���������
		ctkPluginContext* context = framework->getPluginContext();

	// ��ȡ�������λ��
	QString path = QCoreApplication::applicationDirPath() + "/plugins";

	// ������� Hello
	try {
		QSharedPointer<ctkPlugin> plugin = context->installPlugin(QUrl::fromLocalFile(path + "/ServiceFactory.dll"));
		plugin->start();
		qDebug() << "Hello plugin start ...";
	}
	catch (const ctkPluginException &e) {
		qDebug() << "Failed to start Hello" << e.what();
	}

	// ������� A
	try {
		QSharedPointer<ctkPlugin> plugin = context->installPlugin(QUrl::fromLocalFile(path + "/PluginA.dll"));
		plugin->start();
		qDebug() << "PluginA start ...";
	}
	catch (const ctkPluginException &e) {
		qDebug() << "Failed to start PluginA" << e.what();
	}

	// ������� B
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
