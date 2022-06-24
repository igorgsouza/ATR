#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include <reservoir.hpp>

void print(const boost::system::error_code& /*e*/, boost::asio::steady_timer* t, Reservoir& r)
{
    while (r.time() < 10)
    {
        std::cout << "Water Level: " << r.water_level() << " Time: " << r.time() << std::endl;

        r.next_second();

        t->expires_at(t->expiry() + boost::asio::chrono::milliseconds(1000));
        t->async_wait(boost::bind(print,boost::asio::placeholders::error, t, r));

    }
}

int main(int, char**) 
{

    Reservoir r = Reservoir();

    while(r.time() < 60)
    {
        std::cout << "\rWater Level: " << r.water_level() << " Time: " << r.time();;
        r.next_second();
    }

    return 0;

    boost::asio::io_context io;

    int count = 0;
    boost::asio::steady_timer t(io, boost::asio::chrono::milliseconds(1000));

    t.async_wait(boost::bind(print,boost::asio::placeholders::error, &t, r));
    
    io.run();

    return 0;
}
