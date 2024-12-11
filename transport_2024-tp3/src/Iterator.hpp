#ifndef TRANSPORT_ITERATOR_HPP
#define TRANSPORT_ITERATOR_HPP

#include "List.hpp"

template<typename Data>
class Iterator {
public:
  Iterator(const List<Data> &list, bool forward)
    : _list(list), _current_cell(forward ? list.first() : list.last()), _forward(forward) {}

  const std::shared_ptr<Data> &current() { return _current_cell->data(); }

  bool has_more() { return _current_cell != nullptr; }

  void next() { _current_cell = _forward ? _current_cell->next() : _current_cell->previous(); }

private:
  const List<Data> &_list;
  std::shared_ptr<Cell<Data>> _current_cell;
  bool _forward;
};

#endif //TRANSPORT_ITERATOR_HPP
