#include<iostream>
#include<algorithm>
using namespace std;
//#1629_곱셈
long long A, B, C;
long long power(int base, int sq) {
	if (sq > 1) {
		long long tmp = power(base, sq / 2);
		long long result = (tmp*tmp) % C;
		if (sq % 2)return (result * base) % C;
		else return result;
	}
	else return base;
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> A >> B >> C;
	cout << power(A,B)%C;
}