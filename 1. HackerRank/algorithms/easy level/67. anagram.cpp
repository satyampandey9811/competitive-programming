// link to question - https://www.hackerrank.com/challenges/anagram/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the anagram function below.
int anagram(string s) {
    int n=s.size();
    if(n%2!=0)
        return -1;
    
    string s1=s.substr(0,n/2);
    string s2=s.substr(n/2,n/2);

    int c=0;
    for(int i=0;i<s1.size();i++){
        
        auto it=find(s2.begin(),s2.end(),s1[i]);
        if(it!=s2.end()){
            c++;
            *it='A';
        }            
    }
    return s1.size()-c;

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

        int result = anagram(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
