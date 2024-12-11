#ifndef TRANSPORT_BUS_LINE_HPP
#define TRANSPORT_BUS_LINE_HPP

#include "List.hpp"
#include "State.hpp"
#include "BusStop.hpp"

#include <valarray>

class Bus;

class BusLine {
public:
  BusLine(const std::string &name, unsigned int stop_number, unsigned int bus_number, float flip_duration);

  void add_stop(const std::string &name, float stop_duration, float duration = 0);

  const std::valarray<unsigned int> &get_durations() const { return durations; }

  unsigned int get_flip_duration() const { return flip_duration; }

  const std::string &get_name() const { return name; }

  const std::valarray<BusStop> &get_stops() const { return stops; }

  unsigned int get_stop_index() const { return stop_index; }

  unsigned int get_stop_number() const { return stops.size(); }

  unsigned int get_bus_number() const { return bus_number; }

  unsigned int get_total_duration() const;

  List<Bus> get_bus(unsigned int time, State state);

  unsigned int run(unsigned int time);

  ~BusLine() = default;

private:
  std::string name;
  unsigned int stop_number;
  std::valarray<unsigned int> durations;
  std::valarray<BusStop> stops;
  unsigned int bus_number;
  unsigned int flip_duration;
  unsigned int stop_index;
  List<Bus> bus;
};

#endif //TRANSPORT_BUS_LINE_HPP
