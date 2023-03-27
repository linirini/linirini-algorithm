#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
//#13306_트리
int N, Q,parent[200001],x,b,c,d;
int find(int x) {
	if (parent[x] == x)return x;
	else return find(parent[x]);
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> Q;
	parent[1] = 1;
	for (int i = 2; i <= N; i++) {
		cin>>parent[i];
	}
	for (int i = 0; i < N - 1 + Q; i++) {
		cin >> x;
		if (x == 1) {
			cin >> c >> d;
			if (find(c) == find(d)) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
		else if(x == 0){
			cin >> b;
			parent[b] = b;
		}
	}
}