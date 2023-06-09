#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#20168_골목 대장 호석 - 기능성
int N, M, C, A, B, ans=1e9,visited[11];
vector<pair<int,int>>edge[11];
void go(int now, int cost, int maxCost) {
	if (now == B) {
		if(cost<=C)ans = min(ans, maxCost);
		return;
	}
	for (int i = 0; i < edge[now].size(); i++) {
		int nx = edge[now][i].first;
		int nxc = edge[now][i].second;
		if (!visited[nx]) {
			visited[nx] = 1;
			go(nx, cost + nxc, max(maxCost, nxc));
			visited[nx] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M >> A >> B >> C;
	for (int i = 0; i < M; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		edge[u].push_back({ v,c });
		edge[v].push_back({ u,c });
	}
	visited[A] = 1;
	go(A,0,0);
	ans==1e9?cout<<-1:cout << ans;
}