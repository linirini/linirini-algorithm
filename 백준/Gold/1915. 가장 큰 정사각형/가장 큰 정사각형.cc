#include<iostream>
#include<algorithm>
using namespace std;
//#1915_가장 큰 정사각형
int n, m, board[1001][1001], Max;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= m; j++) board[i][j] = str[j-1]-'0';
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j]) {
				board[i][j] = min(board[i - 1][j], min(board[i - 1][j - 1], board[i][j - 1])) + 1;
			Max = max(board[i][j], Max);
			}
		}
	}
	cout << Max * Max;
}