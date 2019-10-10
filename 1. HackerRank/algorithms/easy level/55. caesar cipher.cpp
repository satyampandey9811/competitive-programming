// link to question - https://www.hackerrank.com/challenges/caesar-cipher-1/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the caesarCipher function below.
string caesarCipher(string s, int k) {
    int x;k=k%26;
    for(int i=0;i<s.size();i++){
        if(!isalpha(s[i]))
            continue;
        
        if(islower(s[i])){
            s[i] = (char) ((s[i] - 'a' + k ) % 26 + 'a');
        }
        else{
            s[i] = (char) ((s[i] - 'A' + k ) % 26 + 'A');
        }
    }
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = caesarCipher(s, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
