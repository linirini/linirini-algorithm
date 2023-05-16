#include<iostream>
#include<algorithm>
using namespace std;
//#10844_쉬운 계단 수
#define MOD 1000000000
int N;
long long ans, dp[101][11];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	dp[1][0] = 0;
	for (int i = 1; i < 10; i++) dp[1][i] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			if (!j)dp[i][j] = dp[i - 1][j + 1] % MOD;
			else if (j == 9)dp[i][j] = dp[i - 1][j - 1] % MOD;
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
		}
	}
	for (int i = 0; i < 10; i++)ans = ans + dp[N][i];
	cout << ans % MOD;
}