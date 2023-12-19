#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<stack>
#include<cmath>
#include<cstdio>
#include<math.h>
#include<functional>
#include<map>
#include<set>
using namespace std;
//#2230_수 고르기
//이분탐색으로도 풀이 가능, lower_bount 사용
//N개의 정수로 이루어진 수열에서 두 수를 골랐을 떄 그 차이그 M이상이면서 제일 작은 경우 구하는 문제
//전처리로 수열을 정렬하고 투 포인터를 이용해 구할 수 있다.
//A[end}-A[start]가 M보다 작다면 두 수의 차이가 더 커져야하므로 end를 늘려주고 M보다 크거나 같다면 start를 하나 늘려준다.
long long N, K, A[1000001], Min = 2e9;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A + N);
	int st = 0, en = 0;
	long long dif=0;
	while (en<N) {
		if (dif >= K) {
			Min = min(Min, dif);
			if (st == en) {
				en++;
				if (en == N)break;
				dif = A[en] - A[st];
			}
			else {
				st++;
				dif = A[en] - A[st];
			}
		}
		else {
			en++;
			if (en == N)break;
			dif = A[en] - A[st];
		}
	}
	cout << Min;
}