#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<stack>
#include<cmath>
#include<math.h>
#include<functional>
#include<map>
#include<set>
using namespace std;
//#4196_도미노
//그래프를 만들고, SCC를 만들어서 SCC 사이의 간선을 확인해서 건드려야 할, 쓰러뜨려야 할 SCC를 찾아줘야 함
//들어오는 간선이 없으면 손을 대지 않는 이상 안 쓰러진다.
//즉, 들어오는 간선이 없는 SCC의 개수를 찾아주면 됨
//현재 들어가는 중인 SCC 번호도 확인해줘야함, SCC그룹 번호 기록하라는 뜻->scheck
int T, N, M, x, y, discovered[100001], scheck[100001], ind[100001],seq;
vector<vector<int>>adj;
bool fin[100001];//SCC확정여부
stack<int>st;
vector<vector<int>>SCC;
int get_SCC(int now) {
	discovered[now] = ++seq;
	st.push(now);
	int low = discovered[now];
	for (int i = 0; i < adj[now].size(); i++) {
		int next = adj[now][i];
		if (!discovered[next])low = min(low, get_SCC(next));
		else if (!fin[next])low = min(low, discovered[next]);
	}
	if (low == discovered[now]) {
		vector<int>scc;
		while (true) {
			int tmp = st.top();
			st.pop();
			scc.push_back(tmp);
			fin[tmp] = true;
			scheck[tmp] = SCC.size() + 1;
			if (tmp == now)break;
		}
		SCC.push_back(scc);
	}
	return low;
}
int main() {
	cin >> T;
	while (T--) {
		cin >> N >> M;
		adj.resize(N + 1);
		for (int i = 0; i < M; i++) {
			cin >> x >> y;
			adj[x].push_back(y);
		}
		for (int i = 1; i <= N; i++) {
			if (!discovered[i])get_SCC(i);
		}
		for (int i = 1; i <= N; i++) {
			for (auto next : adj[i]) {
				if (scheck[next] == scheck[i])continue;
				ind[scheck[next]]++;
			}
		}
		int ans = 0;
		for (int i = 1; i <= SCC.size(); i++) {
			if (!ind[i])ans++;
		}
		cout << ans << '\n';
		seq = 0;
		memset(discovered, 0, sizeof(discovered));
		memset(fin, 0, sizeof(fin));
		memset(scheck, 0, sizeof(scheck));
		memset(ind, 0, sizeof(ind));
		adj.clear();
		SCC.clear();
		while (!st.empty())st.pop();
	}
}