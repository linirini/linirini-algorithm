#include<iostream>
#include<algorithm>
using namespace std;
//#2110_공유기 설치
int N, C, X[200001],ans;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> C;
	for (int i = 0; i < N; i++)cin >> X[i];
	sort(X, X + N);
	int st = 1, en = X[N - 1]-X[0];
	while (st <= en) {
		int cnt = 1;
		int mid = (st + en) / 2;
		int cur = X[0];
		for (int i = 1; i < N; i++) {
			if (X[i] - cur >= mid) {
				cnt++;
				cur = X[i];
			}
		}
		if (cnt >= C) {
			ans = mid;
			st = mid + 1;
		}
		else en = mid - 1;
	}
	cout << ans;
}