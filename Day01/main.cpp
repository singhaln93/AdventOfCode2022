/**
 * @file main.cpp
 * @author Neeraj Singhal
 */
#include "lib/util.h"

#include <iostream>
#include <string>

// challenge: https://adventofcode.com/2022/day/1
#define ENABLE_TEST true
#define SELECT_CASE 1

#if ENABLE_TEST
std::string fileName{ "../inputs/testData.txt" };
#else
std::string fileName{ "../inputs/actualData.txt" };
#endif

int main() {
  int result{ 0 };
  std::ifstream inFile;
  std::vector<int> vector;
  std::vector<int> sum;

  std::cout << "-- Case " << SELECT_CASE << " --\n";
#if SELECT_CASE == 1
  // TODO: Find the Elf with maximum calories and number of calories he has

  // Get the contents of file in a vector
  [[maybe_unused]] bool ret = getFileContentsInVector(vector, fileName);
  printVector<int>(vector);
  result = findMaxValue(vector);

#else

#endif
  std::cout << "Result: " << result << "\n";
  return 0;
}
