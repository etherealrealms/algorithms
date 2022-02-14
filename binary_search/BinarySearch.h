//
// Created by Michael Moncada on 2022-02-09.
//

#ifndef BINARY_SEARCH__BINARYSEARCH_H_
#define BINARY_SEARCH__BINARYSEARCH_H_

#include <vector>

using std::vector;

template<class T>
class BinarySearch {
 private:
  vector<T> haystack {};
  unsigned int executionCount;

 public:
  BinarySearch(vector<T> h): haystack{h}, executionCount {}  {
    std::sort(haystack.begin(), haystack.end());
  }

  bool search(const T needle) {
    unsigned int low = 0;
    unsigned int high = haystack.size();
    bool foundItem {};
    executionCount = 0;

    int mid = -1;

    while (low < high || mid != 0) {
      executionCount++;
      mid = low + ((high - low) / 2);
      T item = haystack.at(mid);

      if (item < needle) {
        low = mid;
      } else if (item > needle) {
        high = mid;
      } else {
        foundItem = true;
        break;
      }

    }

    return foundItem;
  }

  void printList() const {
    for (const T item: haystack) {
      std::cout << item << std::endl;
    }
  }

  unsigned int getExecutionCount() const {
    return executionCount;
  }
};

#endif //BINARY_SEARCH__BINARYSEARCH_H_
