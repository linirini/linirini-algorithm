# [Gold IV] 가장 큰 정사각형 - 1915 

[문제 링크](https://www.acmicpc.net/problem/1915) 

### 성능 요약

메모리: 5940 KB, 시간: 8 ms

### 분류

다이나믹 프로그래밍

### 아이디어

- dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1))+1
- dp[i][j] = 해당 인덱스까지 확인했을 때 만들어지는 최대 정사각형 한변의 길이
- 자신을 기준으로 왼쪽, 왼쪽 대각선 위, 위쪽 값 중 최소값 + 1
