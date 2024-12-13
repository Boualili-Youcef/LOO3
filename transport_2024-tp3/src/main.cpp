#include "BusLine.hpp"
#include "Kernel.hpp"
#include "SubwayLine.hpp"
#include "Line.hpp"

void build_bus_line(Kernel &kernel) {
  auto line_1 = std::make_shared<Line>("A1", 10, 10, 5);
  auto line_2 = std::make_shared<Line>("A2", 10, 10, 7);

  line_1->add_node("1", 2, 1.7f);
  line_1->add_node("2", 2, 4.5f);
  line_1->add_node("3", 2, 6.9f);
  line_1->add_node("4", 2, 3.f);
  line_1->add_node("5", 2, 5.3f);
  line_1->add_node("6", 2, 6.1f);
  line_1->add_node("7", 2, 7.4f);
  line_1->add_node("8", 2, 3.4f);
  line_1->add_node("9", 2, 2.2f);
  line_1->add_node("10", 2);

  line_2->add_node("11", 2, 3.2f);
  line_2->add_node("12", 2, 2.7f);
  line_2->add_node("13", 2, 4.9f);
  line_2->add_node("14", 2, 4.3f);
  line_2->add_node("15", 2, 7.6f);
  line_2->add_node("16", 2, 6.9f);
  line_2->add_node("17", 2, 1.2f);
  line_2->add_node("18", 2, 2.f);
  line_2->add_node("19", 2, 5.1f);
  line_2->add_node("20", 2);

  kernel.add_line(line_1);
  kernel.add_line(line_2);
}

void build_subway_line(Kernel &kernel) {
  auto line_1 = std::make_shared<Line>("L1", 6, 8, 4);
  auto line_2 = std::make_shared<Line>("L2", 5, 6, 6);

  line_1->add_node("1", 2, 4.1f);
  line_1->add_node("2_1", 2, 3.5f);
  line_1->add_node("3", 2, 4.2f);
  line_1->add_node("4", 2, 3.2f);
  line_1->add_node("5_1", 2, 5.f);
  line_1->add_node("6", 2);

  line_2->add_node("7", 2, 7.2f);
  line_2->add_node("8", 2, 5.1f);
  line_2->add_node("2_2", 2, 2.2f);
  line_2->add_node("9", 2, 2.7f);
  line_2->add_node("10", 2);

  kernel.add_line(line_1);
  kernel.add_line(line_2);
}

int main() {
  Kernel kernel;

  build_bus_line(kernel);
  build_subway_line(kernel);
  /* Loop simulation */
  kernel.run(0, 5000);

  return 0;
}