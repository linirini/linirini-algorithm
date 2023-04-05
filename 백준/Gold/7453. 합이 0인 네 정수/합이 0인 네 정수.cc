#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#7453_합이 0인 네 정수
long long n, A[4001], B[4001], C[4001], D[4001], ans;
vector<long long>sum1, sum2;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) {
			sum1.push_back(A[i] + B[j]);
			sum2.push_back(C[i] + D[j]);
		}
	sort(sum1.begin(), sum1.end());
	sort(sum2.begin(), sum2.end());
	for (int i = 0; i < sum1.size(); i++) {
		int lowIdx = lower_bound(sum2.begin(), sum2.end(), -sum1[i])-sum2.begin();
		int upIdx = upper_bound(sum2.begin(), sum2.end(), -sum1[i]) - sum2.begin();
		if (!(sum1[i] + sum2[lowIdx]))ans+=upIdx-lowIdx;
	}
	cout << ans;
}