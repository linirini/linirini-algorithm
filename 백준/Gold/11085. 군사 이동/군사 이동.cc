#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
//#11085_군사 이동
int p, w, c, v, s, t, cost, parent[1001], width;
priority_queue<pair<int, pair<int,int>>> pq;
int find(int x) {
	if (parent[x] == x)return x;
	else return find(parent[x]);
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) {
		if (x < y)parent[y] = x;
		else if(y < x) parent[x] = y;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> p >> w >> c >> v;
	for (int i = 0; i < p; i++) parent[i] = i;
	for (int i = 0; i < w; i++) {
		cin >> s >> t >> cost;
		pq.push({ cost,{s,t} });
	}
	while (!pq.empty()) {
		int wi = pq.top().first;
		int st = pq.top().second.first;
		int en = pq.top().second.second;
		pq.pop();
		merge(st, en);
		width = wi;
		if (find(c) == find(v)) {
			cout << width;
			break;
		}
	}
}