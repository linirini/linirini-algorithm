#include <iostream>
#include<string>
using namespace std;
//#16926_배열 돌리기 1
int arr[301][301];
int N, M, R;
void rotate_counter_clock_wise() {
    int square_count = min(N,M)/2;
    for (int cnt = 0; cnt < square_count; cnt ++) {
        int MaxN = N - cnt - 1;
        int MaxM = M - cnt - 1;
        int tmp = arr[cnt][cnt];
        // 위쪽 변 : 왼 <- 오
        for (int i = cnt; i < MaxM; i++) {
            arr[cnt][i] = arr[cnt][i + 1];
        }
        // 오른쪽 변 : 아래 -> 위
        for (int i = cnt; i < MaxN; i++) {
            arr[i][MaxM] = arr[i + 1][MaxM];
        }
        // 아래쪽 변 : 왼 -> 오
        for (int i = MaxM; i > cnt; i--) {
            arr[MaxN][i] = arr[MaxN][i - 1];
        }
        // 왼쪽 변 : 위 -> 아래
        for (int i = MaxN; i > cnt; i--) {
            arr[i][cnt] = arr[i - 1][cnt];
        }
        arr[cnt + 1][cnt] = tmp;
    }
}
int main() {
    cin >> N >> M>>R;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> arr[i][j];
    for (int i = 0; i < R; i++)rotate_counter_clock_wise();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}