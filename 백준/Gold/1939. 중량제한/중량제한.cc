#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
//#1939_중량제한
int N, M, A, B, C, from, to, par[100001], cost[100001];
vector<pair<int, pair<int, int>>>v;
bool cmp(pair<int, pair<int, int>>a, pair<int, pair<int, int>>b) {
	return a.first > b.first;
}
int find(int x) {
	if (par[x] == x)return x;
	else return par[x] = find(par[x]);
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) par[y] = x;
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i <= N; i++)par[i] = i;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		v.push_back({ C,{A,B} });
	}
	sort(v.begin(), v.end(), cmp);
	cin >> from >> to;
	for(int i=0;i<v.size();i++){
		merge(v[i].second.first,v[i].second.second);
		if (find(from) == find(to)) {
			cout <<	v[i].first;
			break;
		}
	}
}