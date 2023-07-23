#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
//#17352_여러분의 다리가 되어 드리겠습니다.
int N, par[300001];
int find(int x) {
	if (par[x] == x)return x;
	else return par[x] = find(par[x]);
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y)par[y] = x;
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)par[i] = i;
	for (int i = 0; i < N - 2; i++) {
		int a, b;
		cin >> a >> b;
		merge(a, b);
	}
	int root = find(1);
	for (int i = 2; i <= N; i++) {
		if (root != find(i)) {
			cout << root << ' ' << i;
			break;
		}
	}
}