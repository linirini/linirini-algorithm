#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#10164_격자상의 경로
int N, M, K,dp[16][16];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			if (i == 1 || j == 1)dp[i][j] = 1;
			else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	int col_st = !(K % M) ? K / M : K / M + 1;
	int row_st = !(K%M)?M:K%M;
	int col_en = (N - col_st) + 1;
	int row_en = (M - row_st) + 1;
	if(!K)cout << dp[N][M];
	else cout << dp[col_st][row_st] * dp[col_en][row_en];
}