#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
//#2467_용액
long long N,Min = 2e9,ans1,ans2, liquid[100001];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> liquid[i];
	int st = 0, en = N - 1;
	while (st < en) {
		long long sum = liquid[st] + liquid[en];
		if (abs(sum) < abs(Min)) {
			Min = sum;
			ans1 = liquid[st];
			ans2 = liquid[en];
		}
		if (!sum)break;
		else if (sum > 0)en--;
		else st++;
	}
	cout << ans1 << ' ' << ans2;
}