// link to question - https://www.codechef.com/AUG19B/problems/CHEFDIL

#include <bits/stdc++.h>
using namespace std;

void testcase() {
	string a;
	cin >> a;
	int c = 0, ans = 0, n = a.size();

	for (int i = 0; i < n; i++) {
		if (a[i] == '1')
			a[i] = '2';
		else if (a[i] == '0')
			continue;

		if (i != n - 1) {
			if (a[i + 1] == '1')
				a[i + 1] = '0';
			else if (a[i + 1] == '0')
				a[i + 1] = '1';
		}		

		int j = i - 1;
		while (j >= 0 and a[j] != '2') {
			a[j] = '1';
			j--;
		}
	}

	auto it = find(a.begin(), a.end(), '0');
	if (it != a.end())
		cout << "LOSE";
	else
		cout << "WIN";	
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