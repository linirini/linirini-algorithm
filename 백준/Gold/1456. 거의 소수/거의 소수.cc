#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#1456_거의 소수
long long A, B, cnt;
vector<long long>num, prime, almost_prime;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	for (long long i = 0; i <= 10000001; i++) num.push_back(i);
	for (long long i = 2; i <= 10000000; i++) {
		if (num[i]) {
			prime.push_back(i);
			for (int j = i * 2; j <= 10000000; j += i) num[j] = 0;
		}
	}
	cin >> A >> B;
	for (int i : prime) {
		long long tmp = i;
		while (tmp <= B / i) {
			tmp *= i;
			if (tmp >= A) cnt++;
		}
	}
	cout << cnt;
}