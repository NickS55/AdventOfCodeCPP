// Day 3, part 2
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <string_view>

struct NumInfo {
  int sum{0};
  int start{-1};
  int end{-1};
  std::string line{};
};

struct Gear {
  NumInfo part1{};
  NumInfo part2{};
};

constexpr int getMinIndex(int index) { return index < 0 ? 0 : index; }
constexpr int getMaxIndex(int i, std::string_view cur) {
  return i + 1 > cur.length() ? cur.length() : i + 1;
}

int getGearValue(int i, std::string_view cur, std::string_view next,
                 std::string_view prev) {

  std::string_view localCur{prev};
  int curI{getMinIndex(i - 1)};

  Gear newGear{};
  while (true) {

    if (isdigit(localCur[curI])) {
      NumInfo numInfo = getNumInfo(curI, localCur);
      if (newGear.part1.sum == 0) {
        newGear.part1 = numInfo;
      } else if (newGear.part2.sum == 0) {
        newGear.part2 = numInfo;
      } else {
        return 0;
      }
    }
    if (localCur == next && i == getMaxIndex(i, cur)) {
      break;
    }
  }
  return newGear.part1.sum * newGear.part2.sum;
}

int getSumEngineValues(std::string_view cur, std::string_view next,
                       std::string_view prev) {
  int sum{};
  int i{};

  while (i <= cur.length()) {
    if (cur[i] == '*') {
      sum += getGearValue(i, cur, next, prev);
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

  int sum{};
  getline(File, curText);
  getline(File, nextText);
  sum += getSumEngineValues(curText, nextText, prevText);
  while (getline(File, newText)) {
    prevText = curText;
    curText = nextText;
    nextText = newText;
    sum += getGearSumEngineValues(curText, nextText, prevText);
    cout << getGeatSumEngineValues(curText, nextText, prevText) << '\n';
  }
  // Assumes that there are no symbols on the last line (nextText).
  sum += getSumEngineValues(nextText, nextText, curText);
  cout << sum << "\n";
  File.close();
  return 0;
}
