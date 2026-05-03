import ctypes
import os
import random

lib = os.path.abspath("lib1.so")
l = ctypes.CDLL(lib)

l.sorting.argtypes = [ctypes.c_int*9999, ctypes.c_int]
l.sorting.restype = ctypes.c_int*9999

test = ctypes.c_int*9999

q = []
for i in range(0, 9999):
  q.append(random.randint(0, 9999))

a = test(*q)

a = l.sorting(a, len(a))