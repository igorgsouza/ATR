#include "atr_include.hpp"

class PI
{
  private:
	double proportional_gain;
	double integral_gain;

	double prev_error = 0;
	double prev_integral = 0;

  public:
	PI(double, double);
	PI();
	~PI();

	double signal(double, double);
};