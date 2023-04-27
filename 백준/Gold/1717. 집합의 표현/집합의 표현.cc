#include<algorithm>
#include<iostream>
using namespace std;
//#1717_집합의 표현
int n, m, c, a, b,par[1000001];
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
	cin >> n >> m;
	for (int i = 0; i <= n; i++)par[i] = i;
	while (m--) {
		cin >> c >> a >> b;
		if (!c) merge(a, b);
		else {
			if (find(a) == find(b))cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
	}
}