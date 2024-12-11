#include "Iterator.hpp"
#include "BusLine.hpp"
#include "Bus.hpp"

#include <climits>

BusLine::BusLine(const std::string &name, unsigned int stop_number, unsigned int bus_number, float flip_duration) :
  name(name), stop_number(stop_number), stops(stop_number), durations(stop_number - 1),
  bus_number(bus_number), flip_duration((int) (flip_duration * 60)), stop_index(0) {
  for (unsigned int i = 0; i < bus_number / 2; ++i) {
    bus.add_first(std::make_shared<Bus>(get_name() + "_" + std::to_string(i + 1), *this, 0, i, UP));
  }
  for (unsigned int i = 0; i < bus_number / 2; ++i) {
    bus.add_first(std::make_shared<Bus>(get_name() + "_" + std::to_string(bus_number / 2 + i + 1),
                                        *this, 0, i, DOWN));
  }

}

void BusLine::add_stop(const std::string &name, float stop_duration, float duration) {
  stops[stop_index] = BusStop(name, (int) (stop_duration * 60));
  if (stop_index < stop_number - 1) {
    durations[stop_index] = (int) (duration * 60);
  }
  stop_index++;
}

unsigned int BusLine::get_total_duration() const {
  unsigned int total = 0;
  unsigned int i;

  for (i = 0; i < stop_number; ++i) {
    total += stops[i].get_stop_duration();
    if (i < stop_number - 1) {
      total += durations[i];
    }
  }
  total += 2 * flip_duration;
  return total;
}

List<Bus> BusLine::get_bus(unsigned int time, State state) {
  List<Bus> stopped_bus;
  Iterator<Bus> it(bus, true);

  while (it.has_more()) {
    if (it.current()->get_state() == state and time == it.current()->get_last_time()) {
      stopped_bus.add_first(it.current());
    }
    it.next();
  }
  return stopped_bus;
}

unsigned int BusLine::run(unsigned int time) {
  unsigned int min_next_time = INT_MAX;
  Iterator<Bus> it(bus, true);

  while (it.has_more()) {
    if (it.current()->get_next_time() == time) {
      it.current()->run(time);

//      std::cout << time << " => ";
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