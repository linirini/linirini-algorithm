#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#28015_영역 색칠
int N, M, ans, board[101][101];
vector<vector<int>>v;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		vector<int>tmp;
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (!board[i][j]) {
				if (tmp.size()) {
					v.push_back(tmp);
					tmp.clear();
				}
			}
			else tmp.push_back(board[i][j]);
		}
		if(tmp.size())v.push_back(tmp); 
		tmp.clear();
	}
	for (int i = 0; i < v.size(); i++) {
		int prev = v[i][0], cnt[3] = { 0, };
		cnt[prev]++;
		for (int j = 1; j < v[i].size(); j++) {
			if (prev != v[i][j]) {
				cnt[v[i][j]]++;
				prev = v[i][j];
			}
		}
		if (cnt[1] && cnt[2])ans += min(cnt[1], cnt[2]) + 1;
		else if (cnt[1] && !cnt[2])ans += cnt[1];
		else if (!cnt[1] && cnt[2])ans += cnt[2];
	}
	cout << ans;
}