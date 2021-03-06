// link to question - https://www.hackerrank.com/challenges/countingsort1/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the countingSort function below.
void countingSort(vector<int> a,int n) {

    vector<int> b(100);
    for(int i=0;i<n;i++){
        b[a[i]]++;
    }
    for(int i=0;i<100;i++){
        cout<<b[i]<<' ';
    }
}

int main()
{

    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];

    countingSort(a,n);

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
