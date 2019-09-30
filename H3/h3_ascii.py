#!/usr/bin/python

import numpy as np, matplotlib.pyplot as plt, sys

def main(argv):
   inputfile = sys.argv[1];
   M=np.loadtxt(inputfile, skiprows=2)
   plt.imshow(M, cmap = plt.cm.gray)
   plt.show()

if __name__ == "__main__":
   main(sys.argv[1:])
