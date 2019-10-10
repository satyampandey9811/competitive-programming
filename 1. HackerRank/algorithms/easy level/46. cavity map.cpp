// link to question - https://www.hackerrank.com/challenges/cavity-map/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the cavityMap function below.
vector<string> cavityMap(vector<string> a) {
    int m=a.size(),n=a[0].size();
    vector<string> b=a;
    for(int i=1;i<m-1;i++){
        for(int j=1;j<n-1;j++){
            int c=a[i][j]-'0',p=a[i-1][j]-'0',q=a[i][j-1]-'0',r=a[i][j+1]-'0',s=a[i+1][j]-'0';
            if(c>p and c>q and c>r and c>s)
                b[i][j]='X';
        }
    }
    return b;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = cavityMap(grid);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
