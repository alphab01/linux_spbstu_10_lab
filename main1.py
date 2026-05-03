import ctypes
import os
import random

lib = os.path.abspath("lib1.so")
l = ctypes.CDLL(lib)

l.sorting.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]
l.sorting.restype = ctypes.POINTER(ctypes.c_int)

test = ctypes.c_int*20000

q = []
for i in range(0, 20000):
  q.append(random.randint(0, 20000))

a = test(*q)

a = l.sorting(a, len(a))