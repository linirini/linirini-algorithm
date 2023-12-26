#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;
//#16724_피리 부는 사나이
int N, M,visited[1001][1001],board[1001][1001];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
pair<int, int>parent[1001][1001];
set<pair<int, int>>ans;
pair<int, int> find(pair<int, int>x) {
	if (parent[x.first][x.second]==x)return x;
	else return parent[x.first][x.second]=find(parent[x.first][x.second]);
}
void merge(pair<int, int>x, pair<int, int>y) {
	x = find(x);
	y = find(y);
	if (x != y) parent[y.first][y.second] = x;
}
void dfs(int x, int y,int dir) {
	visited[x][y] = 1;
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	merge({ x,y, }, { nx, ny });
	if (!visited[nx][ny])dfs(nx,ny,board[nx][ny]);
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			parent[i][j] = { i,j };
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			if (str[j] == 'D')board[i][j] = 0;
			else if (str[j] == 'U')board[i][j] = 1;
			else if (str[j] == 'R')board[i][j] = 2;
			else if (str[j] == 'L')board[i][j] = 3;
		}
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (!visited[i][j])	dfs(i, j,board[i][j]);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			ans.insert(find({ i,j }));
	cout << ans.size();
}