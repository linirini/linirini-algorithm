#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include<math.h>
#include<cmath>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;
//#1916_최소비용 구하기
typedef pair<int, int>pii;
vector<vector<pii>>edge;
vector<int>dist;
const int INF = 1e9;
int N, M,u,v,w,s,d;//N:도시의 개수:정점 개수, M:버스 개수:간선 개수
//u:출발 도시 번호, v:도착 도시 번호, w:버스 비용(가중치)
void djikstra() {
	dist.resize(N + 1, INF);
	dist[s] = 0;
	priority_queue<pii>pq;
	pq.push({ 0,s });
	while(!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		for (int i = 0; i < edge[here].size(); i++) {
			int next = edge[here][i].first;
			int nextcost = edge[here][i].second;
			if (dist[next] > dist[here] + nextcost) {
				dist[next] = dist[here] + nextcost;
				pq.push({ -dist[next],next });
			}
		}
		if (here == d)break;
	}
}
int main() {
	cin >> N >> M;
	edge.resize(N + 1);
	for (int i = 0; i < M; i++) {
		cin >> u >> v >> w;
		edge[u].push_back({ v,w });
	}
	cin >> s >> d;
	djikstra();
	cout << dist[d];
}
