# [Silver III] Four Squares - 17626 

[문제 링크](https://www.acmicpc.net/problem/17626) 

### 성능 요약

메모리: 2228 KB, 시간: 32 ms

### 분류

브루트포스 알고리즘, 다이나믹 프로그래밍

### 아이디어

- 최대값으로 초기화된 dp 일차원 배열에 대해, dp[i] = min(dp[i], dp[j*j] + dp[i-j*j])를 i의 제곱근까지 수행
