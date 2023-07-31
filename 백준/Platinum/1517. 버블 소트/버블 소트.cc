#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#1517_버블 소트
long long N, h=1,cnt;
vector<long long> tree;
vector<pair<long long, long long>>A;
void update(int idx, long long value) {
	idx += h;
	tree[idx] = value;
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
	A.resize(N+1);
	for (int i = 0; i < N; i++) {
		cin >> A[i].first;
		A[i].second = i;
	}
	sort(A.begin(), A.end(),greater<>());
	//for (int i = 0; i < N; i++)cout << "first : "<< A[i].first << " second : " << A[i].second << '\n';
	for (int i = 0; i < N; i++) {
		cnt += query(1, A[i].second + 1, 1, 1, h);
		update(A[i].second, 1);
	}
	cout << cnt;
}