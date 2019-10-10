// link to question - https://www.hackerrank.com/challenges/two-strings/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
    string a("abcdefghijklmnopqrstuvwxyz");
    for(int i=0;i<a.size();i++){
        auto it1=find(s1.begin(),s1.end(),a[i]);
        auto it2=find(s2.begin(),s2.end(),a[i]);
        if(it1!=s1.end() and it2!=s2.end())
            return "YES";
    }
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
