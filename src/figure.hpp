#pragma once
#include <cmath>
#include <iostream>
#include <vector>

namespace chessFigure {
using cell = std::pair<char, char>;

class Figure {
 public:
  explicit Figure(cell pos) : m_pos(pos) {}
  Figure(Figure const &other) { *this = other; }
  Figure(Figure &&other) { *this = std::move(other); }
  Figure &operator=(Figure const &other) {
    m_pos = other.m_pos;
    return *this;
  }
  Figure &operator=(Figure &&other) {
    if (this != &other) {
      std::swap(m_pos, other.m_pos);
    }
    return *this;
  }
  //
  virtual bool IsMovePossible(cell const &new_pos) = 0;
  void SetPos(cell const &pos) { m_pos = pos; }
  cell GetPos() const { return m_pos; }

 protected:
  cell m_pos;
};

class Pawn : public Figure {
 public:
  Pawn(cell pos) : Figure(pos) {}
  Pawn(Pawn const &other) : Figure(other) {}
  Pawn(Pawn &&other) : Figure(other) {}
  Pawn &operator=(Pawn const &other) {
    Figure::operator=(other);
    return *this;
  }
  Pawn &operator=(Pawn &&other) {
    Figure::operator=(std::move(other));
    return *this;
  }
  //
  bool IsMovePossible(cell const &pos) override {
    if (this->m_pos != pos) {
      if ((this->m_pos.first == 1 || this->m_pos.first == 6) &&
          (abs(pos.first - this->m_pos.first) == 2) &&
          (pos.second - this->m_pos.second) == 0) {
        return true;
      } else if (abs(pos.first - this->m_pos.first) == 1 &&
                 abs(pos.second - this->m_pos.second) <= 1) {
        return true;
      }
    }
    return false;
  }
};

class Rook : public Figure {
 public:
  explicit Rook(cell pos) : Figure(pos) {}
  Rook(Rook const &other) : Figure(other) {}
  Rook(Rook &&other) : Figure(other) {}
  Rook &operator=(Rook const &other) {
    Figure::operator=(other);
    return *this;
  }
  Rook &operator=(Rook &&other) {
    Figure::operator=(std::move(other));
    return *this;
  }
  //
  bool IsMovePossible(cell const &pos) override {
    if (this->m_pos != pos &&
        (this->m_pos.first == pos.first || this->m_pos.second == pos.second))
      return true;
    else
      return false;
  }
};

class Knight : public Figure {
 public:
  explicit Knight(cell pos) : Figure(pos) {}
  Knight(Knight const &other) : Figure(other) {}
  Knight(Knight &&other) : Figure(other) {}
  Knight &operator=(Knight const &other) {
    Figure::operator=(other);
    return *this;
  }
  Knight &operator=(Knight &&other) {
    Figure::operator=(std::move(other));
    return *this;
  }
  //
  bool IsMovePossible(cell const &pos) override {
    cell slide{abs(this->m_pos.first - pos.first),
               abs(this->m_pos.second - pos.second)};
    if ((slide.first == 1 && slide.second == 2) ||
        (slide.first == 2 && slide.second == 1))
      return true;
    else
      return false;
  }
};

class Bishop : public Figure {
 public:
  explicit Bishop(cell pos) : Figure(pos) {}
  Bishop(Bishop const &other) : Figure(other) {}
  Bishop(Bishop &&other) : Figure(other) {}
  Bishop &operator=(Bishop const &other) {
    Figure::operator=(other);
    return *this;
  }
  Bishop &operator=(Bishop &&other) {
    Figure::operator=(std::move(other));
    return *this;
  }
  //
  bool IsMovePossible(cell const &pos) override {
    cell slide{abs(this->m_pos.first - pos.first),
               abs(this->m_pos.second - pos.second)};
    if (this->m_pos != pos && slide.first == slide.second)
      return true;
    else
      return false;
  }
};

class King : public Figure {
 public:
  explicit King(cell pos) : Figure(pos) {}
  King(King const &other) : Figure(other) {}
  King(King &&other) : Figure(other) {}
  King &operator=(King const &other) {
    Figure::operator=(other);
    return *this;
  }
  King &operator=(King &&other) {
    Figure::operator=(std::move(other));
    return *this;
  }
  //
  bool IsMovePossible(cell const &pos) override {
    cell slide{abs(this->m_pos.first - pos.first),
               abs(this->m_pos.second - pos.second)};
    if (this->m_pos != pos && slide.first <= 1 && slide.second <= 1)
      return true;
    else
      return false;
  }
};

class Queen : public Figure {
 public:
  explicit Queen(cell pos) : Figure(pos) {}
  Queen(Queen const &other) : Figure(other) {}
  Queen(Queen &&other) : Figure(other) {}
  Queen &operator=(Queen const &other) {
    Figure::operator=(other);
    return *this;
  }
  Queen &operator=(Queen &&other) {
    Figure::operator=(std::move(other));
    return *this;
  }
  //
  bool IsMovePossible(cell const &pos) override {
    // ...
    cell slide{abs(this->m_pos.first - pos.first),
               abs(this->m_pos.second - pos.second)};
    if (this->m_pos != pos &&
        ((slide.first == slide.second) || !slide.first || !slide.second))
      return true;
    else
      return false;
  }
};

}  // namespace chessFigure