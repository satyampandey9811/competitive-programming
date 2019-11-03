# link to question - https://www.hackerrank.com/challenges/finding-the-percentage/problem

if __name__ == '__main__':
    n = int(input())
    student_marks = {}
    for _ in range(n):
        name, *line = input().split()
        scores = list(map(float, line))
        student_marks[name] = scores
    query_name = input()

mylist = student_marks[query_name]
sum = 0
for i in mylist:
    sum += i
sum /= 3
print("{:1.2f}".format(sum))
    