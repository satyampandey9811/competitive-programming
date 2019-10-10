// link to question - https://www.hackerrank.com/challenges/service-lane/problem

#include <bits/stdc++.h>

using namespace std;

void serviceLane(vector<int> a, vector<vector<int>> b, int m, int n) {
  for (int i = 0; i < n; i++) {
    int x = b[i][0], y = b[i][1], min = a[x];
    for (int i = x; i <= y; i++) {
      if (min > a[i])
        min = a[i];
    }
    cout << min << endl;
  }
}

int main() {
  int m, n;
  cin >> m >> n;
  vector<int> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  vector<vector<int>> b(n, vector<int>(2));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> b[i][j];
    }
  }
  serviceLane(a, b, m, n);
  system("pause");
}
