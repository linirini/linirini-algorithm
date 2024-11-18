#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
//#5719_거의 최단 경로
int N, M, S, D, dist[501];
vector<pair<int, int>> edge[501];
vector<pair<int, int>> inverseEdge[501];
vector<int> parent[501];
int dijkstra(int st, int dest) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(dist, dist + N, 1e9);
    pq.push({ 0, st });
    dist[st] = 0;
    while (!pq.empty()) {
        int now = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if (dist[now] < cost) continue;
        for (int i = 0; i < edge[now].size(); i++) {
            int nextNode = edge[now][i].first;
            int nextCost = edge[now][i].second;
            if (dist[nextNode] > cost + nextCost) {
                dist[nextNode] = cost + nextCost;
                pq.push({ dist[nextNode], nextNode });
                parent[nextNode].clear();
                parent[nextNode].push_back(now);
            }
            else if (dist[nextNode] == cost + nextCost) parent[nextNode].push_back(now);
        }
    }
    return dist[dest];
}
void removePath(int dest) {
    queue<int> q;
    q.push(dest);
    vector<int> visited(N, 0);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (visited[now]) continue;
        visited[now] = true;
        for (int i = 0; i < inverseEdge[now].size(); i++) {
            int prevNode = inverseEdge[now][i].first;
            int prevCost = inverseEdge[now][i].second;
            if (dist[prevNode] + prevCost == dist[now]) {
                for (int j = 0; j < edge[prevNode].size(); j++)
                    if (edge[prevNode][j].first == now) edge[prevNode][j].second = 1e9;
                q.push(prevNode);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    while (true) {
        cin >> N >> M;
        if (!N && !M) break;
        cin >> S >> D;
        for (int i = 0; i < M; i++) {
            int u, v, c;
            cin >> u >> v >> c;
            edge[u].push_back({ v, c });
            inverseEdge[v].push_back({ u, c });
        }
        dijkstra(S, D);
        removePath(D);
        int ans = dijkstra(S, D);
        if (ans == 1e9) cout << -1 << '\n';
        else cout << ans << '\n';
        for (int i = 0; i <= N; i++) {
            edge[i].clear();
            inverseEdge[i].clear();
            parent[i].clear();
        }
    }
}
