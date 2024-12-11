#include "Transport.hpp"

Transport::Transport(const std::string &id, unsigned int start_time, unsigned int position, Way way,
                     unsigned int total_duration, unsigned int transport_number, unsigned int arret_number)
    : id(id)
{
    this->position = position;
    this->way = way;
    delay = std::floor((double)total_duration / (double)transport_number);
    if (position == 0)
    {
        state = START;
        next_time = start_time;
    }
    else
    {
        state = WAIT_START;
        next_time = start_time + position * delay;
    }
    if (way == UP)
    {
        arret_index = 0;
    }
    else
    {
        arret_index =  arret_number - 1;
    }
    last_time = 0;
}

Transport::Transport(const Transport &other) : id(other.id)
{
    position = other.position;
    way = other.way;
    delay = other.delay;
    state = other.state;
    next_time = other.next_time;
    arret_index = other.arret_index;
}

void Transport::run(unsigned int time)
{
    last_time = time;
    if (state == WAIT_START)
    {
        state = START;
        next_time = time;
    }
    else if (state == START or state == STOP)
    {
        if ((arret_index < get_node_number_of_line() - 1 and way == UP) or (arret_index > 0 and way == DOWN))
        {
            state = RUNNING;
            next_time = time + (way == UP ? get_duration_to_node(arret_index) : get_duration_to_node(arret_index - 1));
            arret_index += way == UP ? 1 : -1;
        }
        else
        {
            state = FLIP;
            next_time = time + get_flip_duration();
            way = way == UP ? DOWN : UP;
        }
    }
    else if (state == RUNNING or state == FLIP)
    {
        state = STOP;
        next_time = time + get_stop_duration_of_node(arret_index);
    }
}
