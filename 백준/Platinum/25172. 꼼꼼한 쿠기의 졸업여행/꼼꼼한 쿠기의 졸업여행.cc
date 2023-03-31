#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#25172_꼼꼼한 쿠기의 졸업여행
int N, M, parent[200001], query[200001], u, v,visited[200001],groupCnt;
vector<int>parentInput[200001];
vector<string> ans;
int find(int x) {
	if (parent[x] == x)return x;
	else return parent[x] = find(parent[x]);
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) {
		parent[y] = x;
		groupCnt--;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)parent[i] = i;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		parentInput[u].push_back(v);
		parentInput[v].push_back(u);
	}
	for (int i = 0; i < N; i++)cin >> query[i];
	ans.push_back("DISCONNECT");
	for (int i = N - 1; i >= 0; i--) {
		visited[query[i]]=1;
		groupCnt++;
		for (auto node : parentInput[query[i]]) {
			if (query[i] == node || !visited[node])continue;
			merge(query[i], node);
		}
		if (groupCnt==1)ans.push_back("CONNECT");
		else ans.push_back("DISCONNECT");
	}
	for (int i = ans.size()-1; i >= 0; i--)cout << ans[i] << '\n';
}
