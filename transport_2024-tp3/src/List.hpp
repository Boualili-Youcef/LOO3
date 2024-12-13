#ifndef TRANSPORT_LIST_HPP
#define TRANSPORT_LIST_HPP

#include "Cell.hpp"

#include <iostream>

template<typename Data>
class List {
public:
  List() : _first(nullptr), _last(nullptr) {}

  List(const List &other) {
    std::shared_ptr<Cell<Data>> current = _first;

    while (current != nullptr) {
      add_last(current->data());
      current = current->next();
    }
  }

  void add_first(const std::shared_ptr<Data> &data) {
    std::shared_ptr<Cell<Data>> new_cell = std::make_shared<Cell<Data>>(data, nullptr, _first);

    if (_first != nullptr) {
      _first->_previous = new_cell;
    }
    _first = new_cell;
    _last = _last == nullptr ? _first : _last;
  }

  void add_last(const std::shared_ptr<Data> &data) {
    std::shared_ptr<Cell<Data>> new_cell = std::make_shared<Cell<Data>>(data, _last, nullptr);

    if (_last != nullptr) {
      _last->_next = new_cell;
    }
    _last = new_cell;
    _first = _first == nullptr ? _last : _first;
  }

  void append(List &list) {
    std::shared_ptr<Cell<Data>> current = list.first();

    while (current != nullptr) {
      add_last(current->data);
      current = current->next;
    }
  }

  const std::shared_ptr<Cell<Data>> &first() const { return _first; }

  const std::shared_ptr<Cell<Data>> &last() const { return _last; }

  unsigned int size() {
    unsigned int size = 0;
    std::shared_ptr<Cell<Data>> current = _first;

    while (current != _last) {
      ++size;
      current = current->next();
    }
    return size;
  }

  void remove_first() {
    if (_first != nullptr) {
      _first = _first->next;
      if (_first == nullptr) {
        _last = nullptr;
      }
    }
  }

  void remove_last() {
    if (_last != nullptr) {
      _last = _last->previous;
      if (_last == nullptr) {
        _first = nullptr;
      }
    }
  }

  ~List() = default;

private:
  std::shared_ptr<Cell<Data>> _first;
  std::shared_ptr<Cell<Data>> _last;
};

#endif //TRANSPORT_LIST_HPP
