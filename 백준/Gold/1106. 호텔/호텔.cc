#include<iostream>
#include<algorithm>
using namespace std;
//#1106_호텔
int C, N,dp[100001];
struct Promotion {
	int cost;
	int customer;
};
Promotion hotel[1001];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> C >> N;
	for (int i = 1; i <= N; i++) cin >> hotel[i].cost >> hotel[i].customer;
	for (int i = 1; i <= N; i++) 
		for(int j=hotel[i].cost;j<=100000;j++)dp[j] = max(dp[j], dp[j - hotel[i].cost] + hotel[i].customer);
	for (int i = 1; i <= 100000; i++) {
		if (dp[i] >= C) {
			cout << i;
			return 0;
		}
	}
}