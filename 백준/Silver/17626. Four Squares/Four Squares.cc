#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
//#17626_Four Squares
int n;
vector <int> dp;
int main() {
    cin >> n;
    dp.resize(50001, 50001);
    for (int i = 1; i <= n; i++) {
        if ((int)sqrt(i) * (int)sqrt(i) == i) dp[i] = 1;
        for (int j = 1; j <= (int)sqrt(i); j++) {
            dp[i] = min(dp[i], dp[j * j] + dp[i - j * j]);
        }
    }
    cout << dp[n];
}