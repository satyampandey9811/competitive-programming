// link to question - https://www.hackerrank.com/challenges/repeated-string/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long c=0;
    int a=s.size();
    for(int i=0;i<a;i++){
        if(s[i]=='a')
            c++;
    }
    c=c*(n/a);
    for(int i=0;i<n%a;i++){
      if (s[i] == 'a')
        c++;
    }
    return c;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
