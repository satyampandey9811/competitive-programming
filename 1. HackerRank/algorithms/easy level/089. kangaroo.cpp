// link to question - https://www.hackerrank.com/challenges/kangaroo/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the kangaroo function below.
string kangaroo(int x1, int v1, int x2, int v2) {
  
      while(x1<x2){
          x1+=v1;x2+=v2;
          if(x1==x2)
            return "YES";
          
      }
  
    return "NO";
}

int main() {

  int x1, x2, v1, v2;
  cin >> x1 >> v1 >> x2 >> v2;

  string result = kangaroo(x1, v1, x2, v2);

  cout << result << "\n";
  system("pause");
  return 0;
}
