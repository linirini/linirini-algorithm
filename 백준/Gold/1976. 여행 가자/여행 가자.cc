#include<iostream>
#include<algorithm>
using namespace std;
//#1976_여행 가자
int N, M, par[201],c,r,flag;
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
	cin >> N >> M;
	for (int i = 0; i <= N; i++)par[i]=i;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> c;
			if (c)merge(i, j);
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> c;
		if(!i)r = find(c);
		if (r != find(c)) {
			flag = 1;
		}
	}
	!flag?cout << "YES":cout<<"NO";
}