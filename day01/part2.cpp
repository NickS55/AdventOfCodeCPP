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

bool isWordEqualToNum(std::string input, std::string target, int index) {
  int targetLen(target.length());
  std::string subInput(input.substr(index, targetLen));

  if (subInput == target) {
    return true;
  }
  return false;
}

int getWordNum(std::string input, int index) {
  if (isWordEqualToNum(input, "one", index)) {
    return 1;
  } else if (isWordEqualToNum(input, "two", index)) {
    return 2;
  } else if (isWordEqualToNum(input, "three", index)) {
    return 3;
  } else if (isWordEqualToNum(input, "four", index)) {
    return 4;
  } else if (isWordEqualToNum(input, "five", index)) {
    return 5;
  } else if (isWordEqualToNum(input, "six", index)) {
    return 6;
  } else if (isWordEqualToNum(input, "seven", index)) {
    return 7;
  } else if (isWordEqualToNum(input, "eight", index)) {
    return 8;
  } else if (isWordEqualToNum(input, "nine", index)) {
    return 9;
  } else if (isWordEqualToNum(input, "zero", index)) {
    return 0;
  }
  return -1;
}

int getFirstNum(std::string string) {
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

int getLastNum(std::string string) {
  int len(string.length());
  int index = len;
  while (index--) {
    if (std::isdigit(string[index])) {
      return getNum(string[index]);
    }

    int wordNum(getWordNum(string, index));
    if (wordNum != -1) {
      return wordNum;
    }
  }
  return -1;
}

int main() {
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
