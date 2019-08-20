// link to question - https://www.codechef.com/AUG19B/problems/MSNSADM1/

#include <bits/stdc++.h>
using namespace std;

void testcase() {
	int n;
	cin >> n;
	vector<int> a(n),b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, (a[i] * 20) - (b[i] * 10));
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef SP
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif	
	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		//cout << "Case #" << i << ": ";
		testcase();
		cout << '\n';
	}
	return 0;
}