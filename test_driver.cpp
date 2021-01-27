#include "Sudoku.h"
#include <iostream>

int main(int argc, char *argv[]) {
  int board[81];
  for (int i = 0; i < 81; i++) {
    int val;
    std::cin >> val;
    board[i] = val;
  }

  ds::Sudoku puzzle;
  puzzle.readFrom1DArray(board);
  puzzle.solve();
  puzzle.print1D();

  return 0;
}
