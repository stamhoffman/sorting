#include "sorting.h"

namespace sorted {

bool Bubble(std::vector<int> data) {
  while (true) {
    bool flag = false;
    for (auto itr = data.begin(); itr != data.end(); itr++) {
      if (itr != data.end()) {
        auto cur = *itr;
        if (*itr > *(itr + 1)) {
          *itr = *(itr + 1);
          *(itr + 1) = cur;
          flag = true;
        }
      }
    }
    if (flag != true) return true;
  }
  return false;
}

bool Bubble_v1(int *begin, int *end) {
  while (true) {
    bool flag = false;
    for (auto itr = begin; itr != end + 1; itr++) {
      if (itr != end + 1) {
        auto cur = *itr;
        if (*itr > *(itr + 1)) {
          *itr = *(itr + 1);
          *(itr + 1) = cur;
          flag = true;
        }
      }
    }
    if (flag != true) return true;
  }
  return false;
}

void ShakerSort(std::vector<int> &data) {
  auto end_itr = data.end();
  auto cur_itr = data.end();
  bool flag = false;

  while (true) {
    flag = false;
    end_itr = cur_itr;
    for (auto itr = data.begin(); itr != end_itr; itr++) {
      auto buffer = *itr;
      if (itr != end_itr) {
        if (*itr > *(itr + 1)) {
          *itr = *(itr + 1);
          *(itr + 1) = buffer;
          cur_itr = itr + 1;
          flag = true;
        }
      }
    }
    if (flag == false) return;
  }
}


void QuickSorted(const std::vector<int>::iterator begin,
                 const std::vector<int>::iterator end, std::vector<int> &data) {
  std::vector<int>::iterator left_itr = begin;
  std::vector<int>::iterator right_itr = end - 1;

  if (std::distance(begin, end) == 1) {
    if (*left_itr == *right_itr) {
      left_itr--;
    }
    if (*left_itr > *right_itr) {
      std::swap(*left_itr, *right_itr);
    }
    return;
  }

  if (std::distance(begin, end) == 2) {
    if (*left_itr > *right_itr) {
      std::swap(*left_itr, *right_itr);
    }
    return;
  }

  while (left_itr < right_itr) {
    while (*left_itr <= *begin && left_itr < right_itr) {
      left_itr++;
    }
    while (*right_itr >= *begin && left_itr < right_itr) {
      right_itr--;
    }
    if (*left_itr > *right_itr) {
      std::swap(*left_itr, *right_itr);
    }
  }
  left_itr--;
  std::swap(*left_itr, *begin);
  if (left_itr > begin) {
    QuickSorted(begin, left_itr, data);
  }
  if (right_itr > left_itr) {
    QuickSorted(right_itr, end, data);
  }
}

}  // namespace sorted
