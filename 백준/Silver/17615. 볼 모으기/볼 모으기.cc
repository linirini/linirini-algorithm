#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//#17615_볼 모으기
int N,Rcnt,Bcnt,ans=500001;
string str;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N>>str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'R')Rcnt++;
	}
	Bcnt = N - Rcnt;
	if (N == 1||Bcnt == N || Rcnt == N) {
		cout << 0;
		return 0;
	}
	char st = str[0];
	int cnt = 1,i=1;
	while (st == str[i]) {
		cnt++;
		i++;
	}
	if (st == 'R')ans = min(Bcnt, Rcnt - cnt);
	else ans = min(Bcnt - cnt, Rcnt);
	st = str[N - 1];
	cnt = 1,i=N-2;
	while (st == str[i]) {
		cnt++;
		i--;
	}
	if (st == 'R')ans = min(Bcnt, Rcnt - cnt);
	else ans = min(Bcnt - cnt, Rcnt);
	cout << ans;
}