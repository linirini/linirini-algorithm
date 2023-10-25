#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#16562_친구비
int N, M, k, par[10001], cost[100001], visited[100001], ans, flag = 1;
int find(int x) {
	if (x == par[x])return x;
	else return par[x] = find(par[x]);
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (cost[x] > cost[y])swap(x, y);
	if (x != y)par[y] = x;
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M>>k;
	for (int i = 0; i <= N; i++) par[i] = i;
	for (int i = 1; i <= N; i++) cin >> cost[i];
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		merge(u, v);
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[find(i)]) {
			if (ans+cost[find(i)] <= k) {
				ans += cost[find(i)];
				visited[find(i)] = 1;
			}
			else {
				flag = false;
				break;
			}
		}
	}
	flag ? cout << ans : cout << "Oh no";
}