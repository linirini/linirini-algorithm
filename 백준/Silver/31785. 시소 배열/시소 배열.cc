#include<iostream>
#include<algorithm>
using namespace std;
//#31785_시소 배열
long long Q, A[500001];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> Q;
	long long x, command, st=1, en=0;
	while (Q--) {
		cin >> command;
		if (command == 1) {
			cin >> x;
			A[en+1] = A[en] + x;
			en++;
		}
		else {
			long long mid = (en - st + 1) / 2 + st - 1;
			long long left = A[mid] - A[st - 1];
			long long right = A[en] - A[mid];
			if (left <= right) {
				st = mid+1;
				cout << left << '\n';
			}
			else {
				en = mid;
				cout<<right<<'\n';
			}
		}
	}
	for (int i = st; i <= en; i++) cout << A[i] - A[i - 1] << ' ';
}