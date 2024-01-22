#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#20303_할로윈의 양아치
int N, M, K,c[30001],parent[30001],dp[30001],children[30001],candy[30001];
int find(int x) {
	if (x == parent[x])return x;
	else return parent[x] = find(parent[x]);
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return;
	if (x > y)swap(x, y);
	parent[y] = x;
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i <= N; i++)parent[i] = i;
	for (int i = 1; i <= N; i++)cin >> c[i];
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		merge(a, b);
	}
	for (int i = 1; i <= N; i++) {
		int par = find(i);
		candy[par] += c[i];
		children[par]++;

	}
	for (int i = 1; i <= N; i++) {
		for (int j = K - 1 ; j>=children[i] ; j--)
			dp[j] = max(dp[j], dp[j - children[i]] + candy[i]);
	}
	cout << dp[K-1];
}