#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
int n, m;
int maxDay;
vector<pair<int, int>> node(1005);
vector<vector<pair<int, int>>> edge(1005);
int dp[1005][1005];
int ans = -1;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int g, d;
        cin >> g >> d;
        node[i] = { g, d };
        maxDay = max(maxDay, g % d ? g / d + 1 : g / d);
    }
    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        edge[a].push_back({ b, t });
        edge[b].push_back({ a, t });
    }
    dp[1][1] = node[1].first;
    ans = dp[1][1];
    for (int i = 1; i <= maxDay; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i][j] > 0) {
                for (int k = 0; k < edge[j].size(); k++) {
                    int nextday = i + edge[j][k].second;
                    if (nextday > maxDay)continue;
                    int nextnode = edge[j][k].first;
                    int nextval = node[nextnode].first - ((nextday - 1) * node[nextnode].second);
                    if (nextval < 0)nextval = 0;
                    dp[nextday][nextnode] = max(dp[nextday][nextnode],dp[i][j]+ nextval);
                    ans = max(ans, dp[nextday][nextnode]);
                }
            }
        }
    }

    cout << ans;
    return 0;
}