#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#19949 영재의 시험
vector<int> v;
int dp[10][6][6][10];
int recur(int cur, int ppre, int pre, int total){
    if (cur == 10){
        if (total >= 5) return 1;
        return 0;
    }
    if (dp[cur][ppre][pre][total] != -1) return dp[cur][ppre][pre][total];
    int ret = 0;
    for (int i = 1; i < 6; i++){
        if (ppre == pre && pre == i) continue;
        if (v[cur] == i) ret += recur(cur + 1, pre, i, total + 1);
        else ret += recur(cur + 1, pre, i, total);
    }
    dp[cur][ppre][pre][total] = ret;
    return dp[cur][ppre][pre][total];
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    v.resize(10);
    for (int i = 0; i < 10;i++) cin >> v[i];
    fill(&dp[0][0][0][0], &dp[9][5][5][10], -1);
    cout << recur(0, 0, 0, 0);
    return 0;
}