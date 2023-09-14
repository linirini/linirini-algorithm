# [Gold III] 파일 합치기 - 11066 

[문제 링크](https://www.acmicpc.net/problem/11066) 

### 성능 요약

메모리: 3004 KB, 시간: 144 ms

### 분류

다이나믹 프로그래밍

### 아이디어

- dp[i][j] = i~j 까지 구간의 파일을 합치는데 필요한 최소 비용
- sum[i] : 1~i번째 파일까지의 크기 합 : 누적합
- dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1])
  - ex) file = [40,30,30,50] -> dp[1][4] = dp[1][2]+dp[3][4] + sum[4]-sum[0] 일 때 최소
