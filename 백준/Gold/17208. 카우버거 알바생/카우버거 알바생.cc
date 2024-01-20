#include<iostream>
#include<algorithm>
using namespace std;
//#17208_카우버거 알바생
int N, M, K,dp[101][301][301];
struct Order {
	int x;
	int y;
};
Order orders[101];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) cin >> orders[i].x >> orders[i].y;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			for (int k = 1; k <= K; k++) {
				if (orders[i].x <= j && orders[i].y <= k)dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - orders[i].x][k - orders[i].y] + 1);
				else dp[i][j][k] = dp[i - 1][j][k];
			}
		}
	}
	cout << dp[N][M][K];
}
