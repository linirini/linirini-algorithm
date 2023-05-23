#include<iostream>
#include<algorithm>
using namespace std;
//#5557_1학년
int N, arr[105];
long long dp[21][105];
int main() {
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)cin >> arr[i];
    dp[arr[0]][0] = 1;
    for (int i = 1; i < N; i++) {
        int now = arr[i];
        for (int j = 0; j <= 20; j++) {
            if (dp[j][i - 1] > 0) {
                int nextP = j + now;
                int nextM = j - now;
                if (nextP <= 20)dp[nextP][i] += dp[j][i - 1];
                if (nextM >= 0)dp[nextM][i] += dp[j][i - 1];
            }
        }
    }
    cout << dp[arr[N - 1]][N - 2];
}