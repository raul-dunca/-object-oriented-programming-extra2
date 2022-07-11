#pragma once
#include <QAbstractTableModel>
#include "Service.h"

class ProductsModel : public QAbstractTableModel
{
private:
	Service& serv;

public:
	ProductsModel(Service& s) :serv{ s }
	{

	}

	int rowCount(const QModelIndex& parent = QModelIndex()) const override
	{
		return this->serv.get_ideas_serv().size();
	}
	int columnCount(const QModelIndex& parent = QModelIndex()) const override
	{
		return 4;
	}
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override
	{
		int row = index.row();
		int col = index.column();

		Idea current = this->serv.get_ideas_serv()[row];

		if (role == Qt::EditRole || role == Qt::DisplayRole)
		{
			switch (col)
			{
			case 0:
				return QString::fromStdString(current.get_description());
			case 1:
				return QString::fromStdString(current.get_status());
			case 2:
				return QString::fromStdString(current.get_creator());
			case 3:
				return QString::fromStdString(to_string(current.get_act()));
			default:
				break;
			}
		}
		return QVariant();
	}

	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override
	{

		if (role == Qt::DisplayRole and orientation==Qt::Horizontal)
		{
			switch (section)
			{
			case 0:
				return QString::fromStdString("Description");
			case 1:
				return QString::fromStdString("Status");
			case 2:
				return QString::fromStdString("Creator");
			case 3:
				return QString::fromStdString("Act");
			default:
				break;
			}
		}
		return QVariant();
	}

	int  add_model(Idea i)
	{
		/*for (auto a : this->serv.get_ideas_serv())
		{
			if (i.get_description() == a.get_description())
			{
				
				return 0;
			}
		}*/
		int n = this->serv.get_ideas_serv().size();
		this->beginInsertRows(QModelIndex{}, n, n);
		this->serv.add_serv(i);
		this->endInsertRows();
		return 1;
	}
	int revise_model(string desc,string ow, string act)
	{
		vector<Idea> v = this->serv.get_ideas_serv();
		
		for (int i=0;i<v.size();i++)
		{
			if (desc ==v[i].get_description())
			{
				if(v[i].get_status()=="accepted")
					return 0;
				else
				{
					
					this->serv.revise_serv(desc);
					/*int n = this->serv.get_ideas_serv().size();
					this->beginRemoveRows(QModelIndex{}, i,i);
					this->serv.remove_serv(desc, act);
					this->endRemoveRows();

					
					this->beginInsertRows(QModelIndex{}, n, n);
					this->serv.add_serv(Idea{desc,"accepted",ow,stoi(act)});
					this->endInsertRows();*/
						return 1;
				}
			}
		}
		return 0;
	}
	//void clearData();
};

