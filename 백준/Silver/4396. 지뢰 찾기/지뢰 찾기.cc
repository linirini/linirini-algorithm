#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
//#4396_지뢰 찾기
int n, m,flag;
vector<string>board,ans;
int dx[8] = { 1,-1,0,0,1,-1,1,-1};
int dy[8] = { 0,0,1,-1,1,1,-1,-1 };
void go(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx>=0 && nx<n && ny>=0 && ny<n && board[nx][ny] == '*')cnt++;
	}
	ans[x][y] = (char)(cnt+48);
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> n;
	board.resize(n + 1); ans.resize(n + 1);
	for (int i = 0; i < n; i++)cin >> board[i];
	for (int i = 0; i < n; i++)cin >> ans[i];
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			if (ans[i][j] == 'x') {
				if (board[i][j] == '*')flag = 1;
				go(i, j);
			}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (flag) {
				if (board[i][j] == '*')cout << '*';
				else cout << ans[i][j];
			}
			else {
				if (board[i][j] != '*' && ans[i][j] != '.')cout << ans[i][j];
				else if (board[i][j] == '*' && ans[i][j] != '.')cout << '*';
				else cout << '.';
			}
		}
		cout << '\n';
	}
}