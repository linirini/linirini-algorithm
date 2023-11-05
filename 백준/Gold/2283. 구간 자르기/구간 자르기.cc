#include<iostream>
#include<algorithm>
using namespace std;
//#2283_구간 자르기
int N, K,visited[1000001];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int u, v;
		cin >> u >> v;
		for (int j = u; j < v; j++)
			visited[j]++;
	}
	int st = 0, en = 0, cnt = 0;
	while (st<=en&&en<=1000000) {
		if (cnt == K) {
			cout << st << ' ' << en;
			return 0;
		}
		else if (cnt < K) cnt += visited[en++];
		else cnt -= visited[st++];
	}
	cout << "0 0";
}