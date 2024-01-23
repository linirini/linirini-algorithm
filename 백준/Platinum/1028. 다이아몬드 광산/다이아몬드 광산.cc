#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
//#1028_다이아몬드 광산
int R, C, ans, downDp[2][751][751], upDp[2][751][751], board[751][751];
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> R >> C;
    for (int i = 1; i <= R; i++) {
        string str;
        cin >> str;
        for (int j = 1; j <= C; j++) board[i][j]=str[j-1]-'0';
    }
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (board[i][j]) {
                upDp[0][i][j] = upDp[0][i - 1][j + 1] + 1;
                upDp[1][i][j] = upDp[1][i - 1][j - 1] + 1;
            }
        }
    }
    for (int i = R; i >= 1; i--) {
        for (int j = 1; j <= C; j++) {
            if (board[i][j]) {
                downDp[0][i][j] = downDp[0][i + 1][j + 1] + 1;
                downDp[1][i][j] = downDp[1][i + 1][j - 1] + 1;
            }
        }
    }
    for (int i = 1; i <= R; i++){
        for (int j = 1; j <= C; j++) {
            if (board[i][j]) {
                for (int k = 1; k <= min(upDp[0][i][j], downDp[0][i][j]); k++) {
                    int pos = j + 2 * (k - 1);
                    if (pos > C) break;
                    if (board[i][pos]) {
                        int leftMax = min(upDp[1][i][pos], downDp[1][i][pos]);
                        if (leftMax >= k) ans = max(ans, k);
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}