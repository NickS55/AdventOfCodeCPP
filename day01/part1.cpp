#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

// #define ENABLE_DEBUG // comment out to disable debugging

std::string textLine;
int total{};

// get number by subtracting ascii values
// note: only works for single digit numbers
int getNum(char x) { return (x - '0'); }

int getFirstNum(std::string string) {
  int index{0};
  int len(string.length());
  while (index != len) {
    if (std::isdigit(string[index])) {
      return getNum(string[index]);
    }
    index++;
  }
  return -1;
}

int getLastNum(std::string string) {
  int len(string.length());
  int curIndex = len;
  while (curIndex--) {
    if (std::isdigit(string[curIndex])) {
      return getNum(string[curIndex]);
    }
  }
  return -1;
}

int main() {
  std::ifstream File("input.txt");

  while (getline(File, textLine)) {
    int firstNum{};
    int lastNum{};

    firstNum = getFirstNum(textLine);

#ifdef ENABLE_DEBUG
    std::cout << firstNum;
#endif // DEBUG
    //
    lastNum = getLastNum(textLine);

#ifdef ENABLE_DEBUG
    std::cout << lastNum << std::endl;
#endif // DEBUG

    total += firstNum * 10 + lastNum;
  }

  std::cout << total << std::endl;
  return 0;
}
