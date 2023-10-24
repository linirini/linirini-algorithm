#include<iostream>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
//#4195_친구 네트워크
int T, F,idx,par[200001],visited[200001];
map<string, int>ids;
int find(int x) {
	if (par[x] == x)return x;
	else return x = find(par[x]);
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) {
		if (x > y)swap(x, y);
		par[y] = x;
		visited[x]+=visited[y];
	}
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> F;
		ids.clear();
		fill(visited, visited+200001, 1);
		for (int i = 1; i <= 200000; i++)par[i] = i;
		idx = 1;
		for (int i = 0; i < F; i++) {
			string id1,id2;
			cin >> id1>>id2;
			if (ids.find(id1) == ids.end()) {
				ids.insert({ id1,idx });
				idx++;
			}
			if (ids.find(id2) == ids.end()) {
				ids.insert({ id2,idx });
				idx++;
			}
			int u = ids.find(id1)->second;
			int v = ids.find(id2)->second;
			merge(u, v);
			cout << visited[find(u)] << '\n';
		}
	}
}
