#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
//#2023_신기한 소수
int N, prime[] = { 2,3,5,7 };
bool isPrime(int n) {
	for (int i = 2; i <= sqrt(n); i++)
		if (!(n % i))return false;
	return true;
}
void go(int cnt, int num) {
	if (cnt == N) {
		cout << num << '\n';
		return;
	}
	for (int i = 1; i < 10; i+=2) {
		int tmp = num * 10 + i;
		if (isPrime(tmp))go(cnt + 1, tmp);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < 4; i++)
		go(1, prime[i]);
}