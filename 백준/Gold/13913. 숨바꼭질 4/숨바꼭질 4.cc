#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
//#13913_숨바꼭질 4
int N, K, visited[200001],par[200001];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < 200001; i++)par[i] = i;
	queue<int>q;
	q.push(N);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now == K) {
			cout << visited[K]<<'\n';
			break;
		}
		if ((now + 1) >= 0 && (now + 1) <= 200000 && !visited[now + 1]) {
			q.push(now + 1);
			visited[now + 1] = visited[now] + 1;
			par[now + 1] = now;
		}
		if ((now - 1) >= 0 && (now - 1) <= 200000 && !visited[now - 1]) {
			q.push(now - 1);
			visited[now - 1] = visited[now] + 1;
			par[now - 1] = now;

		}
		if ((now * 2) >= 0 && (now * 2) <= 200000 && !visited[now * 2]) {
			q.push(now * 2);
			visited[now * 2] = visited[now] + 1;
			par[now * 2] = now;
		}
	}
	int st = K;
	stack<int>s;
	s.push(K);
	while (st != N) {
		s.push(par[st]);
		st = par[st];
	}
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
}