# [Silver I] 쉬운 계단 수 - 10844 

[문제 링크](https://www.acmicpc.net/problem/10844) 

### 성능 요약

메모리: 2028 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍

### 아이디어

- 0,9(양끝) 제외 dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1])
