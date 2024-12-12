#ifndef TRANSPORT_LINE_HPP
#define TRANSPORT_LINE_HPP

#include "List.hpp"
#include "State.hpp"
#include "Node.hpp"
#include <memory>
// #include <vector>

#include <valarray>

class Transport;

class Line
{
public:
  Line(const std::string &name, unsigned int stop_number, unsigned int bus_number, float flip_duration);

  const std::valarray<unsigned int> &get_durations() const { return durations; }
  unsigned int get_flip_duration() const { return flip_duration; }
  const std::string &get_name() const { return name; }
  const std::valarray<std::shared_ptr<Node>> &get_stops() const { return stops; }
  unsigned int get_stop_index() const { return stop_index; }
  unsigned int get_stop_number() const { return stops.size(); }
  unsigned int get_bus_number() const { return bus_number; }
  unsigned int get_total_duration() const;

  virtual void add_stop(const std::string &name, float stop_duration, float duration = 0) = 0;
  List<std::shared_ptr<Transport>> get_transport(unsigned int time, State state);
  virtual unsigned int run(unsigned int time) = 0;

  virtual ~Line() = default;

private:
  std::string name;
  unsigned int stop_number;
  std::valarray<unsigned int> durations;
  std::valarray<std::shared_ptr<Node>> stops;
  unsigned int bus_number;
  unsigned int flip_duration;
  unsigned int stop_index;
  List<std::shared_ptr<Transport>> transport;
};

#endif // TRANSPORT_LINE_HPP
