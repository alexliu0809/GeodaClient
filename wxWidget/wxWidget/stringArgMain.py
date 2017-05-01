import numpy as np
import scipy
import pysal
from pysal.esda import smoothing as sm

"""
def main(f,g):

	print("Arg1: {}",format(f))
	print("Arg2: {}",format(g))
    e = np.array([30, 25, 25, 15, 33, 21, 30, 20])
    b = np.array([100, 100, 110, 90, 100, 90, 110, 90])
    print(sm.crude_age_standardization(e, b, 2))
    return 1

"""

def main(X,Y):
    print("Arg1: {}".format(X))
    print("Arg2: {}".format(Y))

    e = np.array([30, 25, 25, 15, 33, 21, 30, 20])
    f = np.array([100, 100, 110, 90, 100, 90, 110, 90])
    print(sm.crude_age_standardization(e, f, 2))

    return 1