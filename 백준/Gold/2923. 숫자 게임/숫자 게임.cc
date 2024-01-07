#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
//#2923_숫자 게임
int N,A[101],B[101];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		A[a]++;
		B[b]++;
		int st = 1, en = 100,Max = 0;
		int tmpA[101], tmpB[101];
		memcpy(tmpA, A, sizeof(A));
		memcpy(tmpB, B, sizeof(B));
		while (st<=100&&en>=1) {
			while (st<=100&&!tmpA[st])st++;
			while(en>=1&&!tmpB[en])en--;
			if (st == 101 || en == 0)break;
			Max = max(Max, st + en);
			if (tmpA[st] > tmpB[en]) {
				tmpA[st] -= tmpB[en];
				tmpB[en] = 0;
			}
			else {
				tmpB[en] -= tmpA[st];
				tmpA[st] = 0;
			}
		}
		cout << Max << '\n';
	}
}