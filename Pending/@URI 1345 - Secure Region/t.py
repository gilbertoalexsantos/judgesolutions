import numpy as np
import matplotlib.pyplot as plt
import pylab
import sys

pylab.grid(True)

r = raw_input().split(" ")
qt = int(r[0])
for i in range(qt):
    r = raw_input().split(" ")
    x = int(r[0]); y = int(r[1])
    plt.scatter(x,y)

pylab.show()
