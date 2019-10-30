# https://www.hackerrank.com/challenges/nested-list/problem

if __name__ == '__main__':
    n = []
    s = []
    for _ in range(int(input())):
        name = input()
        score = float(input())
        n.append([name,score])
        s.append(score)

    l = min(s)
    while l in s:
        s.remove(l)
    l = min(s)
    n.sort()
    for a,b in n:
        if b == l:
            print(a) 
'''
l = min(s)

while min(s) ==l:
    i = s.index(l)
    s.remove(l)
    n.remove(n[i])

l = min(s)
f = []
j = 0
for score in s:
    if score == l:
        f.append(n[j])
    j += 1

f.sort()
for names in f:
    print(names)
    
'''
