#include<iostream>
#include<algorithm>
using namespace std;
//#1103_게임
int N, M, board[51][51], visited[51][51], dp[51][51];
int go(int x, int y) {
	if (x<0 || x>N || y<0 || y>M || !board[x][y]) return 0;
	if (visited[x][y]) {
		cout << -1;
		exit(0);
	}
	if (dp[x][y] != -1)return dp[x][y];
	visited[x][y] = 1;
	dp[x][y] = 0;
	dp[x][y] = max(dp[x][y], go(x - board[x][y], y) + 1);
	dp[x][y] = max(dp[x][y], go(x + board[x][y], y) + 1);
	dp[x][y] = max(dp[x][y], go(x, y - board[x][y]) + 1);
	dp[x][y] = max(dp[x][y], go(x, y + board[x][y]) + 1);
	visited[x][y] = 0;
	return dp[x][y];
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			dp[i][j] = -1;
			if (str[j] == 'H')board[i][j] = 0;
			else board[i][j] = str[j] - '0';
		}
	}
	cout << go(0,0);
}