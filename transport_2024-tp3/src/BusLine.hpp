#ifndef TRANSPORT_BUS_LINE_HPP
#define TRANSPORT_BUS_LINE_HPP

#include "List.hpp"
#include "State.hpp"
#include "BusStop.hpp"
#include "Line.hpp"

#include <valarray>

class Bus;

class BusLine : public Line {
public:
  BusLine(const std::string &name, unsigned int stop_number, unsigned int bus_number, float flip_duration);

  ~BusLine() override = default;

};

#endif //TRANSPORT_BUS_LINE_HPP
