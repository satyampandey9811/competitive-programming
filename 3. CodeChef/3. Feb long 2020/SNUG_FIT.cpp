// link to question - https://www.codechef.com/FEB20B/problems/SNUG_FIT

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define md 1000000007

void testcase(){
    int n, ans = 0;
    cin>>n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i = 0; i < n; i++)
        ans += min(a[i], b[i]);
    cout<<ans;
}

signed main() {
#ifdef SP
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        testcase();
        cout << '\n';
    }
    return 0;
}
