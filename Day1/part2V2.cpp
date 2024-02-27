#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <string_view>

// #define ENABLE_DEBUG // comment out to disable debugging

// get number by subtracting ascii values
// note: only works for single digit numbers
constexpr int getNum(char x) { return (x - '0'); }

constexpr bool isStringInInput(std::string_view input, std::string_view target,
                               int index) {
  int targetLen(target.length());
  std::string_view subInput(input.substr(index, targetLen));

  if (subInput == target) {
    return true;
  }
  return false;
}

constexpr int getWordNum(std::string_view input, int index) {
  if (isStringInInput(input, "one", index)) {
    return 1;
  } else if (isStringInInput(input, "two", index)) {
    return 2;
  } else if (isStringInInput(input, "three", index)) {
    return 3;
  } else if (isStringInInput(input, "four", index)) {
    return 4;
  } else if (isStringInInput(input, "five", index)) {
    return 5;
  } else if (isStringInInput(input, "six", index)) {
    return 6;
  } else if (isStringInInput(input, "seven", index)) {
    return 7;
  } else if (isStringInInput(input, "eight", index)) {
    return 8;
  } else if (isStringInInput(input, "nine", index)) {
    return 9;
  } else if (isStringInInput(input, "zero", index)) {
    return 0;
  }
  return -1;
}

constexpr int getFirstNum(std::string_view string) {
  int index{0};
  int len(string.length());
  while (index != len) {
    if (std::isdigit(string[index])) {
      return getNum(string[index]);
    }
    int wordNum(getWordNum(string, index));
    if (wordNum != -1) {
      return wordNum;
    }
    index++;
  }
  return -1;
}

constexpr int getLastNum(std::string_view string) {
  const int len(string.length());
  int index = len;
  while (index--) {
    if (std::isdigit(string[index])) {
      return getNum(string[index]);
    }

    const int wordNum(getWordNum(string, index));
    if (wordNum != -1) {
      return wordNum;
    }
  }
  return -1;
}

int main() {
  std::string textLine;
  int total{};
  std::ifstream File("input.txt");

#ifdef ENABLE_DEBUG
  int test(getLastNum("ab5ctwo"));
  std::cout << test << std::endl;
#endif // DEBUG

  while (getline(File, textLine)) {
    int firstNum{};
    int lastNum{};

    firstNum = getFirstNum(textLine);
    lastNum = getLastNum(textLine);

    total += firstNum * 10 + lastNum;
  }

  std::cout << total << std::endl;

  return 0;
}
