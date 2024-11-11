#include<iostream>
#include<algorithm>
using namespace std;
//#21278_호석이 두 마리 치킨
int N, M, ans=1e9, ansx=1e9, ansy=1e9;
int floid[101][101];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (i != j) floid[i][j] = 1e9;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		floid[x][y] = 1;
		floid[y][x] = 1;
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (floid[i][j] > floid[i][k] + floid[k][j]) {
					floid[i][j] = floid[i][k] + floid[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			int sum = 0;
			for (int k = 1; k <= N; k++)sum+=min(floid[k][i] * 2, floid[k][j] * 2);
			if (ans > sum) {
				ans = sum;
				ansx = i;
				ansy = j;
			}
		}
	}
	cout << ansx << ' ' << ansy << ' ' << ans;
}