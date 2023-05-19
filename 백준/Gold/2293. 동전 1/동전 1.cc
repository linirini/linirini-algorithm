#include<iostream>
#include<algorithm>
using namespace std;
//#2293_동전1
int N, K;
int coin[101];
int dp[100001];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++)cin >> coin[i];
	dp[0] = 1;
	for (int i = 1; i <= N; i++)
		for (int j = coin[i]; j <= K; j++)
			dp[j] = dp[j] + dp[j - coin[i]];
	cout << dp[K] << '\n';
}