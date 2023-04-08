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
	for (int i = 0; i < N; i++) {
		if (str[i] == 'R')Rcnt++;
		else Bcnt++;
	}
	ans = min(Rcnt, Bcnt);
	char prev = str[0];
	int cnt = 0;
	for(int i=0;i<N;i++) {
		if (prev != str[i])break;
		cnt++;
	}
	if (prev == 'R')ans = min(ans, min(Bcnt, Rcnt - cnt));
	else ans = min(ans, min(Bcnt - cnt, Rcnt));
	prev = str[N - 1]; 
	cnt = 0;
	for(int i=N-1;i>=0;i--) {
		if (prev != str[i])break;
		cnt++;
	}
	if (prev == 'R')ans = min(ans, min(Bcnt, Rcnt - cnt));
	else ans = min(ans, min(Bcnt - cnt, Rcnt));
	cout << ans;
}
