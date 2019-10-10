// link to question - https://www.hackerrank.com/challenges/making-anagrams/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the makingAnagrams function below.
int makingAnagrams(string s1, string s2) {
    
    int c=0;
    for(int i=0;i<s1.size();i++){
        
        auto it=find(s2.begin(),s2.end(),s1[i]);
        if(it!=s2.end()){
            c++;
            *it='A';
        }            
    }
    return s1.size()+s2.size()-(2*c);

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
