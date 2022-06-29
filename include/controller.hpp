#include "pi.hpp"
#include "reservoir.hpp"

class Controller
{
  private:
	bool active = true;
	bool foward = true;
	bool running = true;

	Reservoir reservoir;

	double h_ref;
	uint32_t cycle_time;

	std::thread *process_thread;
	std::thread *softPLC_thread;

	PI pi;

  public:
	Controller();
	~Controller();

	void process();
	void softPLC();
};