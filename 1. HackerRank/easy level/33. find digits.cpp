// link to question - https://www.hackerrank.com/challenges/find-digits/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the findDigits function below.
int findDigits(int n) {

  int rem, s = 0, m = n;
  while (n > 0) {
    rem = n % 10;
    if (rem != 0 and m % rem == 0)
      s++;

    n /= 10;
  }
  return s;
}

int main() {

  int t;
  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int t_itr = 0; t_itr < t; t_itr++) {
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = findDigits(n);

    cout << result << "\n";
  }

  system("pause");

  return 0;
}
