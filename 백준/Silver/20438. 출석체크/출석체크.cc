#include<iostream>
#include<algorithm>
using namespace std;
//#20438_출석체크
int N, K, Q, M, S, E;
int sleep[5001], visited[5001], sum[5001];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> K >> Q >> M;
	for (int i = 0; i < K; i++) {
		int x;
		cin >> x;
		sleep[x] = 1;
	}
	for (int i = 0; i < Q; i++) {
		int x;
		cin >> x;
		if (sleep[x])continue;
		else {
			for (int i = x; i <= N + 2; i += x)
				if (!sleep[i]) visited[i] = 1;
		}
	}
	for (int i = 3; i <= N + 2; i++) {
		if (!visited[i]) sum[i] = sum[i - 1] + 1;
		else sum[i] = sum[i - 1];
	}
	while (M--) {
		cin >> S >> E;
		cout<<sum[E]-sum[S-1]<<'\n';
	}
}