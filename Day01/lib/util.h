/**
 * @file util.h
 * @author Neeraj Singhal
 */

#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

/**
 * @brief     get the file contents in vector
 * @tparam T  template type parameter
 * @param[in] vector   input vector
 * @param[in] fileName filename
 * @return    true, if successful otherwise false
 */
template<typename T>
[[nodiscard("Don't ignore the return value")]] bool
  getFileContentsInVector(std::vector<T> &vector,
    const std::string &fileName) {
  std::string line;
  std::ifstream inFile;
  inFile.open(fileName);
  if (!inFile) {
    std::cout << "Cannot open the File : " << fileName << std::endl;
    return false;
  }

  while (inFile >> line) {
    std::stringstream ss(line);
    for (int i; ss >> i;) {
      vector.emplace_back(i);
      if (ss.peek() == ',')
        ss.ignore();
    }
  }
  // Close The File
  inFile.close();
  return true;
}

/**
 * @brief     displays contents of vector
 * @tparam T  template type parameter
 * @param[in] v input vector
 */
template<typename T>
void printVector(const std::vector<T> &v) {
  for (auto &i : v)
    std::cout << i << " ";
  std::cout << std::endl;
}

//
/**
 * @brief     find maximum value in vector
 * @tparam T  template type parameter
 * @param[in] v input vector
 * @return T  maximum value in vector
 */
template<typename T>
T findMaxValue(const std::vector<T> &v) {
  return *std::max_element(v.begin(), v.end());
}

/**
 * @brief     find minimum value in vector
 * @tparam T  template type parameter
 * @param[in] v input vector
 * @return T  minimum value in vector
 */
template<typename T>
T findMinValue(const std::vector<T> &v) {
  return *std::min_element(v.begin(), v.end());
}

/**
 * @brief    find min/max value in vector
 * @tparam T template type parameter
 * @param v  input vector
 * @return std::pair<T, T> {min,max} value in vector
 */
template<typename T>
std::pair<T, T> findMinMax(const std::vector<T> &v) {
  const auto [min, max] = std::minmax_element(v.begin(), v.end());
  return {*min, *max};
}