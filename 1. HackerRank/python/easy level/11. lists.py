# https://www.hackerrank.com/challenges/python-lists/problem

if __name__ == '__main__':
    n = int(input())

mylist = []
for _ in range(n):
    inputs = input().split()
    if inputs[0] == "print":
        print(mylist)
    elif inputs[0] == "sort":
        mylist.sort()
    elif inputs[0] == "pop":
        mylist.pop()
    elif inputs[0] == "reverse":
        mylist.reverse()
    elif inputs[0] == "append":
        e = int(inputs[1])
        mylist.append(e)
    elif inputs[0] == "remove":
        e = int(inputs[1])
        mylist.remove(e)
    else:
        i = int(inputs[1])
        e = int(inputs[2])
        mylist.insert(i,e)
