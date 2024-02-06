# [Gold III] Treasure Map - 15127 

[문제 링크](https://www.acmicpc.net/problem/15127) 

### 성능 요약

메모리: 5964 KB, 시간: 16 ms

### 분류

다이나믹 프로그래밍

### 아이디어

- 현재 머무르고 있는 정점으로부터 (dp[i][j]!=0) 이동 가능한 정점들에 대해
  - dp[i][j] : i번째 정점에 j번째날 방문했을 때까지 얻을 수 있는 최대 보물양
  - dp[nexti][nextj]=max(dp[nexti][nextj],dp[i][j]+nextTreasure)
- maxDay : 최대 채광 가능한 날 수
- 보물의 양은 0보다 작아질 수 없다는 점 주의 
