#include "Transport.hpp"

Transport::Transport(const std::string &id, const Line &line, unsigned int start_time, unsigned int position, Way way)
    : id(id), line(line)
{
    this->position = position;
    this->way = way;
    delay = std::floor((double)line.get_total_duration() / (double)line.get_bus_number());
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
        arret_index = line.get_stop_number() - 1;
    }
    last_time = 0;
}

Transport::Transport(const Transport &other) : id(other.id), line(other.line)
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
        if ((arret_index < line.get_stop_number() - 1 and way == UP) or (arret_index > 0 and way == DOWN))
        {
            state = RUNNING;
            next_time = time + (way == UP ? line.get_durations()[arret_index] : line.get_durations()[arret_index]);
            arret_index += way == UP ? 1 : -1;
        }
        else
        {
            state = FLIP;
            next_time = time + line.get_flip_duration();
            way = way == UP ? DOWN : UP;
        }
    }
    else if (state == RUNNING or state == FLIP)
    {
        state = STOP;
        next_time = time + line.get_stops()[arret_index]->get_stop_duration();
    }
}
