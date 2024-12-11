#ifndef TRANSPORT_HPP
#define TRANSPORT_HPP

#include "Node.hpp"
#include "State.hpp"
#include "Way.hpp"
#include <cmath>


class Transport
{
public:
    // Les constructeurs de la classe Transport 
    // J'ai rajouté des paramètres total_duration, transport_number et arret_number 
    // je ne sais pas si il faut modifier les construeurs
    Transport(const std::string &id, unsigned int start_time, unsigned int position, Way way,
              unsigned int total_duration, unsigned int transport_number, unsigned int arret_number);

    Transport(const Transport &other);

    // Les getters de la classe Transport
    const std::string &get_id() const { return id; }
    unsigned int get_last_time() const { return last_time; }
    unsigned int get_next_time() const { return next_time; }
    const State &get_state() const { return state; }
    unsigned int get_arret_index() const { return arret_index; }
    const Way &get_way() const { return way; }

    // La méthode run factorise le code des classes Bus et Train
    void run(unsigned int time);

    // Methodes virtuelles pures de la classe Transport
    virtual unsigned int get_node_number_of_line() const = 0;
    virtual unsigned int get_duration_to_node(unsigned int node_index) const = 0;
    virtual unsigned int get_stop_duration_of_node(unsigned int node_index) const = 0;
    virtual unsigned int get_flip_duration() const = 0;

    // Le destructeur de la classe Transport virtuel
    virtual ~Transport() = default;

private:
    std::string id;
    unsigned int position;
    unsigned int delay;
    State state;
    Way way;
    unsigned int next_time;
    unsigned int last_time;
    unsigned int arret_index;
};

#endif // TRANSPORT_HPP
