#ifndef TRANSPORT_CELL_HPP
#define TRANSPORT_CELL_HPP

#include <iostream>
#include <memory>

template<typename Data>
class List;

template<typename Data>
class Cell {
public:
  Cell(const std::shared_ptr<Data> &data, const std::shared_ptr<Cell> &previous, const std::shared_ptr<Cell> &next)
    : _data(data), _previous(previous), _next(next) {
  }

  ~Cell() = default;

  const std::shared_ptr<Data> &data() const { return _data; };

  const std::shared_ptr<Cell> &next() const { return _next; }

  const std::shared_ptr<Cell> &previous() const { return _previous; }

private:
  friend class List<Data>;

  std::shared_ptr<Data> _data;
  std::shared_ptr<Cell> _next;
  std::shared_ptr<Cell> _previous;
};

#endif //TRANSPORT_CELL_HPP
