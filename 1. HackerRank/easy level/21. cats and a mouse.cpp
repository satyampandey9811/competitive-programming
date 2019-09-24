// link to question - https://www.hackerrank.com/challenges/cats-and-a-mouse/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the catAndMouse function below.
string catAndMouse(int x, int y, int z) {
    int a=abs(z-x),b=abs(z-y);
    
    if( a==b)
        return "Mouse C";
    if(a>b)
        return "Cat B";
    else 
        return "Cat A";
    return " ";
}

int main()
{

    int q;
    cin >> q;
    int x,y,z;

    for (int q_itr = 0; q_itr < q; q_itr++) {

        cin>>x>>y>>z;

        string result = catAndMouse(x, y, z);

        cout << result << "\n";
    }
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
