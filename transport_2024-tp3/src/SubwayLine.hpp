#ifndef TRANSPORT_SUBWAY_LINE_HPP
#define TRANSPORT_SUBWAY_LINE_HPP

#include "List.hpp"
#include "State.hpp"
#include "Station.hpp"
#include "Line.hpp"

#include <valarray>

class Train;

class SubwayLine : public Line
{
public:
  SubwayLine(const std::string &name, unsigned int station_number, unsigned int train_number, float flip_duration);

  ~SubwayLine() override = default;
};

#endif // TRANSPORT_SUBWAY_LINE_HPP
