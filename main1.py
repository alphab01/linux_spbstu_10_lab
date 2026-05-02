import ctypes
import os

lib = os.path.abspath("lib1.so")
l = ctypes.CDLL(lib)

l.sum.argtypes = [ctypes.c_int, ctypes.c_int]
l.sum.restypes = ctypes.c_int

print(l.sum(10, 100))