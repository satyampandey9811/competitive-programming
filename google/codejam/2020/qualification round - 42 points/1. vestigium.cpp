// codejam 2020
// qualification round
// first problem - vestigium

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define endl '\n'

void testcase(){
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    }

    int t = 0, r = 0, c = 0;

    for(int i = 0; i < n; i++)
        t += a[i][i];

    for(int i = 0; i < n; i++){
        unordered_set<int> s;
        for(int j = 0; j < n; j++){
            s.insert(a[i][j]);
        }
        if(s.size() != n)
            r++;
    }

    for(int i = 0; i < n; i++){
        unordered_set<int> s;
        for(int j = 0; j < n; j++){
            s.insert(a[j][i]);
        }
        if(s.size() != n)
            c++;
    }

    cout << t << ' ' << r << ' ' << c;
}

signed main() {
#ifdef SP
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case #" << i << ": ";
        testcase();
        cout << endl;
    }
    //fprintf(stderr,"Time: %d ms\n", (int)(clock()*1000.0/CLOCKS_PER_SEC));
    return 0;
}