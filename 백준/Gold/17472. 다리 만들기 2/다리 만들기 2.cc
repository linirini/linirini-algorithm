#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
//#17472_다리 만들기 2
int N, M, board[11][11], visited[11][11], island_visited[7],ans;
struct Coor{
	int x;
	int y;
};
vector<Coor>tmp;
vector<vector<Coor>>islands;
vector<pair<int, int>>edge[7];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void dfs(int x, int y) {
	visited[x][y]=islands.size()+1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && board[nx][ny] && !visited[nx][ny]) {
			tmp.push_back({nx,ny});
			dfs(nx, ny);
		}
	}
}
//O((N*M)^2)
void getIslands() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] && !visited[i][j]) {
				tmp.clear();
				tmp.push_back({ i, j });
				dfs(i, j);
				islands.push_back(tmp);
			}
		}
	}
}
//O((I^2)*(N*M)*(N+M)), I == islands count
void getEdges() {
	for (int i = 0; i < islands.size(); i++) {
		for (int j = i + 1; j < islands.size(); j++) {
			int Min = 1e9;
			for (auto k : islands[i]) {
				for (int l = k.x-1; l >= 0; l--) {
					if (visited[l][k.y] == j + 1) {
						if(abs(k.x-l)-1>1)Min = min(Min, abs(k.x - l) - 1);
						break;
					}
					else if (visited[l][k.y])break;
				}
				for (int l = k.x+1; l < N; l++) {
					if (visited[l][k.y] == j + 1) {
						if (abs(k.x - l) - 1 > 1)Min = min(Min, abs(k.x - l) - 1);
						break;
					}
					else if (visited[l][k.y])break;
				}
				for (int l = k.y-1; l >= 0; l--) {
					if (visited[k.x][l] == j + 1) {
						if (abs(k.y - l) - 1 > 1)Min = min(Min, abs(k.y - l) - 1);
						break;
					}
					else if (visited[k.x][l])break;
				}
				for (int l = k.y+1; l < M; l++) {
					if (visited[k.x][l] == j + 1) {
						if (abs(k.y - l) - 1 > 1)Min = min(Min, abs(k.y - l) - 1);
						break;
					}
					else if (visited[k.x][l])break;
				}
			}
			if (Min != 1e9) {
				edge[i+1].push_back({ j+1, Min });
				edge[j+1].push_back({ i+1, Min });
			}
		}
	}
}
void makeGraph() {
	getIslands();
	getEdges();
}
void prim(int start) {
	island_visited[start] = 1;
	for (int i = 0; i < edge[start].size(); i++)pq.push({ edge[start][i].second,edge[start][i].first });
	while (!pq.empty()) {
		int now = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (!island_visited[now]) {
			island_visited[now] = 1;
			ans += cost;
			for (auto next : edge[now])pq.push({ next.second,next.first });
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];
	makeGraph();
	prim(1);
	for (int i = 1; i <= islands.size(); i++) {
		if (!island_visited[i]) {
			cout << -1;
			return 0;
		}
	}
	cout << ans;
}