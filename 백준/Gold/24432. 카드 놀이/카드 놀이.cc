#include<iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<string.h>
#include<cmath>
using namespace std;
//#24432_카드 놀이
int T, n, m, k, Min, Max,bob[21],alice[21],visited[21];
vector<int>a, b;
void goBob(int now, int cnt) {
	if (cnt == k) {
		int sum = 0;
		for (int i = 0; i < n; i++)
			if (visited[i])sum += bob[i];
		b.push_back(sum);
		return;
	}
	for (int i = now; i < n; i++) {
		if (visited[i])continue;
		visited[i] = 1;
		goBob(i, cnt + 1);
		visited[i] = 0;
	}
}
void goAlice(int now, int cnt) {
	if (cnt == k) {
		int sum = 0;
		for (int i = 0; i < m; i++)
			if (visited[i])sum += alice[i];
		a.push_back(sum);
		return;
	}
	for (int i = now; i < m; i++) {
		if (visited[i])continue;
		visited[i] = 1;
		goAlice(i, cnt + 1);
		visited[i] = 0;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> T;
	while (T--) {
		Min = 1e9, Max = 0;
		memset(bob, 0, sizeof(bob));
		memset(alice, 0, sizeof(alice));
		a.clear();
		b.clear();
		cin >> n >> m >> k;
		for (int i = 0; i < n; i++)cin >> bob[i];
		for (int i = 0; i < m; i++)cin >> alice[i];
		goBob(0,0);
		sort(b.begin(), b.end());
		memset(visited, 0, sizeof(visited));
		goAlice(0,0);
		sort(a.begin(), a.end());
		for (int i = 0; i < b.size(); i++) {
			int it1 = lower_bound(a.begin(), a.end(), b[i])-a.begin();
			int it2 = it1 - 1;
			if (it1 == 0)it2 = 0;
			else if (it1 == a.size()) {
				it1 = a.size() - 1;
				it2 = a.size() - 1;
			}
			Min = min(Min, min(abs(b[i] - a[it1]), abs(b[i] - a[it2])));
		}
		Max = max(abs(b[b.size()-1] - a[0]), abs(a[a.size()-1] - b[0]));
		cout << Min << ' ' << Max << '\n';
	}
}