#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
//#19942_다이어트
int N, mp, mf, ms, mv,mc=1e9,visited[16];
vector<vector<int>> ans;
struct Nutrients {
	int p;
	int f;
	int s;
	int v;
	int c;
};
Nutrients food[16];
void go(int now, int p, int f, int s, int v, int c) {
	if (p >= mp && f >= mf && s >= ms && v >= mv) {
		if (c < mc) {
			vector<int>tmp;
			ans.clear();
			for (int i = 1; i <= N; i++)
				if (visited[i]) tmp.push_back(i);
			mc = c;
			ans.push_back(tmp);
		}
		else if (c == mc) {
			vector<int>tmp;
			for (int i = 1; i <= N; i++)
				if (visited[i]) tmp.push_back(i);
			ans.push_back(tmp);
		}
		return;
	}
	else {
		for (int i = now; i <= N; i++) {
			if (visited[i])continue;
			visited[i] = 1;
			go(i, p + food[i].p, f + food[i].f, s + food[i].s, v + food[i].v, c + food[i].c);
			visited[i] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> mp >> mf >> ms >> mv;
	for (int i = 1; i <= N; i++)
		cin >> food[i].p >> food[i].f >> food[i].s >> food[i].v >> food[i].c;
	go(1, 0, 0, 0, 0, 0);
	if (mc == 1e9) {
		cout << -1;
		return 0;
	}
	cout << mc << '\n';
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans[0].size(); i++)cout << ans[0][i] << ' ';
}