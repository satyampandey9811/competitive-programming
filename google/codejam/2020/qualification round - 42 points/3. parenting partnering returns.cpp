// codejam 2020
// qualification round
// third problem - parenting partnering returns

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define endl '\n'

struct cell{
    int s, e, ind;
    char c;
};

void testcase(){
    int n, st, et;
    cin >> n;
    vector<cell> a(n);
    for(int i = 0; i < n; i++){
        cin >> st >> et;
        cell input;
        input.s = st;
        input.e = et;
        input.ind = i;
        a[i] = input;
    }
    sort(a.begin(), a.end(), [](cell m, cell n){return m.s < n.s;});
    int x = -1, y = -1;

    for(int i = 0; i < n; i++){
        if(a[i].s >= x){
            x = a[i].e;
            a[i].c = 'C';
        }
        else if(a[i].s >= y){
            y = a[i].e;
            a[i].c = 'J';
        }
        else{
            cout << "IMPOSSIBLE";
            return;
        }
    }
    sort(a.begin(), a.end(), [](cell m, cell n){return m.ind < n.ind;});
    for(int i = 0; i < n; i++)
        cout << a[i].c;
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