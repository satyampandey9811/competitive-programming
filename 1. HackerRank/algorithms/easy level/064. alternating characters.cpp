// link to question - https://www.hackerrank.com/challenges/alternating-characters/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the alternatingCharacters function below.
int alternatingCharacters(string s) {
    int n=s.size(),c=0;
    for(int i=0;i<n;){
        if(s[i]=='A'){
            int j=i+1;
            for(;j<n and s[j]=='A';j++){
                c++;
            }
            i=j;
        }
        else{
            int j=i+1;
            for(;j<n and s[j]=='B';j++)
                c++;
            i=j;
        }
    }
    return c;
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

        int result = alternatingCharacters(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
