"""
Program To Find The Value Of Capacitance Or Inductance Necessary To Increase The Power Factor Of An AC Load.

Input: 
    V(rms) -> The voltage in rms value.
    f      -> The frequency (Hz).
    p      -> The power of the load (Watt).
    pf1    -> The load power factor.
    pf2    -> The intended power factor.

Output:
    X  -> The value of capacitance or inductance.

"""

import math
import numpy as np


def main():
    v = 120
    f = 60
    p = 4000
    pf1 = 0.8
    pf2 = 0.95

    x, y = reactance(v, f, p, pf1, pf2)

    print(f"The value of the required shunt {y} is {x}")



def reactance(v, f, p, pf1, pf2):
    w = 2 * math.pi * f
    # finding the angles o1, o2
    o1 = np.arccos(pf1)
    o2 = np.arccos(pf2)
    
    # calculate reactive power of the load
    q1 = p * math.tan(o1)

    if q1 == 0:
        # resistance load 
        y = "Rrestance"
        return (0, y)
    elif q1 > 0:
        # indective load
        q = q1 - (p * math.tan(o2));
        x = q /(w * v**2)
        y = "Capacitance"
    else:
        # capacitive load
        q = q1 - (p * math.tan(o2));                      x = (v**2) /(w * q)
        y = "Inductance"

    return (x, y)




if __name__ == "__main__" :

    main()


