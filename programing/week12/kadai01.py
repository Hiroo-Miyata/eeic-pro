import mylib.mylib as mylib
import numpy as np

print(mylib.nintegrate(lambda x: x + x ** 2, 0, 10, 100))
