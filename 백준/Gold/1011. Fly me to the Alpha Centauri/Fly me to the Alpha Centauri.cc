#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
//#1011_Fly me to the Alpha Centauri
int T, x, y,cnt;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> x >> y;
		int dis = y - x;
		int crit = sqrt(dis);
		pow(crit, 2) == dis ? cnt = 2 * crit - 1 : pow(crit,2)<dis&&dis<=pow(crit,2)+crit?cnt = 2 * crit:cnt = 2*crit+1;
		cout << cnt<<'\n';
	}
}