#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#15961_회전 초밥
int N, d, k, c, visited[3001], cnt,ans;
vector<int>sushi;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> d >> k >> c;
	sushi.resize(N + k);
	visited[c] = 1;
	cnt = 1;
	for (int i = 0; i < N; i++) {
		cin >> sushi[i];
		if (i < k) {
			visited[sushi[i]]++;
			if (visited[sushi[i]]==1)cnt++;
		}
	}
	for (int i = 0; i < k; i++)sushi[i+N] = sushi[i];
	int st = 0, en = k-1;
	while (1) {
		ans = max(ans, cnt);
		if (st == N)break;
		visited[sushi[st]]--;
		if (!visited[sushi[st++]])cnt--;
		visited[sushi[++en]]++;
		if (visited[sushi[en]] == 1)cnt++;
	}
	cout << ans;
}