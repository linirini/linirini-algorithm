# [Silver I] RGB거리 - 1149 

[문제 링크](https://www.acmicpc.net/problem/1149) 

### 성능 요약

메모리: 2044 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍

### 아이디어

- dp[i][j] : i번째 집을 j색깔로 칠할 때의 최소 비용
	ex) dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + home[i][0]
