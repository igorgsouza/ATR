#include <controller.hpp>

Controller::Controller()
{
	reservoir = Reservoir();

	h_ref = reservoir.height() * 0.5;
	cycle_time = 50;

	process_thread = new std::thread(&process, this);
	softPLC_thread = new std::thread(&softPLC, this);

	pi = PI(10, 2);
}

Controller::~Controller()
{
	running = false;

	process_thread->join();
	softPLC_thread->join();

	delete process_thread;
	delete softPLC_thread;
}

void Controller::process()
{
	while (running)
	{
		if (active)
		{
			if (foward)
				reservoir.next_second();
			else
				reservoir.prev_second();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(cycle_time));

		std::cout << reservoir.water_level() << std::endl;
	}
}

void Controller::softPLC()
{
	while (running)
	{
		reservoir.set_flow_in(pi.signal(h_ref, reservoir.water_level()));

		std::this_thread::sleep_for(std::chrono::milliseconds(cycle_time * 2));
	}
}