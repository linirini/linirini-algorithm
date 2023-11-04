#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#20366_같이 눈사람 만들래?
int N, H[601],ans=1e9;
vector<pair<int, pair<int, int>>>snowman;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> H[i];
	for (int i = 0; i < N - 1; i++)
		for (int j = i + 1; j < N; j++)
			snowman.push_back({ H[i] + H[j],{i,j } });
	sort(snowman.begin(), snowman.end());
	for (int i = 0; i < snowman.size() - 1; i++) {
		for (int j = i + 1; j < snowman.size(); j++) {
			if (snowman[i].second.first != snowman[j].second.first && snowman[i].second.second != snowman[j].second.second && snowman[i].second.first != snowman[j].second.second && snowman[i].second.second != snowman[j].second.first) {
				ans = min(ans, snowman[j].first - snowman[i].first);
				break;
			}
		}
	}
	cout << ans;
}