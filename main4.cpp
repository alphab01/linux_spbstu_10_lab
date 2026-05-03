#include <immintrin.h>
#include <algorithm>
#include <iostream>

extern "C" {
  int* sorting(int* c, int s) {
    for (int i = s - 1; i > 0; --i) {
      int max_val = c[0];
      int max_idx = 0;
      int j = 0;
      if (i >= 7) {
        __m256i max_vec = _mm256_set1_epi32(c[0]);
        for (; j <= i - 8; j += 8) {
          __m256i v = _mm256_load_si256((__m256i*)&c[j]);
          max_vec = _mm256_max_epi32(max_vec, v);
        }
        alignas(32) int temp[8];
        _mm256_store_si256((__m256i*)temp, max_vec);

        for (int k = 0; k < 8; ++k) {
          if (temp[k] > max_val) max_val = temp[k];
        }
      }

      for (int k = j; k <= i; ++k) {
        if (c[k] > max_val) max_val = c[k];
      }

      for (int k = 0; k <= i; ++k) {
        if (c[k] == max_val) {
          max_idx = k;
          break;
        }
      }
      std::swap(c[max_idx], c[i]);
    }
    std::cout << "end";
    return c;
  }
}
