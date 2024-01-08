#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
//#12851_숨바꼭질 2
int N, K,visited[100001],Min=1e9,ans;
queue<pair<int, int>>q;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> K;
	q.push({N,0});
	while (!q.empty()) {
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();
		visited[now] = 1;
		if (now == K&&Min>=cnt) {
			Min = cnt;
			ans++;
			continue;
		}
		if (now * 2 <= 100000 && !visited[now * 2]) q.push({ now * 2,cnt + 1 });
		if (now + 1 <= 100000 && !visited[now + 1]) q.push({ now + 1,cnt + 1 });
		if (now - 1 >= 0 && !visited[now - 1]) q.push({ now - 1,cnt + 1 });
	}
	cout << Min << '\n' << ans;
}