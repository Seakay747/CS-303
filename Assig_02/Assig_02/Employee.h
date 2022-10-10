#pragma once

//base class for professional and nonpropfessional employee types
class Employee {
	private:
		double hours_worked;
		double percent_health_contribution = 0.025;
	public:
		virtual double get_weekly_salary() const = 0;
		virtual double get_healthcare_contributions() const = 0;
		virtual double get_vacation_days() const = 0;

		double get_hours_worked() const { return hours_worked; }
		void set_hours_worked(double hours) {
			hours_worked = hours;
		}

		double get_percent_contribution() const { return percent_health_contribution; }
		
};