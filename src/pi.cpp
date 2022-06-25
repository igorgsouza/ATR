#include <pi.hpp>

PI::PI()
{
	proportional_gain = 1;
	integral_gain = 1;
}

PI::PI(double proportional, double integral)
{
	proportional_gain = proportional;
	integral_gain = integral;
}

PI::~PI() {}

double PI::signal(double reference, double real)
{
	double error = reference - real;

	double proportional = proportional_gain * error;

	double integral = prev_integral + 0.5 * (integral_gain * (error + prev_error));

	prev_error = error;
	prev_integral = integral;

	return proportional + integral;
}