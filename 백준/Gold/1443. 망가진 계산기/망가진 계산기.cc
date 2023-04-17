#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int D, P,ans,Min=1e9;
void go(int mul, int num,int cnt) {
	if (cnt==P){
		ans = max(ans, num);
		Min = min(Min, num);
		return;
	}
	if (mul < 2) return;
	if ((num*mul) / pow(10, D-1) >= 10) {
		go(mul - 1, num, cnt);
	}
	else {
		go(mul - 1, num, cnt);
		go(mul, num * mul, cnt + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> D >> P;
	go(9, 1, 0);
	Min/pow(10,D-1)>=10?cout<<-1<<'\n':cout << ans << '\n';
}