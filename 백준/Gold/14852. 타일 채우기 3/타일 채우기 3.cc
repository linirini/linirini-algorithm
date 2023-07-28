#include<iostream>
#include<algorithm>
using namespace std;
//#14852_타일 채우기 3
long long N, dp[1000001][2];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	dp[0][0] = 0;
	dp[1][0] = 2;
	dp[2][0] = 7;
	dp[2][1] = 1;
	for (int i = 3; i <= N; i++) {
		dp[i][1] = (dp[i - 3][0] + dp[i - 1][1]) % 1000000007;
		dp[i][0] = (dp[i][1] * 2 + dp[i - 1][0] * 2 + dp[i - 2][0] * 3) % 1000000007;
	}
	cout << dp[N][0] << '\n';
}