#include<iostream>
#include<algorithm>
using namespace std;
//#4198_열차정렬
int N, cars[2001],dp[2001],revDp[2001],ans;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)cin >> cars[i];
	for (int i = N - 1; i >= 0; i--) {
		for (int j = i + 1; j < N; j++) {
			if (cars[j] > cars[i])dp[i] = max(dp[j], dp[i]);
			else revDp[i] = max(revDp[j], revDp[i]);
		}
		dp[i]++;
		revDp[i]++;
		ans = max(ans, dp[i] + revDp[i] - 1);
	}
	cout << ans;
}