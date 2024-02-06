#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
int n, m, a, b, t, maxDay, ans, dp[1001][1001];
struct Mine {
    int g;
    int d;
};
Mine mines[1001];
vector<pair<int, int>> edge[1001];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> mines[i].g >> mines[i].d;
        maxDay = max(maxDay, mines[i].g % mines[i].d ? mines[i].g / mines[i].d + 1 : mines[i].g / mines[i].d);
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> t;
        edge[a].push_back({ b, t });
        edge[b].push_back({ a, t });
    }
    dp[1][1] = mines[1].g;
    ans = dp[1][1];
    for (int i = 1; i <= maxDay; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i][j]) {
                for (auto next : edge[j]) {
                    int nextDay = i + next.second;
                    if (nextDay > maxDay)continue;
                    int nextMine = next.first;
                    int nextTreasure = mines[nextMine].g - ((nextDay - 1) * mines[nextMine].d);
                    if (nextTreasure < 0)nextTreasure = 0;
                    dp[nextDay][nextMine] = max(dp[nextDay][nextMine],dp[i][j]+ nextTreasure);
                    ans = max(ans, dp[nextDay][nextMine]);
                }
            }
        }
    }
    cout << ans;
}