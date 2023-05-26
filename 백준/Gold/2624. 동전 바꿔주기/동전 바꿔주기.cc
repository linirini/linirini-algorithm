#include<iostream>
#include<algorithm>
using namespace std;
//#2624_동전 바꿔주기
int T, k, P[10001], N[10001], dp[10001];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> T >> k;
	for (int i = 0; i < k; i++)cin >> P[i] >> N[i];
	dp[0] = 1;
	for (int i = 0; i < k; i++) {
		for (int j = T; j > 0; j--) {
			int sum = 0;
			for (int l = 0; l < N[i]; l++) {
				sum += P[i];
				if (j - sum >= 0)dp[j] += dp[j - sum];
			}
		}
	}
	cout << dp[T];
}