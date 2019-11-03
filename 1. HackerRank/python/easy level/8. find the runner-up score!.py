# link to question - https://www.hackerrank.com/challenges/find-second-maximum-number-in-a-list/problem

if __name__ == '__main__':
    n = int(raw_input())
    arr = map(int, raw_input().split())

a = max(arr)
while(a in arr):
    arr.remove(a)
a = max(arr)
print(a)


