// link to question - https://www.hackerrank.com/challenges/hackerrank-in-a-string/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the hackerrankInString function below.
string hackerrankInString(string a) {

    string b("hackerrank");
    int c=0;char d='h';
    for(int i=0;i<a.size();i++){
        if(c<9 and a[i]==d){
            c++;
            d=b[c];
        }
    }
    if(c==9)
        return "YES";
    else 
        return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        string result = hackerrankInString(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
