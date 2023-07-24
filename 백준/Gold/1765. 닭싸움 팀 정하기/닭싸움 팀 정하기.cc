#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#1765_닭싸움 팀 정하기
int n, m, p, q, cnt, par[1001],visited[1001],chk[1001];
vector<int>edge[1001];
char cmd;
int find(int x) {
	if (par[x] == x)return x;
	else return par[x] = find(par[x]);
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y)par[y] = x;
}
void go(int st, int now, int enemyCnt) {
	if (enemyCnt == 2) {
		merge(st, now);
		return;
	}
	for (auto next : edge[now]) {
		if (visited[next])continue;
		visited[next] = 1;
		go(st, next, enemyCnt + 1);
		visited[next] = 0;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)par[i] = i;
	for (int i = 0; i < m; i++) {
		cin >> cmd >> p >> q;
		if (cmd == 'F')merge(p, q);
		else {
			edge[p].push_back(q);
			edge[q].push_back(p);
		}
	}
	for (int i = 1; i <= n; i++) {
		visited[i] = 1;
		go(i, i, 0);
		visited[i] = 0;
	}
	for (int i = 1; i <= n; i++)find(i);
	for (int i = 1; i <= n; i++)chk[par[i]] = 1;
	for (int i = 1; i <= n; i++)if (chk[i])cnt++;
	cout << cnt;
}