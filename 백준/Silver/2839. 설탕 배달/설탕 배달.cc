#include<iostream>
#include<algorithm>
using namespace std;
//#2839_설탕 배달
int N,ans;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0);
	cin >> N;
	while (N>0) {
		if (!(N % 5)) {
			ans += N / 5;
			break;
		}
		N -= 3;
		ans++;
	}
	N<0?cout<<-1:cout << ans;
}
