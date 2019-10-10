// link to question - https://www.hackerrank.com/challenges/a-very-big-sum/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the aVeryBigSum function below.
long aVeryBigSum(vector<long> ar) {
  long sum = 0;
  int n = ar.size();
  for (int i = 0; i < n; i++) {
    sum += ar[i];
  }
  return sum;
}

int main() {
  int n;
  cin >> n;
  vector<long> v(10);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  cout << aVeryBigSum(v);
  system("pause");
}
