#include <boost_tutorial.hpp>

void print(const boost::system::error_code & /*e*/) { std::cout << "Hello, world!" << std::endl; }

int run()
{
	boost::asio::io_context io;

	boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));
	t.async_wait(&print);

	io.run();

	return 0;
}