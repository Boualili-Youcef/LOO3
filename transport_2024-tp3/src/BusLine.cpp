#include "Iterator.hpp"
#include "BusLine.hpp"
#include "Bus.hpp"

#include <climits>

BusLine::BusLine(const std::string &name, unsigned int stop_number, unsigned int bus_number, float flip_duration) :
  Line(name, stop_number, bus_number, flip_duration) {
  for (unsigned int i = 0; i < bus_number / 2; ++i) {
    add_transport(std::make_shared<Bus>(get_name() + "_" + std::to_string(i + 1), *this, 0, i, UP));
  }
  for (unsigned int i = 0; i < bus_number / 2; ++i) {
    add_transport(std::make_shared<Bus>(get_name() + "_" + std::to_string(bus_number / 2 + i + 1),
                                        *this, 0, i, DOWN));
  }

}