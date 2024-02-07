#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
//#14698_전생했더니 슬라임 연구자였던 건에 대하여 (Hard)
long long T, N, C;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		long long energy = 1;
		priority_queue<long long, vector<long long>, greater<long long>>pq;
		for (int i = 0; i < N; i++) {
			cin >> C;
			pq.push(C);
		}
		while (!pq.empty()) {
			long long slime1 = pq.top();
			pq.pop();
			if (!pq.empty()) {
				long long slime2 = pq.top();
				pq.pop();
				long long curEnergy = slime1 * slime2;
				pq.push(curEnergy);
				curEnergy %= 1000000007;
				energy *= curEnergy;
				energy %= 1000000007;
			}
		}
		cout << energy % 1000000007 << '\n';
	}
}