#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
//#18133_가톨릭대학교에 워터 슬라이드를??
int n, m, seq,discovered[100001],finished[100001],scheck[100001],ind[100001];
vector<vector<int>> edge;
stack<int> s;
vector<vector<int>>SCC;
int get_SCC(int cur) {
    discovered[cur] = ++seq;
    s.push(cur);
    int low = discovered[cur];
    for (int i = 0; i < edge[cur].size(); i++) {
        int next = edge[cur][i];
        if (!discovered[next]) low = min(low, get_SCC(next));
        else if(!finished[next])low = min(low, discovered[next]);
    }
    if (low == discovered[cur]) {
        vector<int> scc;
        while (1) {
            int tmp = s.top();
            s.pop();
            scc.push_back(tmp);
            finished[tmp] = 1;
            scheck[tmp] = SCC.size()+1;
            if (tmp == cur)break;
        }
        SCC.push_back(scc);
    }
    return low;
}
int main() {
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> n >> m;
    edge.resize(n + 1);
    for(int i=0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
        if (!discovered[i]) get_SCC(i);
    for (int i = 1; i <= n; i++)
        for (int next : edge[i])
            if (scheck[i] != scheck[next])ind[scheck[next]]++;
    int ans = 0;
    for (int i = 1; i <= SCC.size() ; i++)
        if (!ind[i]) ans++;
    cout << ans;
}