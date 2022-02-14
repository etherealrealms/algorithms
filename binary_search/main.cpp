#include <iostream>
#include <vector>
#include <random>
#include "BinarySearch.h"

std::vector<int> *generateData(unsigned int numberOfDataPoints, unsigned int max = 100) {
  std::vector<int> *v = new std::vector<int>{};
  std::random_device dev;
  std::mt19937 rng(dev());

  for (unsigned int i = 0; i < numberOfDataPoints; i++){

    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,max); // distribution in range [0, max]

    v->push_back(dist6(rng));
  }

  return v;
}

int main() {
  std::cout << "Enter the number of test data points to look for: ";
  int numberOfDataPoints {};

  std::cin >> numberOfDataPoints;
  std::vector<int> *v = generateData(numberOfDataPoints);
  BinarySearch<int> b {*v};

  std::cout << "Enter the number to look for: ";

  int needle {};
  std::cin >> needle;
  std::cout << b.search(needle);
  std::cout << "\nSearch Execution Count: " << b.getExecutionCount() << std::endl;

  delete v;

  return 0;
}
