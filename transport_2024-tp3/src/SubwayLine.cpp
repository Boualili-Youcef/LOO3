#include "Iterator.hpp"
#include "SubwayLine.hpp"
#include "Train.hpp"

#include <climits>

SubwayLine::SubwayLine(const std::string &name, unsigned int station_number, unsigned int train_number,
                       float flip_duration) :
  name(name), station_number(station_number), stations(station_number), durations(station_number - 1),
  train_number(train_number), flip_duration((int) (flip_duration * 60)), station_index(0) {
  for (unsigned int i = 0; i < train_number; ++i) {
    trains.add_first(std::make_shared<Train>(get_name() + "_" + std::to_string(i + 1), *this, 0, i, UP));
  }
}

void SubwayLine::add_station(const std::string &name, float stop_duration, float duration) {
  stations[station_index] = Station(name, (int) (stop_duration * 60));
  if (station_index < station_number - 1) {
    durations[station_index] = (int) (duration * 60);
  }
  station_index++;
}

unsigned int SubwayLine::get_total_duration() const {
  unsigned int total = 0;
  unsigned int i;

  for (i = 0; i < station_number; ++i) {
    total += stations[i].get_stop_duration();
    if (i < station_number - 1) {
      total += durations[i];
    }
  }
  total += 2 * flip_duration;
  return total;
}

List<Train> SubwayLine::get_trains(unsigned int time, State state) {
  List<Train> stopped_trains;
  Iterator<Train> it(trains, true);

  while (it.has_more()) {
    if (it.current()->get_state() == state and time == it.current()->get_last_time()) {
      stopped_trains.add_first(it.current());
    }
    it.next();
  }
  return stopped_trains;
}

unsigned int SubwayLine::run(unsigned int time) {
  unsigned int min_next_time = INT_MAX;
  Iterator<Train> it(trains, true);

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