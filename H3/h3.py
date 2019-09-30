#!/usr/bin/python

import numpy as np, matplotlib.pyplot as plt, sys

def main(argv):
   inputfile = sys.argv[1];
   M=np.fromfile(inputfile, "int32", 2)
   M2=np.fromfile(inputfile, "uint8")
   M2=M2[8:]
   pic=M2.reshape(M[0],M[1])
   plt.imshow(pic.transpose(), cmap = plt.cm.gray)
   plt.show()

if __name__ == "__main__":
   main(sys.argv[1:])
