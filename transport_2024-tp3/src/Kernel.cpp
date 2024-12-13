#include "Bus.hpp"
#include "Iterator.hpp"
#include "Kernel.hpp"
#include "Train.hpp"

#include <climits>
#include <iostream>

Kernel::Kernel() {
}

void Kernel::add_line(std::shared_ptr<Line> line) {
  lines.add_first(line);
}

void Kernel::run(unsigned int begin, unsigned int end) {
  unsigned int time = begin;

  while (time <= end) {
    unsigned int min_next_time = INT_MAX;

    // bus lines
    {
      Iterator<Line> it_lines(lines, true);

      while (it_lines.has_more()) {
        unsigned int next_time = it_lines.current()->run(time);
        std::cout << next_time << " => ";
        {
          List<Transport> stopped_transport = it_lines.current()->get_transport(time, STOP);
          Iterator<Transport> it(stopped_transport, true);
          while (it.has_more()) {
            it.current()->display();
    
            it.next();
          }
        }
        if (next_time < min_next_time) {
          min_next_time = next_time;
        }
        it_lines.next();
      }
    }
    time = min_next_time;
  }
}