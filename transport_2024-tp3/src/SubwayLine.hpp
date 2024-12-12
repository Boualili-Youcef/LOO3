#ifndef TRANSPORT_SUBWAY_LINE_HPP
#define TRANSPORT_SUBWAY_LINE_HPP

#include "List.hpp"
#include "State.hpp"
#include "Station.hpp"

#include <valarray>

class Train;

class SubwayLine {
public:
  SubwayLine(const std::string &name, unsigned int station_number, unsigned int train_number, float flip_duration);

  void add_station(const std::string &name, float stop_duration, float duration = 0);

  const std::valarray<unsigned int> &get_durations() const { return durations; }
  unsigned int get_flip_duration() const { return flip_duration; }
  const std::string &get_name() const { return name; }
  const std::valarray<Station> &get_stations() const { return stations; }
  unsigned int get_station_index() const { return station_index; }
  unsigned int get_station_number() const { return stations.size(); }
  unsigned int get_train_number() const { return train_number; }
  unsigned int get_total_duration() const;
  List<Train> get_trains(unsigned int time, State state);

  unsigned int run(unsigned int time);

  ~SubwayLine() = default;

private:
  std::string name;
  unsigned int station_number;
  std::valarray<unsigned int> durations;
  std::valarray<Station> stations;
  unsigned int train_number;
  unsigned int flip_duration;
  unsigned int station_index;
  List<Train> trains;
};

#endif //TRANSPORT_SUBWAY_LINE_HPP
