#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#17250_은하철도
int N, M, u, v;
int galaxy[100001],cnt[100001];
int find(int x) {
	if (galaxy[x] == x)return x;
	else return find(galaxy[x]);
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) {
		galaxy[x] = y;
		cnt[y] += cnt[x];
		cnt[x] = 0;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		galaxy[i] = i;
		cin >> cnt[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		merge(u, v);
		cout << cnt[find(u)] << '\n';
	}
}