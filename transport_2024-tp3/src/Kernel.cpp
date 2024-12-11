#include "Bus.hpp"
#include "Iterator.hpp"
#include "Kernel.hpp"
#include "Train.hpp"

#include <climits>
#include <iostream>

Kernel::Kernel() {
}

void Kernel::add_bus_line(std::shared_ptr<BusLine> line) {
  bus_lines.add_first(line);
}

void Kernel::add_subway_line(std::shared_ptr<SubwayLine> line) {
  subway_lines.add_first(line);
}

void Kernel::run(unsigned int begin, unsigned int end) {
  unsigned int time = begin;

  while (time <= end) {
    unsigned int min_next_time = INT_MAX;

    // bus lines
    {
      Iterator<BusLine> it_bus_lines(bus_lines, true);

      while (it_bus_lines.has_more()) {
        unsigned int next_time = it_bus_lines.current()->run(time);

        {
          List<Bus> stopped_bus = it_bus_lines.current()->get_bus(time, STOP);
          Iterator<Bus> it(stopped_bus, true);
          while (it.has_more()) {
            std::cout << time << " : " << it.current()->get_id() << " in stop "
                      << it.current()->get_line().get_stops()[it.current()->get_arret_index()].get_name()
                      << " of bus line " << it.current()->get_line().get_name() << std::endl;
            it.next();
          }
        }
        if (next_time < min_next_time) {
          min_next_time = next_time;
        }
        it_bus_lines.next();
      }
    }
    // subway lines
    {
      Iterator<SubwayLine> it_subway_lines(subway_lines, true);

      while (it_subway_lines.has_more()) {
        unsigned int next_time = it_subway_lines.current()->run(time);

        {
          List<Train> stopped_trains = it_subway_lines.current()->get_trains(time, STOP);
          Iterator<Train> it(stopped_trains, true);
          while (it.has_more()) {
            std::cout << time << " : " << it.current()->get_id() << " in station "
                      << it.current()->get_line().get_stations()[it.current()->get_arret_index()].get_name()
                      << " of subway line " << it.current()->get_line().get_name() << std::endl;
            it.next();
          }
        }
        if (next_time < min_next_time) {
          min_next_time = next_time;
        }
        it_subway_lines.next();
      }
    }
    time = min_next_time;
  }
}