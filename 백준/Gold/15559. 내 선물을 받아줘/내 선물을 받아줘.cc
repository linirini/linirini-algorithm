#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
//#15559_내 선물을 받아줘
int N, M, cnt, ans, visited[1001][1001];
vector<string>board;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int findDir(char dir) {
	if (dir == 'N') return 0;
	else if (dir == 'S') return 1;
	else if (dir == 'W') return 2;
	else if (dir == 'E') return 3;
}
void go(int x, int y) {
	visited[x][y] = cnt;
	int dir = findDir(board[x][y]);
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	if (!visited[nx][ny])go(nx, ny);
	else if (visited[nx][ny] == cnt) ans++;
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		board.push_back(str);
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (!visited[i][j]) {
				cnt++;
				go(i, j);
			}
	cout << ans;
}