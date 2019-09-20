// link to question - https://www.hackerrank.com/challenges/diagonal-difference/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the diagonalDifference function below.
int diagonalDifference(vector<vector<int>> arr) {

  int n = arr.size(), d1 = 0, d2 = 0;
  for (int i = 0, j = 0; i < n; i++, j++)
    d1 += arr[i][j];
  for (int i = 0, j = n - 1; i < n; i++, j--)
    d2 += arr[i][j];

  return abs(d1 - d2);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i].resize(n);

        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = diagonalDifference(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
