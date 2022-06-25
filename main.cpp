#include <controller.hpp>

int main(int, char **)
{
	Controller *c = new Controller();

	std::this_thread::sleep_for(std::chrono::seconds(10));

	delete c;

	std::cout << "Hello World" << std::endl;
}
