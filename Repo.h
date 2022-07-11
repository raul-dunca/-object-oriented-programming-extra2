#pragma once
#include "Domain.h"
#include <vector>
#include <fstream>
#include <sstream>
class Repo
{
public:
	Repo()
	{
		ifstream f("writers.txt");
		string buffer, n, e;
		while (getline(f, buffer))
		{
			stringstream ss(buffer);
			getline(ss, n, ';');
			getline(ss, e, ';');
			this->writers.push_back(Writer{ n,e });
		}

		ifstream f2("ideas.txt");
		string buffer2, d, s,c,a;
		while (getline(f2, buffer2))
		{
			stringstream sss(buffer2);
			getline(sss, d, ';');
			getline(sss, s, ';');
			getline(sss, c, ';');
			getline(sss, a, ';');
			this->ideas.push_back(Idea{ d,s,c,stoi(a)});
		}

		for(int i=0;i<this->ideas.size();i++)
			for (int j = 0; j < this->ideas.size(); j++)
			{
				if (this->ideas[i].get_act() < this->ideas[j].get_act())
					swap(this->ideas[i], this->ideas[j]);
			}


	}
	vector<Writer> get_writers()
	{
		return this->writers;
	}
	vector<Idea> get_idea()
	{
		return this->ideas;
	}
	void add_repot(Idea i)
	{
		this->ideas.push_back(i);
		for (int i = 0; i < this->ideas.size(); i++)
			for (int j = 0; j < this->ideas.size(); j++)
			{
				if (this->ideas[i].get_act() < this->ideas[j].get_act())
					swap(this->ideas[i], this->ideas[j]);
			}
	}
	void remove_repo(string d)
	{
		
		for (int i = 0; i < this->ideas.size(); i++)
			if (this->ideas[i].get_description() == d)
			{
				this->ideas.erase(this->ideas.begin() + i);
			}
		for (int i = 0; i < this->ideas.size(); i++)
			for (int j = 0; j < this->ideas.size(); j++)
			{
				if (this->ideas[i].get_act() < this->ideas[j].get_act())
					swap(this->ideas[i], this->ideas[j]);
			}
	}
	void revise_repo(string d)
	{
		for (int i = 0; i < this->ideas.size(); i++)
			if (this->ideas[i].get_description() == d)
			{
				this->ideas[i].set_status("accepted");
			}
	}

private:
	vector<Writer> writers;
	vector<Idea> ideas;
};