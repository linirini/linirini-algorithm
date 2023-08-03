#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#2517_달리기
long long N, h = 1,ans[5000001];
vector<long long> tree;
vector<pair<long long, long long>>player;
void update(int idx, long long value) {
	idx += h;
	tree[idx] += value;
	while (idx > 1) {
		idx /= 2;
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
	}
}
long long query(int L, int R, int node, int nodeL, int nodeR) {
	if (L <= nodeL && nodeR <= R)return tree[node];
	if (nodeR < L || R < nodeL)return 0;
	int mid = (nodeL + nodeR) / 2;
	return query(L, R, node * 2, nodeL, mid) + query(L, R, node * 2 + 1, mid + 1, nodeR);
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	while (N > h)h <<= 1;
	tree.resize(2 * h);
	player.resize(N + 1);
	for (int i = 0; i < N; i++) {
		cin >> player[i].first;
		player[i].second = i;
	}
	sort(player.begin(), player.end(), greater<>());
	for (int i = 0; i < N; i++) {
		ans[player[i].second] = query(1, player[i].second + 1, 1, 1, h)+1;
		update(player[i].second, 1);
	}
	for (int i = 0; i < N; i++)
		cout << ans[i] << '\n';
}