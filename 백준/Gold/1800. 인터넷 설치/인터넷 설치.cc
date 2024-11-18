#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
//#1800_인터넷 설치
int n, p, k, dist[10001];
vector<pair<int, int>> edge[10001];
bool dijkstra(int cost) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(dist, dist + 10001, 1e9);
    dist[1] = 0;
    pq.push({ 0, 1 });
    while (!pq.empty()) {
        int now = pq.top().second;
        int nowCost = pq.top().first;
        pq.pop();
        if (dist[now] < nowCost) continue;
        for (auto next : edge[now]) {
            int nextNode = next.first;
            int nextCost = next.second;
            int w = 0;
            if (nextCost > cost) w = nowCost + 1;
            else w = nowCost;
            if (dist[nextNode] > w) {
                dist[nextNode] = w;
                pq.push({ dist[nextNode], nextNode });
            }
        }
    }
    return dist[n] <= k;
}
int main() {
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> n >> p >> k;
    for (int i = 0; i < p; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        edge[u].push_back({ v, c });
        edge[v].push_back({u, c});
    }
    int l = 0, r = 1e7, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (dijkstra(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
}
