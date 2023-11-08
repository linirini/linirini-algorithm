#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
//#14863_서울에서 경산까지
int N, K, path[100][2], cost[100][2], dp[100][100001];
int go(int n, int k) {
    if (k > K) return -9e8;
    if (n == N) return 0;
    int& ret = dp[n][k];
    if (ret != -1) return ret;
    ret = max(go(n + 1, k + path[n][0]) + cost[n][0], go(n + 1, k + path[n][1]) + cost[n][1]);
    return ret;
}
int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> path[i][0] >> cost[i][0] >> path[i][1] >> cost[i][1];
    memset(dp, -1,sizeof(dp));
    cout<<go(0,0);
}