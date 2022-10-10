#pragma once
#include "Employee.h"

//professional employee inheriting from employeee class adding annual salary and annual vacation hours
class Professional : public Employee {
	private:
		double annual_salary = 50024;
		double annual_vacation_hours = 83.2;
	public:
public:
	double get_weekly_salary() const;
	double get_healthcare_contributions() const;
	double get_vacation_days() const;
};