#pragma once

#include <QWidget>
#include "ui_QtWidgetsClass.h"
#include "Model.h"
#include <QMessageBox>
class QtWidgetsClass : public QWidget
{
	Q_OBJECT

public:
	QtWidgetsClass(Writer w,ProductsModel* m,QWidget *parent = Q_NULLPTR);
	~QtWidgetsClass();
	void add()
	{

		string s1 = (this->ui.desciptionEdit->text()).toStdString();
		string s2= (this->ui.actEdit->text()).toStdString();
		if (s1 == "" or (s2!="1" and s2!="2" and s2 != "3"))
		{
			QMessageBox m;
			m.critical(0, "Error", "Please give the right input");
			m.setFixedSize(500, 200);
			return;
		}
		else
		{
			int k;
			k=this->m->add_model(Idea{s1,"proposed",this->w.get_name(),stoi(s2)});
			if (k == 0)
			{
				QMessageBox m;
				m.critical(0, "Error", "Cant have 2 ideas with same description!");
				m.setFixedSize(500, 200);
			}
		}
	
	}
	void revise()
	{
		if (this->w.get_expertise() != "Senior")
		{
			QMessageBox m;
			m.critical(0, "Error", "You are not a Senio!!");
			m.setFixedSize(500, 200); 
			return;
		}
		else
		{
			string s1 = (this->ui.desciptionEdit->text()).toStdString();
			string s2 = (this->ui.actEdit->text()).toStdString();
			int k;
			k = this->m->revise_model(s1,s2,this->w.get_name());
			if (k == 0)
			{
				QMessageBox m;
				m.critical(0, "Error", "Something went wrong!");
				m.setFixedSize(500, 200);
				return;
			}
			
		}
	}
private:
	Ui::QtWidgetsClass ui;
	Writer w;
	ProductsModel* m;
};
