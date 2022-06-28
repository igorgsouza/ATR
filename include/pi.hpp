#include "atr_include.hpp"

class PI
{
  private:
	double proportional_gain;
	double integral_gain;

	double prev_error;
	double prev_integral;

  public:
	PI();
	PI(double, double);
	~PI();
	double signal(double, double);
};