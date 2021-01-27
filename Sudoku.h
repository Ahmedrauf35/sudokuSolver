#ifndef __SUDOKU_H__
#define __SUDOKU_H__

#include <iostream>
#include <array>

namespace ds {

class Sudoku {
private:
 int grid[9][9];

public:
  
  Sudoku() {}

  void readFrom1DArray(int *grid);
  bool solve();
  bool isPresent(int col, int num); // comments on the .cpp 
  bool isPresentRow(int row, int num);
  bool isPresBox(int row, int col, int num);
  bool findEmpt(int& row, int& col);
  bool isValid(int row, int col, int num);


  void print1D() const {
    for (int row = 0; row < 9; row++) {
      for (int col = 0; col < 9; col++) {
        if (row != 0 || col != 0)
          std::cout << " ";
        std::cout << grid[row][col];
      }
    }
  }
};

} // namespace ds

#endif // __SUDOKU_H__