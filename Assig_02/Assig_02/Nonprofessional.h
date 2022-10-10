#pragma once
#include "Employee.h"

//nonprofessional inheriting from the employee with two new variables for hourly pay rate and hourly vacation rate
class Nonprofessional : public Employee {
	private:
		double hourly_pay_rate = 22.25;
		double hourly_vacation_rate = 0.005;
	public:
		double get_weekly_salary() const;
		double get_healthcare_contributions() const;
		double get_vacation_days() const;
};