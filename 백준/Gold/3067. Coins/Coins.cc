#include<iostream>
#include<algorithm>
using namespace std;
//#3067_Coins
long long T, N, M,dp[10001],coin[21];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> coin[i];
		for (int i = 1; i <= 10000; i++) dp[i] = 0;
		cin >> M;
		for (int i = 1; i <= N; i++) {
			dp[coin[i]]++;
			for (int j = coin[i]+1; j <= M; j++) {
				dp[j] += dp[j - coin[i]];
			}
		}
		cout << dp[M] << '\n';
	}
}