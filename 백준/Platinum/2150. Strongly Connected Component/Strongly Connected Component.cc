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
//#2150_Strongly Connected Component
int V, E, A, B, K, discovered[10001], finished[10001], seq;
stack<int>st;
vector<vector<int>>SCC;
vector<int>edge[10001];
int getScc(int now) {
	discovered[now] = ++seq;
	st.push(now);
	int low = discovered[now];
	for (auto next : edge[now]) {
		if (!discovered[next])low = min(low,getScc(next));
		else if(!finished[next])low = min(low, discovered[next]);
	}
	if (discovered[now] == low) {
		vector<int>scc;
		while (1) {
			int tmp = st.top();
			scc.push_back(tmp);
			st.pop();
			finished[tmp] = 1;
			if (now == tmp)break;
		}
		sort(scc.begin(), scc.end());
		SCC.push_back(scc);
	}
	return low;
}
int main() {
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		cin >> A >> B;
		edge[A].push_back(B);
	}
	for (int i = 1; i <= V; i++) {
		if (!discovered[i])getScc(i);
	}
	sort(SCC.begin(), SCC.end());
	cout << SCC.size() <<'\n';
	for (int i = 0; i < SCC.size(); i++) {
		for (auto comp : SCC[i]) cout << comp << ' ';
		cout << -1<<'\n';
	}
}