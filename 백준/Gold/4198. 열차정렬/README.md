# [Gold I] 열차정렬 - 4198 

[문제 링크](https://www.acmicpc.net/problem/4198) 

### 성능 요약

메모리: 2044 KB, 시간: 4 ms

### 분류

다이나믹 프로그래밍, 가장 긴 증가하는 부분 수열: O(n log n)

### 아이디어

- 한 인덱스를 기준으로 LIS와 LDS의 최대 길이
- dp 활용
- dp, revDp에 각각 LIS와 LDS 저장후 ans = max(ans, dp[i]+revDp[i]-1) 저장
