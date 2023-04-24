#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;
//#5766_할아버지는 유명해
int N, M,n;
bool cmp(pair<int, int> a, pair<int, int>b) {return a.first > b.first;}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	while (1) {
		map<int, int>m;
		vector<pair<int, int>>v;
		cin >> N >> M;
		if (!N && !M)return 0;
		for (int i = 0; i < N; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> n;
				if (m.find(n) != m.end())m[n]++;
				else m.insert({ n,1 });
			}
		}
		for (auto now : m) v.push_back({ now.second,now.first });
		sort(v.begin(), v.end(),cmp);
		int rank = 1, score = v[0].first;
		vector<int>ans;
		for (int i = 1; i < v.size(); i++) {
			if (v[i].first != score) {
				rank++;
				score = v[i].first;
			}
			if (rank == 2)ans.push_back(v[i].second);
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)cout << ans[i] << ' ';
		cout << '\n';
	}
}