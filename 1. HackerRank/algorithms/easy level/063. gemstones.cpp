// link to question - https://www.hackerrank.com/challenges/gem-stones/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the gemstones function below.
int gemstones(vector<string> a) {
    int ans=0;
    int m=a.size(),n=a[0].size();
    for(int i=0;i<n;i++){
        int f=1;
        for(int j=1;j<m;j++){
            auto it=find(a[j].begin(),a[j].end(),a[0][i]);
            if(it==a[j].end()){
                f=0;break;
            }
            else
                *it='1';
        }
        if(f) ans++;
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item;
        getline(cin, arr_item);

        arr[i] = arr_item;
    }

    int result = gemstones(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
