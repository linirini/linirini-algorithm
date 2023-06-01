#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
//#9465_스티커
int T, n, sticker[2][100001], dp[2][100001];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> T;
	while (T--) {
		memset(sticker, 0, sizeof(sticker));
		memset(dp, 0, sizeof(dp));
		cin >> n;
		for (int i = 0; i < 2; i++)
			for (int j = 1; j <= n; j++)
				cin >> sticker[i][j];
		dp[0][1] = sticker[0][1];
		dp[1][1] = sticker[1][1];
		for (int i = 2; i <= n; i++) {
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + sticker[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + sticker[1][i];
		}
		cout << max(dp[0][n], dp[1][n]) << "\n";
	}
}