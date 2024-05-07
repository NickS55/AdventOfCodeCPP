// Part 2 -> A gear is any * symbol that is adjacent to exactly two part
// numbers. Its gear ratio is the result of multiplying those two numbers
// together. Sum all the gears.

#include "utils.h"
#include <cctype>
#include <iostream>
#include <ostream>

template <typename T> bool getHasStar(const T &input, int r, int c) {
  for (int i{r - 1}; i <= r + 1; i++) {
    for (int j{c - 1}; j <= c + 1; j++) {
      if (input[i][j] == '*') {
        return true;
      }
    }
  }
  return false;
}

int charToInt(char c) { return c - '0'; }

template <typename T> auto part2(const T &input) {
  auto numRows{input.size()};
  auto numCols{input[0].size()};

  struct Number {
    int row;
    int col;
    int len;
    int num;
  };

  vector<Number> numbers;
  // get numbers and if they are attached to a gear
  for (int i{0}; i < numRows; i++) {
    int num = 0;
    int len{0};
    bool hasStar{false};
    for (int j{0}; j < numCols; j++) {
      auto curIndex{input[i][j]};
      if (isdigit(input[i][j])) {
        num *= 10;
        num += charToInt(curIndex);
        len += 1;
        hasStar |= getHasStar(input, i, j);
      } else {
        if (hasStar) {
          numbers.push_back(Number{i, j, len, num});
        }
        num = 0;
        len = 0;
        hasStar = false;
      }
    }
  }

  // get all of the locations of gears
  using Gear = pair<int, int>;
  map<Gear, vector<int>> gears;
  for (int i{0}; i < numRows; i++) {
    for (int j{0}; j < numCols; j++) {
      if (input[i][j] == '*') {
        gears[{i, j}] = {};
      }
    }
  }

  // get all of the numbers attached to gears
  for (auto n : numbers) {
    for (int i{n.row - 1}; i < n.row + 2; i++) {
      for (int j{n.col - n.len - 1}; j < n.col + 1; j++) {
        if (input[i][j] == '*') {
          gears[{i, j}].push_back(n.num);
        }
      }
    }
  }

  // for (const Number &num : numbers) {
  //   std::cout << "Row: " << num.row << ", ";
  //   std::cout << "Column: " << num.col << ", ";
  //   std::cout << "Length: " << num.len << ", ";
  //   std::cout << "Number: " << num.num << std::endl;
  // }

  // total all the gear values where a gear is any * with exactly two numbers
  // and its value is the numbers multiplied together
  int total{0};
  for (auto [k, v] : gears) {
    if (v.size() == 2) {
      cout << v[0] << ' ' << v[1] << '\n';
      total += v[0] * v[1];
      // cout << total << '\n';
    }
  }
  return total;
}

void run(const char *filename) {
  auto lines = aoc::read_lines(filename, aoc::Blanks::Suppress);

  // Extend the data with a border of '.' to make the tests on adjacent
  // symbols simpler.
  string blank(lines[0].size() + 2, '.');
  vector<string> rows;
  rows.push_back(blank);
  for (auto line : lines)
    rows.push_back("." + line + ".");
  rows.push_back(blank);

  // auto p1 = part1(rows);
  // cout << "Part1: " << p1 << '\n';

  auto p2 = part2(rows);
  cout << "Part2: " << p2 << '\n';
}

int main(int argc, char **argv) {
  aoc::timer timer;
  try {
    if (argc < 2) {
      cout << "Provide input file name\n";
      return -1;
    }

    fs::path path{argv[1]};
    if (!fs::is_regular_file(path)) {
      cout << "Path '" << argv[1] << "' does not exist or is not a file\n";
      return -1;
    }

    run(argv[1]);
  } catch (std::exception &e) {
    cout << e.what();
  }
}
