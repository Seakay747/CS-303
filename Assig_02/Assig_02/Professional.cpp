#include <iostream>
#include "Employee.h"
#include "Professional.h"
#include "common.h"

//Function to get weekly salary after healthcare contributions, includes boneses for overtime hours
double Professional::get_weekly_salary() const {
	double contributions = get_healthcare_contributions();
	if (get_hours_worked() <= 49) {
		if (TESTING) {
			std::cout << "Calculating pay with no overtime..." << std::endl;
			std::cout << "Pays is " << (annual_salary / 52) - contributions << std::endl;
		}
		return (annual_salary / 52) - contributions;
	}
	else {
		double overtime = get_hours_worked() - 40;
		if (TESTING) {
			std::cout << "Calculating pay with " << overtime << " hours of overtime..." << std::endl;
		}
		if (overtime >= 40) {
			if (TESTING) {
				std::cout << "Pay is " << (((annual_salary / 52.0) - contributions) + 1200.0) << std::endl;
			}
			return (((annual_salary / 52.0) - contributions) + 1200.0);
		}
		else if (overtime >= 30) {
			if (TESTING) {
				std::cout << "Pay is " << (((annual_salary / 52.0) - contributions) + 750.0) << std::endl;
			}
			return (((annual_salary / 52.0) - contributions) + 750.0);
		}
		else if (overtime >= 20) {
			if (TESTING) {
				std::cout << "Pay is " << (((annual_salary / 52.0) - contributions) + 400.0) << std::endl;
			}
			return (((annual_salary / 52.0) - contributions) + 400.0);
		}
		else if (overtime >= 10) {
			if (TESTING) {
				std::cout << "Pay is " << (((annual_salary / 52.0) - contributions) + 150.0) << std::endl;
			}
			return (((annual_salary / 52.0) - contributions) + 150.0);
		}
		else {
			if (TESTING) {
				std::cout << "Pay is " << (((annual_salary / 52.0) - contributions) + 100.0) << std::endl;
			}
			return (((annual_salary / 52.0) - contributions) + 100.0);
		}
	};
}

//Function to calculate the amount being put towards healthcare contributions based off of a standard precentage
double Professional::get_healthcare_contributions() const {
	if (get_hours_worked() <= 49) {
		if (TESTING) {
			std::cout << "Calculating healthcare contribution with no overtime..." << std::endl;
			std::cout << "Contribution amount is " << (annual_salary / 52) * get_percent_contribution() << std::endl;
		}
		return (annual_salary / 52) * get_percent_contribution();
	}
	else {
		double overtime = get_hours_worked() - 40;
		if (TESTING) {
			std::cout << "Calculating healthcare contributions with " << overtime << " hours of overtime..." << std::endl;
		}
		if (overtime >= 40) {
			if (TESTING) {
				std::cout << "Contribution amount is " << (((annual_salary / 52.0) + 1200.0) * get_percent_contribution()) << std::endl;
			}
			return (((annual_salary / 52.0) + 1200.0) * get_percent_contribution());
		}
		else if (overtime >= 30) {
			if (TESTING) {
				std::cout << "Contribution amount is " << (((annual_salary / 52.0) + 750.0) * get_percent_contribution()) << std::endl;
			}
			return (((annual_salary / 52.0) + 750.0) * get_percent_contribution());
		}
		else if (overtime >= 20) {
			if (TESTING) {
				std::cout << "Contribution amount is " << (((annual_salary / 52.0) + 400.0) * get_percent_contribution()) << std::endl;
			}
			return (((annual_salary / 52.0) + 400.0) * get_percent_contribution());
		}
		else if (overtime >= 10) {
			if (TESTING) {
				std::cout << "Contribution amount is " << (((annual_salary / 52.0) + 150.0) * get_percent_contribution()) << std::endl;
			}
			return (((annual_salary / 52.0) + 150.0) * get_percent_contribution());
		}
		else {
			if (TESTING) {
				std::cout << "Contribution amount is " << (((annual_salary / 52.0) + 100.0) * get_percent_contribution()) << std::endl;
			}
			return (((annual_salary / 52.0) + 100.0) * get_percent_contribution());
		}
	}
}

//Function to calculate the amount of vacation earned in the current week based off of the annual amount given to professional employess
double Professional::get_vacation_days() const {
	if (TESTING) {
		std::cout << "Calculating vacation days..." << std::endl;
		std::cout << (annual_vacation_hours / 52) << " hours of vaction earned" << std::endl;
	}
	return (annual_vacation_hours / 52);
}