#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
//#9694_무엇을 아느냐가 아니라 누구를 아느냐가 문제다
int T, N, M, x, y, z, route[21];
vector<pair<int, int>>edge[21]; 
vector<int>dist;
const int INF = 1e9;
void djikstra() {
	dist[0] = 0;
	priority_queue<pair<int,int>>pq;
	pq.push({ 0,0 });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost)continue;
		for (int i = 0; i < edge[here].size(); i++) {
			int next = edge[here][i].first;
			int nextcost = edge[here][i].second;
			if (dist[next] > dist[here] + nextcost) {
				dist[next] = dist[here] + nextcost;
				route[next] = here;
				pq.push({ -dist[next],next });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	for(int i=1;i<=T;i++) {
		cin >> N >> M;
		memset(route, -1, sizeof(route));
		for (int i = 0; i < 21; i++)edge[i].clear();
		dist.clear();
		dist.resize(M + 1, INF);
		for (int j = 0; j < N; j++) {
			cin >> x >> y >> z;
			edge[x].push_back({ y,z });
			edge[y].push_back({ x,z });
		}
		djikstra();
		cout << "Case #" << i << ": ";
		if (dist[M-1]==INF)cout << -1;
		else {
			vector<int>ans;
			int now = M - 1;
			while (now) {
				ans.push_back(now);
				now = route[now];
			}
			ans.push_back(0);
			for (int j = ans.size()-1; j >= 0; j--)cout << ans[j] << " ";
		}
		cout << "\n";
	}
}