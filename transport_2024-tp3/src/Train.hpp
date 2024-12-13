#ifndef TRANSPORT_TRAIN_HPP
#define TRANSPORT_TRAIN_HPP

#include "SubwayLine.hpp"
#include "State.hpp"
#include "Way.hpp"
#include "Transport.hpp"

class Train : public Transport
{
public:
  // Les constructeurs de la classe Train
  Train(const std::string &id, const Line &line, unsigned int start_time, unsigned int position, Way way);
  Train(const Train &other);

  // La méthode display affiche l'état du train
  void display() const override;

  /*
    // Getters de la classe Train
    const Line &get_line() const override { return line; }

    // Implementation des methodes virtuelles pures de la classe Transport
    unsigned int get_node_number_of_line() const override;
    unsigned int get_duration_to_node(unsigned int node_index) const override;
    unsigned int get_stop_duration_of_node(unsigned int node_index) const override;
    unsigned int get_flip_duration() const override;
  */
  ~Train() = default;
};

#endif // TRANSPORT_TRAIN_HPP
