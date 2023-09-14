#include<iostream>
#include<algorithm>
using namespace std;
//#11066_파일 합치기
int T, N, K, dp[501][501], sum[501];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> K;
			sum[i] = sum[i - 1] + K;
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N - i; j++) {
				dp[j][i+j] = 1e9;
				for (int k = j; k < i+j; k++) dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k + 1][i+j] +sum[i+j] - sum[j - 1]);
			}
		}
		cout << dp[1][N] << '\n';
	}
}