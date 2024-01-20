# [Gold IV] 카우버거 알바생 - 17208 

[문제 링크](https://www.acmicpc.net/problem/17208) 

### 성능 요약

메모리: 37768 KB, 시간: 36 ms

### 분류

다이나믹 프로그래밍, 배낭 문제

### 아이디어

- 3차원 배낭문제
- dp[i][j][k] : i번째 주문까지 탐색했을 때, j개의 치즈버거와 k개의 감자튀김으로 받을 수 있는 최대 주문 개수
  - dp[i][j][k] = max(dp[i-1][j][k],dp[i-1][j-orders[i].x][k-orders[i].y]+1)
