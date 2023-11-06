#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<stack>
#include<cmath>
#include<cstring>
#include<math.h>
#include<functional>
#include<map>
#include<set>
using namespace std;
//#21758_꿀 따기
int N;
long long bee[100002], sum[100002],ans;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> bee[i];
		sum[i] = bee[i] + sum[i - 1];
	}
	for (int i = 2; i < N; i++) {
		ans = max(ans, sum[N] - bee[1] - bee[i] + sum[N] - sum[i]);
	}
	for (int i = 2; i < N; i++) {
		ans = max(ans, sum[N] - bee[N] - bee[i] + sum[i - 1]);
	}
	for (int i = 2; i < N; i++) {
		ans = max(ans, sum[i] - bee[1] + sum[N] - sum[i - 1] - bee[N]);
	}
	cout << ans << '\n';
}