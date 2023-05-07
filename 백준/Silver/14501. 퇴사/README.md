# [Silver III] 퇴사 - 14501 

[문제 링크](https://www.acmicpc.net/problem/14501) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

브루트포스 알고리즘, 다이나믹 프로그래밍

### 아이디어

- 마지막 날짜부터 역순으로, i번째 날짜에 대해 dp[i]=max(dp[i+1],dp[i+day[i]]+cost[i])
