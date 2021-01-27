main.out: Sudoku.cpp main.cpp
	@$(CXX) -g -Wall $(CXXFLAGS) $^ -o $@

test.out: Sudoku.cpp test_driver.cpp
	@$(CXX) -g -Wall $(CXXFLAGS) $^ -o $@

format:
	@clang-format -i *.cpp *.h

clean:
	@rm -f *.out

impl: SudokuImpl.cpp test_driver.cpp
	@$(CXX) -g -Wall $(CXXFLAGS) $^ -o test.out
