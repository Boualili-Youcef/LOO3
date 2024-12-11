#ifndef TRANSPORT_BUS_STOP_HPP
#define TRANSPORT_BUS_STOP_HPP

#include "Node.hpp"

class BusStop : public Node
{
public:
  BusStop() : Node() {}

  BusStop(const std::string &name, unsigned int stop_duration) : Node(name, stop_duration) {}
};

#endif // TRANSPORT_BUS_STOP_HPP
