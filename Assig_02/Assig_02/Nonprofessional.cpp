#include <iostream>
#include "Employee.h"
#include "Nonprofessional.h"
#include "common.h"

//Function used to calculate weekly salary; paying time and a half for overtime hours and subtracting healthcare contributions
double Nonprofessional::get_weekly_salary() const {
	double contributions = get_healthcare_contributions();
	if (get_hours_worked() <= 40) {
		if (TESTING) {
			std::cout << "Calculating pay with no overtime..." << std::endl;
			std::cout << "Pay is " << (get_hours_worked() * hourly_pay_rate) - contributions << std::endl;
		}
		return (get_hours_worked() * hourly_pay_rate) - contributions;
	}
	else {
		double overtime = get_hours_worked() - 40;
		if (TESTING) {
			std::cout << "Calculating weekly pay with " << overtime << " hours of overtime..." << std::endl;
			std::cout << "Pay is " << (((get_hours_worked() - overtime) * hourly_pay_rate) + (overtime * hourly_pay_rate * 1.5)) - contributions << std::endl;
		}
		return (((get_hours_worked() - overtime) * hourly_pay_rate) + (overtime * hourly_pay_rate * 1.5)) - contributions;
	}
}

//Function used to calculate precent deduction that goes towards healthcare
double Nonprofessional::get_healthcare_contributions() const {
	if (get_hours_worked() <= 40) {
		if (TESTING) {
			std::cout << "Calculating healthcare contributions with no overtime..." << std::endl;
			std::cout << "Contribution amount is " << (get_hours_worked() * hourly_pay_rate * get_percent_contribution()) << std::endl;
		}
		return (get_hours_worked() * hourly_pay_rate * get_percent_contribution());
	}
	else {
		double overtime = get_hours_worked() - 40;
		if (TESTING) {
			std::cout << "Calculating healthcare contributions with " << overtime << " hours of overtime..." << std::endl;
			std::cout << "Contribution amount is " << (((get_hours_worked() - overtime) * hourly_pay_rate) + (overtime * hourly_pay_rate * 1.5)) * get_percent_contribution() << std::endl;
		}
		return (((get_hours_worked() - overtime) * hourly_pay_rate) + (overtime * hourly_pay_rate * 1.5)) * get_percent_contribution();
	}
}

//Function used to calculate the number of vacation days earned based off of the hourly earn rate
double Nonprofessional::get_vacation_days() const {
	if (TESTING) {
		std::cout << "Calculating vacation days..." << std::endl;
		std::cout << (get_hours_worked() * hourly_vacation_rate) << " hours of vacation earned" << std::endl;
	}
	return (get_hours_worked() * hourly_vacation_rate);
}