#ifndef TRANSPORT_KERNEL_HPP
#define TRANSPORT_KERNEL_HPP

#include "BusLine.hpp"
#include "SubwayLine.hpp"
#include "List.hpp"

class Kernel {
public:
  Kernel();

  void add_bus_line(std::shared_ptr<BusLine> line);

  void add_subway_line(std::shared_ptr<SubwayLine> line);

  void run(unsigned int begin, unsigned int end);

  ~Kernel() = default;

private:
  List<BusLine> bus_lines;
  List<SubwayLine> subway_lines;
};

#endif //TRANSPORT_KERNEL_HPP
