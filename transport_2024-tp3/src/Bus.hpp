#ifndef TRANSPORT_BUS_HPP
#define TRANSPORT_BUS_HPP

#include "BusLine.hpp"
#include "State.hpp"
#include "Way.hpp"
#include "Transport.hpp"

class Bus : public Transport
{
public:
  // Les constructeurs de la classe Bus
  Bus(const std::string &id, const BusLine &line, unsigned int start_time, unsigned int position, Way way);
  Bus(const Bus &other);

  // La méthode display affiche l'état du bus
  void display();

  // Getters de la classe Bus
  const BusLine &get_line() const { return line; }

  // Implementation des methodes virtuelles pures de la classe Transport
  unsigned int get_node_number_of_line() const override;
  unsigned int get_duration_to_node(unsigned int node_index) const override;
  unsigned int get_stop_duration_of_node(unsigned int node_index) const override;
  unsigned int get_flip_duration() const override;

  ~Bus() = default;

private:
  const BusLine &line;
};

#endif // TRANSPORT_BUS_HPP
