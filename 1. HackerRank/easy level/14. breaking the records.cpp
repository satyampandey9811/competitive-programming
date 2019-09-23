// link to question - https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the breakingRecords function below.
vector<int> breakingRecords(vector<int> scores) {

    int a=scores[0],min=a,max=a,nmin=0,nmax=0;
    for(int i=1;i<scores.size();i++){
        if(scores[i]>max){
            nmax++;max=scores[i];
        }
        else if(scores[i]<min){
            nmin++;min=scores[i];
        }
    }
    cout<<nmax<<' '<<nmin;
    return scores;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int> s=breakingRecords(v);
    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
