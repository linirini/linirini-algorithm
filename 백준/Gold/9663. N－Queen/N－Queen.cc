#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<stack>
#include<cmath>
#include<math.h>
#include<functional>
#include<map>
#include<set>
using namespace std;
//#9663_N-Queen
int N, cnt;
int chess[15];//(인덱스:행, 값: 열)
bool check(int row) {//유망한지 판단
	for(int i=0;i<row;i++) {//입력받은 행까지 탐색
		//(같은 열에 위치) or (행 번호 차이=열번호 차이:같은 대각선상 위치)
		if (chess[i] == chess[row] || row - i == abs(chess[i] - chess[row])) {
			return 0;
		}
	}
	return 1;
}
void queen(int row) {
	if (row == N) {
		cnt++;//마지막 행까지 찾기 완료
		return;
	}
	else {
		for (int i = 0; i < N; i++) {
			chess[row] = i;//row번째 행의 i번째 열에 위치시켜보기
			if (check(row)) {//위의 위치가 유망하다면
				queen(row + 1);//다음 행으로 넘어간다.
			}
		}
	}
}
int main() {
	cin >> N;
	queen(0);//첫 행부터 탐색 시작
	cout << cnt;
}