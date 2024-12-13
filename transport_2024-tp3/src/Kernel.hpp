#ifndef TRANSPORT_KERNEL_HPP
#define TRANSPORT_KERNEL_HPP

#include "Line.hpp"
#include "List.hpp"
#include <memory>

class Kernel {
public:
  Kernel();

  void add_line(std::shared_ptr<Line> line);

  void run(unsigned int begin, unsigned int end);

  ~Kernel() = default;

private:
  List<Line> lines; // Liste unique pour toutes les lignes
};

#endif //TRANSPORT_KERNEL_HPP
