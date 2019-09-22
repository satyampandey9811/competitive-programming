// link to question - https://www.hackerrank.com/challenges/time-conversion/problem

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
  int val = stoi(s.substr(0, 2));

  char a = s[8];
  if (a == 'A') {
    if (val == 12) {
      s[0] -= 1;
      s[1] -= 2;
    }
  } else if (a == 'P') {
      if(val==12)
      return s.substr(0,8);
    val += 12;
    string m = to_string(val), n = s.substr(2, 6);
    string o = m + n;
    return o;
  }
  return s.substr(0, 8);
}

int main() {

  string s;
  getline(cin, s);

  string result = timeConversion(s);

  cout << result << "\n";

  system("pause");

  return 0;
}
