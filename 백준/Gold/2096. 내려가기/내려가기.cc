#include<iostream>
#include<algorithm>
using namespace std;
//#2096_내려가기
int N, maxDp[2][3], minDp[2][3];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	int	k = 0;
	int Max, Min;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		maxDp[k][0] = max(maxDp[1 - k][0], maxDp[1 - k][1]) + x;
		maxDp[k][1] = max(max(maxDp[1 - k][0], maxDp[1 - k][1]), maxDp[1 - k][2]) + y;
		maxDp[k][2] = max(maxDp[1 - k][1], maxDp[1 - k][2]) + z;
		minDp[k][0] = min(minDp[1 - k][0], minDp[1 - k][1]) + x;
		minDp[k][1] = min(min(minDp[1 - k][0], minDp[1 - k][1]), minDp[1 - k][2]) + y;
		minDp[k][2] = min(minDp[1 - k][1], minDp[1 - k][2]) + z;
		k = 1 - k;
	}
	Max = max(max(maxDp[1 - k][0], maxDp[1 - k][1]), maxDp[1 - k][2]);
	Min = min(min(minDp[1 - k][0], minDp[1 - k][1]), minDp[1 - k][2]);
	cout << Max << ' ' << Min;
}