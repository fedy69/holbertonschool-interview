#!/usr/bin/python3
"""Minimum Operations"""


def minOperations(n: int) -> int:
    if n <= 0:
        return 0
    count = []
    i = 2
    while n > 1:
        while n % i == 0:
            count.append(i)
            n = n / i
        i += 1

    return sum(count)
