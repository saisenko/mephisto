"""
Back-end connection between
Python GUI and C++ fucntionality
"""

import ctypes
import os

lib_path = os.path.join("..", "build", "lib", "libtranslator.so")
translator_lib = ctypes.CDLL(lib_path)
