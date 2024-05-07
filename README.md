# AdventOfCodeCPP

This is my personal repository containing original solutions for [2023 Advent of Code](https://adventofcode.com/2023/about), written in C++.

The repository includes a build script, inputs, code, and answers.

***While these solutions work, I would not suggest using them for reference. I am using Advent of Code problems to help me learn C++.*** 

## How to Run on Mac - Days 1 and 2
1. Install G++ via Homebrew: `$ brew install gcc`
2. Run the `gccp.sh` script to compile programs in C++ V17 in debug mode:

   ```bash
   $ pwd
   AdventOfCodeCPP/Day1
   $ sh ../gccp.sh day1.cpp
   $ ./a.out
   ~ANSWER~ 
   ```

## How to Run on Mac - Days 3+ 
### After completing the first set of instructions...

0. $ brew install cmake
1. $ cd < dayXX > 
2. $ cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON .
3. $ cmake --build . 
4. $ ./< dayXX > <inputFile.txt>

## Completed
- Day 1 - Part 1, Part 2 
- Day 2 - Part 1, Part 2 
- Day 3 - Part 1, Part 2
