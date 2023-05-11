#include<iostream>
#include<algorithm>
using namespace std;
//#1149_RGB거리
int N, home[1001][3], dp[1001][3],cost, ans;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < 3; j++)
			cin >> home[i][j];
	dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 0;
	for (int i = 1; i <= N; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + home[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + home[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + home[i][2];
	}
	cout << min(dp[N][0], min(dp[N][1], dp[N][2]));
}