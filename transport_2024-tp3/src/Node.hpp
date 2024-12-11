#ifndef TRANSPORT_NODE_HPP
#define TRANSPORT_NODE_HPP

#include <string>

class Node {
public:
  Node() : stop_duration(0) {}

  Node(const std::string &name, unsigned int stop_duration) : name(name), stop_duration(stop_duration) {}

  const std::string &get_name() const { return name; }

  unsigned int get_stop_duration() const { return stop_duration; }

private:
  std::string name;
  unsigned int stop_duration;
};

#endif //TRANSPORT_NODE_STOP_HPP
