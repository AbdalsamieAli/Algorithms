#!/usr/bin/env python3

"""
program to calculate per unit value for given circuit.
Input : 
    base_s -> base power in VA
    base_v -> base voltage in V 
    v -> actual voltage in Volt
    i -> actual current in Amps
    z -> acutal impedance in Ohm
Output :
    i -> current in per unit
    v -> voltage in per unit
    z -> impedance in per unit

"""

def pu(base_s, base_v, v=0, i=0, z=0):
    # calculating the base current and impedance
    base_i = base_s / base_v
    base_z = (base_v * base_v)  / base_s
    

    # calculating per unit values 
    v_pu = v / base_v
    i_pu = i / base_i
    z_pu = z / base_z

    # return per unit values 
    return v_pu, i_pu, z_pu

def main():
    base_s = 10000
    base_v = 240
    v = 240
    i = 24
    z = (9.88 - 1.54j)
    v_pu, i_pu, z_pu = pu(base_s, base_v, v, i, z)

    print(f"V = {v_pu} per unit \nI = {i_pu} per unit \nZ = {z_pu} per unit")


if __name__ == "__main__":
    
    main()
