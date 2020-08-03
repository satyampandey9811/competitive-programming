// codejam 2020
// qualification round
// second problem - nesting depth

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define endl '\n'

void testcase(){
    string s, ans;
    cin >> s;
    int n = s.size(), p, q, r;
    int a = 0;
    for(int i = 0; i < n; i++) {
        p = s[i] - '0';
        q = p - a;
        r = a - p;
        for(int j = 0; j < q; j++){
            ans += '(';
            a++;
        }
        for(int j = 0; j < r; j++){
            ans += ')';
            a--;
        }
        ans += s[i];
    }
    while(a){
        ans += ')';
        a--;
    }
    cout << ans;
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