// link to question - https://www.hackerrank.com/challenges/drawing-book/problem

#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main() {
  lli n, i, j, k, l, p, count1 = 0, count2 = 0;
  cin >> n >> p;
  count1 = p / 2;
  count2 = (n - p) / 2;
  cout << min(count1, count2);
}
