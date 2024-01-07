#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
//#1484_다이어트
long long G;
vector<long long>ans;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> G;
	long long st = 1,en=2;
	while (st < en) {
		if (pow(en, 2) - pow(st, 2) == G) {
			ans.push_back(en);
			st++;
		}
		else if (pow(en, 2) - pow(st, 2) > G)st++;
		else if (pow(en, 2) - pow(st, 2) < G)en++;
	}
	if (!ans.size()) {
		cout << -1;
		return 0;
	}
	for (int i = 0; i < ans.size(); i++)cout << ans[i] << '\n';
}
