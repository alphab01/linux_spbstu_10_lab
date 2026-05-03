#include <iostream>
#include <vector>

extern "C" {
  int* sorting(int* c, int s) {
    for (int i = 0; i < s; ++i) {
      for (int j = 0; j < s - 1; ++j) {
        if (c[j] > c[j + 1]) {
          std::swap(c[j], c[j + 1]);
        }
      }
    }
    /*
    for (int i = 0; i < s; ++i) {
      std::cout << c[i] << (i == s - 1 ? '\n' : ' ');
    }
    */
    std::cout << "end";
    return c;
  }
}