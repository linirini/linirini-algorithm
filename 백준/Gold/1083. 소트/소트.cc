#include<iostream>
#include<algorithm>
using namespace std;
//#1083_소트
int N, A[51], S;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)cin>>A[i];
	cin >> S;
	for (int i = 0; i < N; i++) {
		if (!S)break;
		int Max = -1, idx = -1,cnt=0;
		for (int j = i; j < N && j-i<=S; j++) {
			if (Max < A[j]) {
				Max = A[j];
				idx = j;
			}
			cnt++;
		}
		S -= (idx - i);
		for (int j = idx; j > i; j--) swap(A[j - 1], A[j]);
	}
	for (int i = 0; i < N; i++)cout << A[i] << ' ';
}