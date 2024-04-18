#include<iostream>
#include<algorithm>
using namespace std;
//#16987_계란으로 계란치기
int N, ans;
struct Egg{
	int S;
	int W;
};
Egg eggs[10];
void go(int now) {
    if (now >= N) {
        int cnt = 0;
        for (int i = 0; i < N; i++)  if (eggs[i].S <= 0) cnt++;
        ans = max(ans, cnt);
        return;
    }
    int flag = 0;
    for (int i = 0; i < N; i++) {
        if (i == now) continue;
        if (eggs[now].S > 0 && eggs[i].S > 0) {
            eggs[now].S -= eggs[i].W;
            eggs[i].S -= eggs[now].W;
            flag = true;
            go(now + 1);
            eggs[now].S += eggs[i].W;
            eggs[i].S += eggs[now].W;
        }
    }
    if (!flag) go(now + 1);
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)cin >> eggs[i].S >> eggs[i].W;
    go(0);
	cout << ans;
}