# [Gold V] 합분해 - 2225 

[문제 링크](https://www.acmicpc.net/problem/2225) 

### 성능 요약

메모리: 2180 KB, 시간: 12 ms

### 분류

다이나믹 프로그래밍, 수학

### 아이디어

- dp[i][j] : i개 수를 사용하여 j를 만들 수 있는 경우의 수
- DP[K][N] = DP[K-1][0] + DP[K-1][1] + ... + DP[K-1][N]
