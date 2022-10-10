#include <iostream>
#include <vector>
#include <assert.h>
#include "Employee.h"
#include "Nonprofessional.h"
#include "Professional.h"
#include "common.h"

//while true, every function within professional and nonprofessional will print its action as it's performing it when called; also does some basic assertion tests
bool TESTING = true;

int main() {
	std::vector<Employee*> roster;

	//instantiating nonprofessional employess
	Nonprofessional* Dave = new Nonprofessional;
	Dave->set_hours_worked(43);
	Nonprofessional* Ryan = new Nonprofessional;
	Ryan->set_hours_worked(22);
	Nonprofessional* Elise = new Nonprofessional;
	Elise->set_hours_worked(40);

	//instantiating professional employees
	Professional* Hannah = new Professional;
	Hannah->set_hours_worked(62);
	Professional* Chris = new Professional;
	Chris->set_hours_worked(40);
	
	//assertion testing
	if (TESTING) {
		assert(Dave->get_hours_worked() == 43);
		assert(Ryan->get_hours_worked() == 22);
		assert(Elise->get_hours_worked() == 40);
		assert(Hannah->get_hours_worked() == 62);
		assert(Chris->get_hours_worked() == 40);
	}

	//filling the roster
	roster.push_back(Dave);
	roster.push_back(Ryan);
	roster.push_back(Elise);
	roster.push_back(Hannah);
	roster.push_back(Chris);

	//looping through roster to test functions on multiple edge cases, outcome are printed by function calls while testing is set to true in the global namespace
	for (unsigned int i = 0; i < roster.size(); i++) {
		roster.at(i)->get_weekly_salary();
		roster.at(i)->get_vacation_days();
	}

	return 0;
}