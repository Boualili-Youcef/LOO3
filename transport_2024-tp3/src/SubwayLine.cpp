#include "Iterator.hpp"
#include "SubwayLine.hpp"
#include "Train.hpp"

#include <climits>

SubwayLine::SubwayLine(const std::string &name, unsigned int station_number, unsigned int train_number,
                       float flip_duration) :
  Line(name, station_number, train_number, flip_duration) {
  for (unsigned int i = 0; i < train_number; ++i) {
     add_transport(std::make_shared<Train>(get_name() + "_" + std::to_string(i + 1), *this, 0, i, UP));
  }
}
