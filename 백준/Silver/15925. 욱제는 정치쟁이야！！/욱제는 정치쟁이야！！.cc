#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
//#15925_욱제는 정치쟁이야!!
int N, flag, board[31][31];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> flag;
	int mid = N / 2;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < N; i++) {
			int cnt = 0;
			for (int j = 0; j < N; j++) if (board[i][j]==flag)cnt++;
			if (cnt > mid)for (int j = 0; j < N; j++)board[i][j] = flag;
		}
		for (int j = 0; j < N; j++) {
			int cnt = 0;
			for (int i = 0; i < N; i++)if (board[i][j]==flag)cnt++;
			if (cnt > mid)for (int i = 0; i < N; i++)board[i][j] = flag;
		}
	}
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if (board[i][j] != flag) {
				cout << 0;
				return 0;
			}
	cout << 1;
}