#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//#1189_컴백홈
int R, C, K,visited[6][6],ans;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
string board[6];
void go(int x, int y, int cnt) {
	if (cnt == K) {
		if (x == R - 1 && y == C - 1)ans++;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= R || ny < 0 || ny >= C|| board[nx][ny] == 'T' || visited[nx][ny])continue;
		visited[x][y] = 1;
		go(nx, ny, cnt + 1);
		visited[x][y] = 0;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> R >> C >> K;
	for (int i = R-1; i >= 0; i--) cin >> board[i];
	go(0, 0, 1);
	cout<<ans;
}