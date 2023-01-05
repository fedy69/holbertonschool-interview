#!/usr/bin/python3
"""Minimum Operations"""


def minOperations(n: int) -> int:
    if n == 0:
        return 0
    operations = 0
    
    while n & (n - 1) != 0:
        n -= n & -n
        operations += 1
    
    return operations + (n.bit_length() - 1)
