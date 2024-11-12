#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
//#12887_경로 게임
int M, Min=1e9, black;
vector<string>board;
int go(int now) {
	int idx = 0, len = 0;
	while(idx<M) {
		if (board[now][idx + 1] == '#') now = (now + 1) % 2;
		else idx++;
		len++;
	}
	return len;
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> M;
	for (int i = 0; i < 2; i++) {
		string str;
		cin >> str;
		board.push_back(str);
	}
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < M; j++)
			if (board[i][j] == '#') black++;
	for (int i = 0; i < 2; i++) 
		if (board[i][0] != '#') Min = min(Min, go(i));
	cout << 2 * M - Min - black;
}