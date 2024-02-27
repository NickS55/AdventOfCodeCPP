#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

// #define ENABLE_DEBUG // comment out to disable debugging

// get number by subtracting ascii values
// note: only works for single digit numbers
int getNum(char x) { return (x - '0'); }

int getFirstNum(std::string_view string) {
  int index{0};
  const int len(string.length());
  while (index != len) {
    if (std::isdigit(string[index])) {
      return getNum(string[index]);
    }
    index++;
  }
  return -1;
}

int getLastNum(std::string_view string) {
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
  std::string textLine;
  int total{};

  std::ifstream File("input.txt");

  while (getline(File, textLine)) {
    int lastNum{};

    int firstNum{};
    getFirstNum(textLine);

#ifdef ENABLE_DEBUG
    std::cout << firstNum;
#endif // DEBUG

    lastNum = getLastNum(textLine);

#ifdef ENABLE_DEBUG
    std::cout << lastNum << std::endl;
#endif // DEBUG

    total += firstNum * 10 + lastNum;
  }

  std::cout << total << std::endl;
  return 0;
}
