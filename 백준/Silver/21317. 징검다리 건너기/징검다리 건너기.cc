#include<iostream>
#include<algorithm>
using namespace std;
//#21317_징검다리 건너기
int N, K, bridge[21][3],dp[21][2];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N-1 ; i++)
		cin >> bridge[i][1] >> bridge[i][2];
	cin >> K;
	for (int i = 0; i <= N; i++) {
		dp[i][0] = 1e9;
		dp[i][1] = 1e9;
	}
	dp[1][0] = 0;
	dp[2][0] = bridge[1][1];
	dp[3][0] = min(bridge[1][2], dp[2][0] + bridge[2][1]);
	for (int i = 4; i <= N; i++) {
		dp[i][0] = min(dp[i - 2][0] + bridge[i - 2][2],dp[i - 1][0] + bridge[i - 1][1]);
		dp[i][1] = min(min(dp[i - 2][1] + bridge[i - 2][2], dp[i - 1][1] + bridge[i - 1][1]),dp[i - 3][0] + K);
	}
	cout << min(dp[N][0], dp[N][1]);
}