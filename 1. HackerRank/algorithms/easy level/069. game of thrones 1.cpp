// link to question - https://www.hackerrank.com/challenges/game-of-thrones/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the gameOfThrones function below.
string gameOfThrones(string s) {

    sort(s.begin(),s.end());
    int c=0;
    for(int i=0;i<s.size()-1;){
        if(s[i]==s[i+1])
            i+=2;
        else{
            i++;c++;
            if(c>1)
                break;
        }
    }
    if(c<2)
        return "YES";
    else
        return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
