#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<stack>
#include<cmath>
#include<math.h>
#include<functional>
#include<map>
#include<set>
using namespace std;
//#14428_수열과 쿼리 16 
int N, M, a, b, c, h = 1;
vector<pair<int, int>>tree;
vector<int>num;
void update(int idx, int value) {
	tree[idx] = { value,idx - h + 1 };
	while (idx > 1) {
		idx /= 2;
		tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
	}
}
pair<int,int> query(int L, int R, int node, int nodeL, int nodeR) {
	if (L <= nodeL && nodeR <= R) {
		return tree[node];
	}
	if (nodeR < L || R < nodeL) {
		return { 1e9,1e9 };
	}
	int mid = (nodeL + nodeR) / 2;
	pair<int, int> l = query(L, R, node * 2, nodeL, mid);
	pair<int, int> r = query(L, R, node * 2 + 1, mid + 1, nodeR);
	return min(l,r);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	while (N > h)h <<= 1;
	tree.resize(2 * h, { 1e9,1e9 });
	num.resize(N + 1);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
		update(i+h, num[i]);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b>> c;
		if (a == 1)update(b - 1+h, c);
		else cout << query(b, c, 1, 1, h).second << '\n';
	}
}