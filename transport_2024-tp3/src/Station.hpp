#ifndef TRANSPORT_STATION_HPP
#define TRANSPORT_STATION_HPP

#include "Node.hpp"

class Station : public Node
{
public:
  Station() : Node() {}

  Station(const std::string &name, unsigned int stop_duration) : Node(name, stop_duration) {}
};

#endif // TRANSPORT_STATION_HPP
