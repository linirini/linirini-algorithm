#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#11437_LCA
int T, N, A, B;
int visited[50001], parent[50001];
int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			visited[i] = 0;
			parent[i] = i;
		}
		for (int i = 0; i < N - 1; i++) {
			cin >> A >> B;
			parent[B] = A;
		}
		int a, b;
		cin >> a >> b;
		visited[a] = 1;
		while (a != parent[a]) {
			a = parent[a];
			visited[a] = 1;
		}
		while (true) {
			if (visited[b]) {
				cout << b << '\n';
				break;
			}
			b = parent[b];
		}
	}
}