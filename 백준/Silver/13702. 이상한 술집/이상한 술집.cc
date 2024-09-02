#include<iostream>
#include<algorithm>
using namespace std;
//#13702_이상한 술집
long long N, K, mak[10001], ans;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++)cin >> mak[i];
	sort(mak, mak + N);
	long long left = 1, right = mak[N - 1];
	while (left <= right) {
		long long mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 0; i < N; i++) cnt += mak[i] / mid;
		if (cnt >= K) {
			ans = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}
	cout << ans;
}