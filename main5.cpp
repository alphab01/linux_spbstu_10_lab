#include <immintrin.h>
#include <algorithm>
#include <iostream>
#include <omp.h>

extern "C" {
  int* sorting(int* c, int s) {
    for (int i = s - 1; i > 0; --i) {
      int max_val = c[0];
      int max_idx = 0;
      #pragma omp parallel
      {
        int local_max = c[0];
        int local_idx = 0;
        #pragma omp for nowait
        for (int k = 0; k <= i; ++k) {
          if (c[k] > local_max) {
            local_max = c[k];
            local_idx = k;
          }
        }
        #pragma omp critical
        {
          if (local_max > max_val) {
            max_val = local_max;
            max_idx = local_idx;
          }
        }
      }
      std::swap(c[max_idx], c[i]);
    }
    std::cout << "end" << std::endl;
    return c;
  }
}
