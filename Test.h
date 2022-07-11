#pragma once
#include "Repo.h"
#include <cassert>
void test()
{
	Repo r;
	assert(r.get_idea().size() == 3);
	r.add_repot(Idea{ "d","proposed","c",3 });
	assert(r.get_idea().size() == 4);
	assert(r.get_idea()[3].get_description() == "d");
	assert(r.get_idea()[3].get_status() == "proposed");
	r.revise_repo("d");
	assert(r.get_idea()[3].get_status() == "accepted");
}