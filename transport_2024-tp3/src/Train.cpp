#include <cmath>
#include <iostream>

#include "Train.hpp"

Train::Train(const std::string &id, const SubwayLine &line, unsigned int start_time, unsigned int position, Way way)
    : Transport(id, start_time, position, way, line.get_total_duration(),
                line.get_train_number(), line.get_station_number()),
      line(line) {}

Train::Train(const Train &other) : Transport(other), line(other.line) {}

void Train::display()
{
  std::cout << "train " << get_id() << ": " << state_to_string(get_state())
            << " " << (get_state() == RUNNING ? "to station" : "in station")
            << " " << line.get_stations()[get_arret_index()].get_name() << " "
            << line.get_name() << " " << (get_way() == UP ? "UP" : "DOWN");
}

// Implementation des methodes virtuelles pures de la classe Transport
unsigned int Train::get_node_number_of_line() const { return line.get_station_number(); }
unsigned int Train::get_duration_to_node(unsigned int node_index) const { return line.get_durations()[node_index]; }
unsigned int Train::get_stop_duration_of_node(unsigned int node_index) const { return line.get_stations()[node_index].get_stop_duration(); }
unsigned int Train::get_flip_duration() const { return line.get_flip_duration(); }
