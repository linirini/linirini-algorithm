#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#10165_버스 노선
int N, M,visited[500005];
vector<pair<pair<int, int>,int>>line;
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	if (a.first.first == b.first.first)return a.first.second > b.first.second;
	return a.first.first < b.first.first;
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		if (a < b) {
			line.push_back({ { a,b }, i });
			line.push_back({ {a + N,b + N},i });
		}
		else line.push_back({{ a, b + N }, i});
	}
	sort(line.begin(),line.end(),cmp);
	int st = 0, en = 0, l = 0, r = 0;
	for (int i = 0; i < line.size(); i++) {
		st = line[i].first.first;
		en = line[i].first.second;
		int idx = line[i].second;
		if (!visited[idx] && l <= st && en <= r) {
			visited[idx] = 1;
			continue;
		}
		l = st;
		r = en;
	}
	for (int i = 0; i < M; i++)
		if (!visited[i])cout << i + 1 << ' ';
}