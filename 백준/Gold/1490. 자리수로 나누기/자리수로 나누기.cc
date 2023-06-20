#include<iostream>
#include<algorithm>
using namespace std;
//#1490_자리수로 나누기
long long N, num[10];
long long gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	long long tmp = N;
	while (tmp) {
		num[tmp % 10] = 1;
		tmp /= 10;
	}
	long long lcm = 1, pos = 1;
	for (int i = 1; i < 10; i++)
		if(num[i])lcm = lcm * i / gcd(lcm, i);
	while (1) {
		for (int j = 0; j < pos; j++) {
			if (!((N * pos + j) % lcm)) {
				cout << N * pos + j;
				return 0;
			}
		}
		pos *= 10;
	}
}