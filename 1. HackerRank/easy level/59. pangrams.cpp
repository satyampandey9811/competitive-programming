// link to question - https://www.hackerrank.com/challenges/pangrams/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the pangrams function below.
string pangrams(string s) {

    set<char> a;
    for(int i=0;i<s.size();i++){
        if(!isalpha(s[i]))
            continue;
        s[i]=toupper(s[i]);
        a.insert(s[i]);
    }
    if(a.size()==26)
        return "pangram";
    return "not pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
