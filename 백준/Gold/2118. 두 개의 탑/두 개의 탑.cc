#include<iostream>
#include<algorithm>
using namespace std;
//#2118_두 개의 탑
int N, tower[50001],dis[50002];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> tower[i];
	dis[1] = tower[1];
	for (int i = 2; i <= N; i++) dis[i] = dis[i - 1] + tower[i];
	int total = dis[N],ans=0,st=0,en=1;
	while (true) {
		if (en > N)break;
		if (st == en) {
			en++; 
			continue;
		}
		int tmp = dis[en] - dis[st], tmp2 = total - tmp;
		ans = max(ans, min(tmp, tmp2));
		if (tmp < tmp2)en++;
		else st++;
	}
	cout << ans;
}