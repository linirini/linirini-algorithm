#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
//#32069_가로등
long long L, N, K, k;
queue<pair<long long, long long>> q;
set<long long>visited;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> L >> N >> K;
	for (int i = 0; i < N; i++) {
		long long x;
		cin >> x;
		q.push({x,0});
		visited.insert(x);
	}
	while (k!= K) {
		long long now = q.front().first;
		long long cost = q.front().second;
		q.pop();
		cout << cost << '\n';
		k++;
		if (now + 1 >= 0 && now + 1 <= L && !visited.count(now + 1)) {
			q.push({ now + 1, cost + 1 });
			visited.insert(now+1);
		}
		if (now - 1 >= 0 && now - 1 <= L && !visited.count(now - 1)) {
			q.push({ now - 1, cost + 1 });
			visited.insert(now - 1);
		}
	}
}