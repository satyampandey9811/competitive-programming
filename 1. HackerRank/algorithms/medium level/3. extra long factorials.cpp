// link to question - https://www.hackerrank.com/challenges/extra-long-factorials/problem

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the extraLongFactorials function below.

def extraLongFactorials(n):
    ans = 1
    ct = 1
    while ct <= n:
        ans *= ct
        ct += 1

    print(ans)    

if __name__ == '__main__':
    n = int(input())

    extraLongFactorials(n)
