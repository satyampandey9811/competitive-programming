// link to question - https://www.hackerrank.com/challenges/maximum-perimeter-triangle/problem

#include <bits/stdc++.h>
#include <math.h>
using namespace std;

vector<string> split_string(string);

// Complete the maximumPerimeterTriangle function below.
vector<int> maximumPerimeterTriangle(vector<int> a) {
    int n=a.size();
    long long int maxlen=0;
    int p,d,e;
    int maxs=0,mins=0;
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                int x=a[i],y=a[j],z=a[k];
                if((x+y>z and x+z>y and y+z>x) and ( x*1LL +y+z>=maxlen )){
                    maxlen=x+y+z;
                    d=min(x,y);
                    d=min(d,z);
                    e=max(x,y);
                    e=max(e,z);
                    if(e>maxs)
                        maxs=e;
                    if(d>mins)
                        mins=d;
                }
            }
        }
    }
    p=maxlen-mins-maxs;
    if(mins==0)
        return {-1};
    else
        return {mins,p,maxs};
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string sticks_temp_temp;
    getline(cin, sticks_temp_temp);

    vector<string> sticks_temp = split_string(sticks_temp_temp);

    vector<int> sticks(n);

    for (int i = 0; i < n; i++) {
        int sticks_item = stoi(sticks_temp[i]);

        sticks[i] = sticks_item;
    }

    vector<int> result = maximumPerimeterTriangle(sticks);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

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
