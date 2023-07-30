#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#12837_가계부
long long N, Q, K, c,p,x,q, h = 1;
vector<long long>tree;
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
	cin >> N >> Q;
	while (N > h)h <<= 1;
	tree.resize(2 * h);
	for (int i = 0; i < Q; i++) {
		cin >> c;
		if (c == 1) {
			cin >> p >> x;
			update(p-1, x);
		}
		else {
			cin >> p >> q;
			cout<<query(p, q, 1, 1, h)<<'\n';
		}
	}
}