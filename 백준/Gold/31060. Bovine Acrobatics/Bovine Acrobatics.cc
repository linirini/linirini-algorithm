#include<iostream>
#include<algorithm>
#include<vector>
#include<queue> 
using namespace std;
//#31060_Bovine Acrobatics
long long N, K, M, diff[200001],ans;
vector<pair<long long, long long>> cows;
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
	return a.first > b.first;
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		int w, a;
		cin >> w >> a;
		cows.push_back({ w,a });
	}
	sort(cows.begin(), cows.end(), cmp);
	long long towerCount = M;
	queue<pair<int, int>>candidates;
	for (int i = 0; i < N; i++) {
		long long curW = cows[i].first;
		long long curC = cows[i].second;
		while (!candidates.empty() && candidates.front().first - K >= curW) {
			towerCount += candidates.front().second;
			candidates.pop();
		}
		int usedCows = min(towerCount, curC);
		if (usedCows > 0) {
			candidates.push({ curW, usedCows });
			towerCount -= usedCows;
			ans += usedCows;
		}
	}
	cout << ans << '\n';
}