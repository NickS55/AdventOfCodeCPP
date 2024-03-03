// Day 3, part 1
#include <fstream>
#include <iostream>
#include <string>

int getCharValue(char character) {
  int ichar{(int)character - '0'};
  if (ichar >= 0 && ichar < 10) {
    return ichar;
  }
  return -1;
}

bool getIsSymbol(char character) {
  if (character != '.' && (int)character != 0 &&
      getCharValue(character) == -1) {
    return true;
  }
  return false;
}

int getMinIndex(int index) { return index < 0 ? 0 : index; }

bool isTouchingSymbol(std::string cur, std::string next, std::string prev,
                      int leftIndex, int RightIndex) {
  while (leftIndex <= RightIndex) {
    if (next.length() && getIsSymbol(next[leftIndex])) {
      return true;
    }
    if (prev.length() && getIsSymbol(prev[leftIndex])) {
      return true;
    }
    if (getIsSymbol(cur[leftIndex])) {
      return true;
    }
    leftIndex += 1;
  }
  return false;
}

int getSumEngineValues(std::string cur, std::string next, std::string prev) {
  int sum{};
  int i{};

  int curSum{};
  int leftIndex{-1};
  int rightIndex{-1};
  while (i <= cur.length()) {
    int curValue{getCharValue(cur[i])};
    if (curValue > -1) {
      curSum *= 10;
      curSum += curValue;
      leftIndex = leftIndex < 0 ? getMinIndex(i - 1) : leftIndex;
      rightIndex = i + 1 > cur.length() ? cur.length() : i + 1;
    }
    if ((curValue < 0 || i == cur.length())) {
      if (leftIndex >= 0 &&
          isTouchingSymbol(cur, next, prev, leftIndex, rightIndex)) {
        sum += curSum;
      }
      leftIndex = -1;
      rightIndex = -1;
      curSum = 0;
    }
    i++;
  }
  return sum;
}

int main(int argc, char *argv[]) {
  using std::cout;
  using std::ifstream;
  using std::string;

  ifstream File(argv[1]);

  string prevText{};
  string curText{};
  string nextText{};
  string newText{};

  int lines{};

  int sum{};
  getline(File, curText);
  getline(File, nextText);
  sum += getSumEngineValues(curText, nextText, prevText);
  lines += 1;
  while (getline(File, newText)) {
    prevText = curText;
    curText = nextText;
    nextText = newText;
    sum += getSumEngineValues(curText, nextText, prevText);
    lines += 1;
  }
  sum += getSumEngineValues(nextText, nextText, curText);
  lines += 1;
  cout << sum << "\n";
  File.close();
  return 0;
}
