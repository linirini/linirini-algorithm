#include<iostream>
#include<algorithm>
using namespace std;
//#14501_퇴사
int N, day[16], cost[16], dp[16];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)cin >> day[i] >> cost[i];
	for (int i = N - 1; i >= 0; i--) {
		if (i + day[i] > N)dp[i] = dp[i + 1];
		else dp[i] = max(dp[i + 1], dp[i + day[i]] + cost[i]);
	}
	cout << dp[0];
}