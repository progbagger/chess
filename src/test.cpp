#include <random>

#include "figure.hpp"

void sheesh(chessFigure::Figure *sh) {
  std::random_device dev;
  std::mt19937 gen(dev());
  std::uniform_real_distribution<double> result(0, 7.9);
  //
  sh->SetPos({result(gen), result(gen)});
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      if (sh->GetPos().first == i && sh->GetPos().second == j) {
        std::cout << "X ";
      } else {
        if (sh->IsMovePossible({i, j})) {
          std::cout << "\033[0;32m"
                    << "1 "
                    << "\e[0m";
        } else {
          std::cout << "* ";
        }
      }
    }
    std::cout << std::endl;
  }
}

int main() {
  chessFigure::Rook r({0, 0});
  chessFigure::Knight k({0, 1});
  chessFigure::Bishop b({0, 2});
  chessFigure::Queen q({0, 3});
  chessFigure::King kk({0, 4});
  chessFigure::Pawn p({0, 0});

  // std::cout << r.IsMovePossible({3, 0}) << " {3 0} " << r.IsMovePossible({0,
  // 7})
  //           << " {0 7} " << r.IsMovePossible({1, 1}) << " {1 1} " <<
  //           std::endl;

  // sheesh(&b);
  sheesh(&q);
}