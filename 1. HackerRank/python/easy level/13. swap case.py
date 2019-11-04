# link to question - https://www.hackerrank.com/challenges/swap-case/problem

def swap_case(s):
    a = ""
    for num in range(len(s)):
        if s[num] >= 'a' and s[num] <= 'z':
            a += s[num].upper()
        elif s[num] >= 'A'  and s[num] <= 'Z':
            a += s[num].lower()
        else:
            a += s[num]
    return a

