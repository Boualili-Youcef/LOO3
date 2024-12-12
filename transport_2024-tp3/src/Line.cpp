#include "Iterator.hpp"
#include "Line.hpp"
#include "Transport.hpp"

#include <climits>

Line::Line(const std::string &name, unsigned int stop_number, unsigned int bus_number, float flip_duration)
    : name(name), stop_number(stop_number), stops(stop_number), durations(stop_number - 1),
      bus_number(bus_number), flip_duration((int)(flip_duration * 60)), stop_index(0)
{
}

unsigned int Line::get_total_duration() const
{
    unsigned int total = 0;
    unsigned int i;

    for (i = 0; i < stop_number; ++i)
    {
        total += stops[i]->get_stop_duration();
        if (i < stop_number - 1)
        {
            total += durations[i];
        }
    }
    total += 2 * flip_duration;
    return total;
}

List<std::shared_ptr<Transport>> Line::get_transport(unsigned int time, State state)
{
    List<std::shared_ptr<Transport>> stopped_transport;
    Iterator<std::shared_ptr<Transport>> it(transport, true);

    while (it.has_more())
    {

        // Ajout de get() pour accéder à l'objet pointé par le shared_ptr
        if (it.current()->get()->get_state() == state and time == it.current()->get()->get_last_time())
        {
            stopped_transport.add_first(it.current());
        }
        it.next();
    }
    return stopped_transport;
}

unsigned int Line::run(unsigned int time)
{
    unsigned int min_next_time = INT_MAX;
    Iterator<std::shared_ptr<Transport>> it(transport, true);
    while (it.has_more())
    {
        if (it.current()->get()->get_next_time() == time)
        {
            it.current()->get()->run(time);

            //      std::cout << time << " => ";
            //      it.current()->display();
            //      std::cout << std::endl;
        }
        if (it.current()->get()->get_next_time() < min_next_time)
        {
            min_next_time = it.current()->get()->get_next_time();
        }
        it.next();
    }
    return min_next_time;
}