#pragma once
#include "Repo.h"
class Service
{
public:
	Service(Repo r) :r{ r }
	{

	}
	vector<Writer> get_writers_serv()
	{
		return this->r.get_writers();
	}
	vector<Idea> get_ideas_serv()
	{
		return this->r.get_idea();
	}
	void add_serv(Idea i)
	{
		this->r.add_repot(i);
	}
	void remove_serv(string desc, string act)
	{
		this->r.remove_repo(desc);
	}
	void revise_serv(string d)
	{
		this->r.revise_repo(d);
	}

private:
	Repo r;
};