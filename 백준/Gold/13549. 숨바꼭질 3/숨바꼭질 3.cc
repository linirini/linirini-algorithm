#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
//#13549_숨바꼭질 3
int N, K, visited[200001];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> K;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, N });
	visited[N] = 1;
	while (!pq.empty()) {
		int time = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (now == K) {
			cout<<time;
			break;
		}
		if ((now * 2) >= 0 && (now * 2) <= 200000 && !visited[now * 2]) {
			pq.push({ time,now * 2 });
			visited[now * 2] = 1;
		}
		if ((now + 1) >= 0 && (now + 1) <= 200000 && !visited[now + 1]) {
			pq.push({ time+1,now + 1 });
			visited[now + 1] = 1;
		}
		if ((now - 1) >= 0 && (now - 1) <= 200000 && !visited[now - 1]) {
			pq.push({ time + 1,now - 1 });
			visited[now - 1] = 1;
		}
	}
}
