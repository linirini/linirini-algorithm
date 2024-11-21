#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
//#26646_알프스 케이블카
int N, H[50001],ans;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> H[i];
	for (int i = 1; i < N; i++) ans += pow(H[i] + H[i - 1], 2) + pow(abs(H[i - 1] - H[i]), 2);
	cout << ans;
}
