#include <QApplication>
#include <QFormLayout>
#include <QVBoxLayout>

#include <ctkCheckablePushButton.h>
#include <ctkCollapsibleButton.h>
#include <ctkColorPickerButton.h>
#include <ctkRangeWidget.h>

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);

	// ���۵���ť
	ctkCollapsibleButton* buttons = new ctkCollapsibleButton("Buttons");

	// �ɹ�ѡ��ť
	ctkCheckablePushButton* checkablePushButton = new ctkCheckablePushButton();
	checkablePushButton->setText("Checkable");

	// ��ɫʰȡ��
	ctkColorPickerButton* colorPickerButton = new ctkColorPickerButton();
	colorPickerButton->setColor(QColor("#9e1414"));

	ctkCollapsibleButton* sliders = new ctkCollapsibleButton("Sliders");

	QFormLayout* buttonsLayout = new QFormLayout;
	buttonsLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
	buttonsLayout->addRow("ctkCheckablePushButton", checkablePushButton);
	buttonsLayout->addRow("ctkColorPickerButton", colorPickerButton);
	buttons->setLayout(buttonsLayout);

	QVBoxLayout* topLevelLayout = new QVBoxLayout();
	topLevelLayout->addWidget(buttons);
	topLevelLayout->addWidget(sliders);

	QFormLayout* slidersLayout = new QFormLayout;
	ctkRangeWidget* rangeWidget = new ctkRangeWidget();
	slidersLayout->addRow("ctkRangeWidget", rangeWidget);
	sliders->setLayout(slidersLayout);

	QWidget topLevel;
	topLevel.setLayout(topLevelLayout);
	topLevel.show();

	return app.exec();
}