#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#15565_귀여운 라이언
int N, K, Min=1e9;
vector<int>dolls;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (num == 1)dolls.push_back(i);
	}
	if (dolls.size() < K) {
		cout << -1;
		return 0;
	}
	for (int i = 0; i <= dolls.size()-K; i++) Min = min(Min,dolls[i + K - 1] - dolls[i] + 1);
	cout << Min;
}