#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
//#14430_자원 캐기
int N, M, board[301][301],dp[301][301];
int main() {
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    dp[0][0] = board[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int nx = i + 1;
            int ny = j + 1;
            if (nx < N)
                dp[nx][j] = max(dp[nx][j], dp[i][j] + board[nx][j]);
            if (ny < M)
                dp[i][ny] = max(dp[i][ny], dp[i][j] + board[i][ny]);
        }
    }
    cout << dp[N - 1][M - 1];
}