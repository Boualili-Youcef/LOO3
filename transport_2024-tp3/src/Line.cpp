#include "Iterator.hpp"
#include "Line.hpp"
#include "Transport.hpp"

#include <climits>

Line::Line(const std::string &name, unsigned int stop_number, unsigned int bus_number, float flip_duration)
    : name(name), stop_number(stop_number), stops(stop_number), durations(stop_number - 1),
      bus_number(bus_number), flip_duration((int)(flip_duration * 60)), stop_index(0)
{
}

void Line::add_node(const std::string &name, float stop_duration, float duration) {
  stops[stop_index] = std::make_shared<Node>(name, (int) (stop_duration * 60));
  if (stop_index < get_stop_number() - 1) {
    durations[stop_index] = (int) (duration * 60);
  }
  stop_index++;
}

List<Transport> Line::get_transport(unsigned int time, State state) {
  List<Transport> stopped_bus;
  
  Iterator<Transport> it(transport, true);

  while (it.has_more()) {
    if (it.current()->get_state() == state and time == it.current()->get_last_time()) {
      stopped_bus.add_first(it.current());
    }
    it.next();
  }
  return stopped_bus;
}


unsigned int Line::get_total_duration() const {
  unsigned int total = 0;
  unsigned int i;

  for (i = 0; i < get_stop_number(); ++i) {
    total += stops[i]->get_stop_duration();
    if (i < get_stop_number() - 1) {
      total += durations[i];
    }
  }
  total += 2 * get_flip_duration();
  return total;
}

unsigned int Line::run(unsigned int time) {
  unsigned int min_next_time = INT_MAX;
  Iterator<Transport> it(transport, true);
    std::cout << "tran: " << transport.size() << std::endl;
  while (it.has_more()) {
    if (it.current()->get_next_time() == time) {
      it.current()->run(time);

      std::cout << time << " => ";
//      it.current()->display();
//      std::cout << std::endl;

    }
    if (it.current()->get_next_time() < min_next_time) {
      min_next_time = it.current()->get_next_time();
    }
    it.next();
  }
  return min_next_time;
}

