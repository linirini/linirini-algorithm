#include<iostream>
#include<algorithm>
using namespace std;
//#1535_안녕
int N,dp[21][101];
struct Knapsack{
	int L;
	int J;
};
Knapsack ks[21];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)cin >> ks[i].L;
	for (int i = 1; i <= N; i++)cin >> ks[i].J;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 100; j++) {
			if (j > ks[i].L)dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - ks[i].L] + ks[i].J);
			else dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[N][100];
}