// link to question - https://www.hackerrank.com/challenges/plus-minus/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the aVeryBigSum function below.
void plusMinus(vector<int> arr) {
  float p = 0, n = 0, z = 0;
  int num = arr.size();
  for (int i = 0; i < num; i++) {
    if (arr[i] == 0)
      z++;
    else if (arr[i] > 0)
      p++;
    else
      n++;
  }
  p = p / num;
  n = n / num;
  z = z / num;
  cout << p << endl << n << endl << z;
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  plusMinus(v);
  system("pause");
}
