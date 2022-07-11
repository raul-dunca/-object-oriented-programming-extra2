#include "QtWidgetsClass.h"

QtWidgetsClass::QtWidgetsClass(Writer w,ProductsModel* m,QWidget *parent)
	: QWidget(parent),w{w},m{m}
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromStdString(this->w.get_name()));
	this->ui.tableView->setModel(m);
	QApplication::connect(this->ui.addIdea, &QPushButton::clicked, this, &QtWidgetsClass::add);
	QApplication::connect(this->ui.reviseButton, &QPushButton::clicked, this, &QtWidgetsClass::revise);
	
}

QtWidgetsClass::~QtWidgetsClass()
{
}
