#include<iostream>
#include<algorithm>
using namespace std;
//#11660_구간 합 구하기 5
int N, dp[1025][1025], M;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			int value;
			cin >> value;
			dp[i][j] = dp[i][j - 1] + value;
		}
	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int sum = 0;
		for (int j = x1; j <= x2; j++) {
			sum += dp[j][y2] - dp[j][y1 - 1];
		}
		cout << sum <<'\n';
	}
}