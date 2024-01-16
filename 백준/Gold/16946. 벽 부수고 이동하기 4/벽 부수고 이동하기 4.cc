#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
//#16946_벽 부수고 이동하기 4
int N, M,cnt, board[1001][1001], area[1001][1001];
vector<int>areaSize;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
void dfs(int x, int y) {
	area[x][y] = areaSize.size();
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && !board[nx][ny] && area[nx][ny]==-1) {
			cnt++; 
			dfs(nx, ny);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) board[i][j] = str[j]-'0';
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			area[i][j] = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!board[i][j]&&area[i][j]==-1) {
				cnt = 1;
				dfs(i, j);
				areaSize.push_back(cnt);
			}
		}
	}
	int areaCnt = areaSize.size();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j]) {
				set<int>visited;
				cnt = 1;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					int areaNumber = area[nx][ny];
					if (nx >= 0 && nx < N && ny >= 0 && ny < M && !board[nx][ny] && visited.find(areaNumber)==visited.end()) {
						cnt += areaSize[areaNumber];
						visited.insert(areaNumber);
					}
				}
				cout << cnt % 10;
			}
			else cout << 0;
		}
		cout << '\n';
	}
}