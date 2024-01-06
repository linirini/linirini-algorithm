#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
//#2470_두 용액
long long N,Min=2e10,ans1,ans2;
vector<long long>liquid;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	liquid.resize(N);
	for (int i = 0; i < N; i++) cin >> liquid[i];
	sort(liquid.begin(), liquid.end());
	int st = 0, en = N - 1;
	while (st < en) {
		if (abs(liquid[st] + liquid[en]) < Min) {
			Min = abs(liquid[st] + liquid[en]);
			ans1 = liquid[st];
			ans2 = liquid[en];
			if (!Min)break;
		}
		if (liquid[st] + liquid[en] < 0)st++;
		else en--;
	}
	cout << ans1 << ' ' << ans2;
}