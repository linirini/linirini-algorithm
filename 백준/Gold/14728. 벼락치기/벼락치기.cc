#include<iostream>
#include<algorithm>
using namespace std;
//#14728_벼락치기
int N, T,dp[101][10001];
struct Chapter {
	int K;
	int S;
};
Chapter c[101];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> T;
	for (int i = 1; i <= N; i++)cin >> c[i].K >> c[i].S;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= T; j++) {
			if (j - c[i].K >= 0)dp[i][j] = max(dp[i - 1][j], dp[i-1][j - c[i].K] + c[i].S);
			else dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[N][T];
}