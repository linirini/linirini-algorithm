#include<algorithm>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
//#3066_브리징 시그널
int T;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> T;
	while (T--) {
		int N, port[40001];
		vector<int>LIS;
		cin >> N;
		for (int i = 0; i < N; i++)cin >> port[i];
		LIS.push_back(port[0]);
		for (int i = 1; i < N; i++) {
			if (LIS.back() < port[i])LIS.push_back(port[i]);
			else {
				auto it = lower_bound(LIS.begin(), LIS.end(), port[i]);
				*it = port[i];
			}
		}
		cout << LIS.size() << '\n';
	}
}