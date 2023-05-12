# [Silver I] 포도주 시식 - 2156 

[문제 링크](https://www.acmicpc.net/problem/2156) 

### 성능 요약

메모리: 2100 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍

### 아이디어

- 연속으로 3잔 불가능 : i-2번째 + i번째 or i-3번째 + i-1번째 + i번째
	- max(dp[i - 3] + wine[i - 1], dp[i - 2]) + wine[i]
- i번째 포도주를 마시냐, 마냐
	- max(dp[i],dp[i-1])
