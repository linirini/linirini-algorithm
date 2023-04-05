#include<iostream>
#include<algorithm>
using namespace std;
long long N,ans=1;
int main() {
	cin >> N;
	for (N = N; N >= 5; N -= 3) ans = (3 * ans) % 10007;
	cout << (ans * N) % 10007;
}