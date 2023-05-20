# [Gold V] 동전 1 - 2293 

[문제 링크](https://www.acmicpc.net/problem/2293) 

### 성능 요약

메모리: 2412 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍

### 아이디어

- dp[i] : i 가치를 만들는 경우의 수 : 모든 동전에 대해 dp[i] = dp[i] + dp[i-동전의 가치]
