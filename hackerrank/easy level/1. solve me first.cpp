// link to question - https://www.hackerrank.com/challenges/solve-me-first/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solveMeFirst(int a, int b) {
    // Hint: Type return a+b; below
  int s;
    s=a+b;
    return s;
}

int main() {
    int num1, num2;
    int sum;
    cin>>num1>>num2;
    sum = solveMeFirst(num1,num2);
    cout<<sum;
    return 0;
}