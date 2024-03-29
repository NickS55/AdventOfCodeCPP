// Day 2: Part 1
// Day 2: part 2

#include <cstddef>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <string_view>

int toInt(char character) {
  if (character != ' ') {
    return character - '0';
  }
  return 0;
}

int getMaxValue(std::string string, std::string_view target) {
  int maxValue{};
  std::size_t targetLocation{string.find(target)};

  // when there are no more targets left, target location is greater than string
  // length
  while (targetLocation < string.length()) {
    int curValue{};

    int firstDigit{toInt(string[targetLocation - 2])};
    int secondDigit{toInt(string[targetLocation - 3])};

    curValue = firstDigit + secondDigit * 10;

    maxValue = curValue > maxValue ? curValue : maxValue;

    string = string.substr(targetLocation + 1);

    targetLocation = string.find(target);
  }
  return maxValue;
}

int getMaxGreenValue(std::string string) {
  return getMaxValue(string, "green");
}

int getMaxRedValue(std::string string) { return getMaxValue(string, "red"); }

int getMaxBlueValue(std::string string) { return getMaxValue(string, "blue"); }

bool isValidGame(int red, int green, int blue) {
  constexpr int maxNumGreen{13};
  constexpr int maxNumBlue{14};
  constexpr int maxNumRed{12};

  return green <= maxNumGreen && blue <= maxNumBlue && red <= maxNumRed ? true
                                                                        : false;
}

int main() {
  int gameSum{0};
  int powerSum{0};

  std::ifstream File("input.txt");
  std::string textLine{};

  int gameNumber{1};

  while (getline(File, textLine)) {

    const int curMaxRed{getMaxRedValue(textLine)};
    const int curMaxGreen{getMaxGreenValue(textLine)};
    const int curMaxBlue{getMaxBlueValue(textLine)};

    gameSum = isValidGame(curMaxRed, curMaxGreen, curMaxBlue)
                  ? gameSum + gameNumber
                  : gameSum;

    powerSum += curMaxBlue * curMaxRed * curMaxGreen;
    gameNumber += 1;
  }

  std::cout << "Part1 : " << gameSum;
  std::cout << "Part2 : " << powerSum << "\n";

  return 0;
}
