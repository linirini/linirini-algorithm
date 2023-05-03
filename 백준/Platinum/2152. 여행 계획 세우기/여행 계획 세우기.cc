#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
//#2152_여행 계획 세우기
int N, M, S, T,discovered[10001],seq=0,finished[10001],scheck[10001],visited[10001];
vector<vector<int>> edge,path;
stack<int> s;
vector<vector<int>>SCC;
int get_SCC(int cur) {
    discovered[cur] = ++seq;
    s.push(cur);
    int low = discovered[cur];
    for (int i = 0; i < edge[cur].size(); i++) {
        int next = edge[cur][i];
        if (!discovered[next]) low = min(low, get_SCC(next));
        else if (!finished[next])low = min(low, discovered[next]);
    }
    if (low == discovered[cur]) {
        vector<int> scc;
        while (1) {
            int tmp = s.top();
            s.pop();
            scc.push_back(tmp);
            finished[tmp] = 1;
            scheck[tmp] = SCC.size() + 1;
            if (tmp == cur)break;
        }
        SCC.push_back(scc);
    }
    return low;
}
void bfs() {
    queue<int>q;
    visited[S] = SCC[S - 1].size();
    q.push(S);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int next : path[now]) {
            int cost = visited[now]+SCC[next-1].size();
            if (cost > visited[next]) {
                visited[next] = cost;
                q.push(next);
            }
        }
    }
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M >> S >> T;
    edge.resize(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
    }
    for (int i = 1; i <= N; i++)
        if (!discovered[i]) get_SCC(i);
    path.resize(SCC.size() + 1);
    for (int i = 1; i <= N; i++)
        for (int next : edge[i])
            if (scheck[i] != scheck[next])path[scheck[i]].push_back(scheck[next]);
    if (scheck[S] == scheck[T])cout << SCC[scheck[S] - 1].size();
    else {
        S = scheck[S];
        T = scheck[T];
        bfs();
        cout << visited[T];
    }
}