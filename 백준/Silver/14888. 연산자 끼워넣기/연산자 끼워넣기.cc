#include<iostream>
#include<algorithm>
using namespace std;
//#14888_연산자 끼워넣기
int N, A[101], oper[5], Min=10e9, Max=-10e9;
void go(int idx, int res) {
	if (idx == N) {
		Min = min(Min, res);
		Max = max(Max, res);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (oper[i]) {
			oper[i]--;
			if (i == 0)go(idx + 1, res + A[idx]);
			else if (i == 1)go(idx + 1, res - A[idx]);
			else if (i == 2)go(idx + 1, res * A[idx]);
			else if (i == 3)go(idx + 1, res / A[idx]);
			oper[i]++;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)cin >> A[i];
	for (int i = 0; i < 4; i++)cin >> oper[i];
	go(1, A[0]);
	cout << Max << '\n' << Min;
}