#include<iostream>
#include<algorithm>
using namespace std;
//#1520_내리막 길
int N, M, board[501][501],dp[501][501],visited[501][501];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int go(int x, int y) {
	if (x == N - 1 && y == M - 1)return 1;
	if (dp[x][y] != -1)return dp[x][y];
	dp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M&&board[nx][ny]<board[x][y])
				dp[x][y] = dp[x][y] + go(nx,ny);
	}
	return dp[x][y];
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			dp[i][j] = -1;
		}
	cout << go(0, 0);
}