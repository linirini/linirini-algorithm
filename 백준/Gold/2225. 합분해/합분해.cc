#include<iostream>
#include<algorithm>
using namespace std;
//#2225_합분해
#define MOD 1000000000;
int N, K,dp[201][201];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i <= N; i++)dp[1][i] = 1;
	for (int i = 2; i <= K; i++)
		for (int j = 0; j <= N; j++)
			for (int l = 0; l <= j; l++)
				dp[i][j] = (dp[i][j] + dp[i - 1][l]) % MOD;
	cout << dp[K][N];
}