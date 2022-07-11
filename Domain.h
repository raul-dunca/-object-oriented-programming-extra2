#pragma once
#include <string>
using namespace std;
class Writer
{
public:
	Writer(string n, string e) :name{ n }, expertise{ e }
	{

	}
	string get_name()
	{
		return this->name;
	}
	string get_expertise()
	{
		return this->expertise;
	}

private:
	string name;
	string expertise;
};

class Idea
{
public:
	Idea(string d, string s, string c, int a) : description{ d }, status{ s }, creator{ c }, act{ a }
	{

	}
	string get_description()
	{
		return this->description;
	}
	string get_status()
	{
		return this->status;
	}
	string get_creator()
	{
		return this->creator;
	}
	int get_act()
	{
		return this->act;
	}
	void set_status(string news)
	{
		this->status = news;
	}

private:
	string description;
	string status;
	string creator;
	int act;
};