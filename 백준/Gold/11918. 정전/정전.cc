#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<long long, long long>>coor;
long long N, L, ans;
//#11918_정전
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		long long x;
		cin >> x;
		coor.push_back({ x + L, -1 });
		coor.push_back({ x - L, 1 });
	}
	sort(coor.begin(), coor.end());
	long long pre = coor[0].first;
	long long sum = coor[0].second;
	for (int i = 1; i < coor.size();i++) {
		if (sum == 1 && sum + coor[i].second == 2) pre = coor[i].first;
		else if (sum == 2 && sum + coor[i].second == 1) ans += (coor[i].first - pre);
		sum += coor[i].second;
	}
	cout << ans;
}
