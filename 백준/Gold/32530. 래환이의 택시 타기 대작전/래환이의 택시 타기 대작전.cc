#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
//#32530_래환이의 택시 타기 대작전
int N, ans;
vector<int>v;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		v.push_back(stoi(str.substr(0, 2)) * 60 + stoi(str.substr(3, 2)));
	}
	sort(v.begin(), v.end());
	int st = 0, en = 0;
	while (en<N) {
		if (v[en] - v[st] > 10) {
			ans++;
			st = en;
		}
		else if (en - st + 1 == 3) {
			ans++;
			st = en;
		}
		else if (v[en] - v[st] <= 10)en++;
	}
	cout << ans;
}